#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

void insertionsort(std::vector<int>& data, int low, int high) {
    for (int i = low + 1; i <= high; i++)
    {
        int value = data[i];
        int j = i;
        while (j > low && data[j - 1] > value)
        {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = value;
    }
}

int partition(std::vector<int>& data, int low, int high) {
    int pivot = data[high];
    int pIndex = low;
    for (int i = low; i < high; i++)
    {
        if (data[i] <= pivot)
        {
            std::swap(data[i], data[pIndex]);
            pIndex++;
        }
    }
    std::swap(data[pIndex], data[high]);
    return pIndex;
}

int randPartition(std::vector<int>& data, int low, int high) {
    int pivotIndex = rand() % (high - low + 1) + low;
    std::swap(data[pivotIndex], data[high]);
    return partition(data, low, high);
}

void heapsort(int* begin, int* end) {
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}

void introsort(std::vector<int>& data, int* begin, int* end, int maxdepth) {
    if ((end - begin) < 16) {
        insertionsort(data, begin - &data[0], end - &data[0] - 1);
    }
    else if (maxdepth == 0) {
        heapsort(begin, end);
    }
    else {
        int pivot = randPartition(data, begin - &data[0], end - &data[0] - 1);
        introsort(data, begin, &data[pivot], maxdepth - 1);
        introsort(data, &data[pivot + 1], end, maxdepth - 1);
    }
}
void sort(std::vector<int>& data) {
    int n = data.size();
    int maxdepth = log(n) * 2;

    auto start = std::chrono::high_resolution_clock::now();
    introsort(data, &data[0], &data[0] + n, maxdepth);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "\nExecution time: " << duration << " nanoseconds" << std::endl;

}
std::vector<int> generate_random_data(int size) {
    std::vector<int> data(size);
    std::generate(data.begin(), data.end(), std::rand);
    return data;
}
std::vector<int> generate_sorted_data(int size) {
    std::vector<int> data(size);
    std::iota(data.begin(), data.end(), 0);
    return data;
}

std::vector<int> generate_reverse_sorted_data(int size) {
    std::vector<int> data(size);
    std::iota(data.begin(), data.end(), 0);
    std::reverse(data.begin(), data.end());
    return data;
}
int main() {
    int n = 100;

    std::vector<int> random = generate_random_data(n);
    std::vector<int> sorted = generate_sorted_data(n);
    std::vector<int> reverse = generate_reverse_sorted_data(n);

    std::cout << "Random \t";
    sort(random);
    std::cout << std::endl;
    std::cout << "Sorted \t";
    sort(sorted);
    std::cout << std::endl;
    std::cout << "Reverse \t";
    sort(reverse);
};
