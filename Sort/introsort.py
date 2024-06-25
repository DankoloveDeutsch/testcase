import random
import heapq
import math
import time

def insertionsort(data, low, high):
    for i in range(low + 1, high + 1):
        value = data[i]
        j = i
        while j > low and data[j - 1] > value:
            data[j] = data[j - 1]
            j -= 1
        data[j] = value

def partition(data, low, high):
    pivot = data[high]
    pIndex = low
    for i in range(low, high):
        if data[i] <= pivot:
            data[i], data[pIndex] = data[pIndex], data[i]
            pIndex += 1
    data[pIndex], data[high] = data[high], data[pIndex]
    return pIndex

def rand_partition(data, low, high):
    pivot_index = random.randint(low, high)
    data[pivot_index], data[high] = data[high], data[pivot_index]
    return partition(data, low, high)

def heapsort(data):
    heapq.heapify(data)
    sorted_data = [heapq.heappop(data) for _ in range(len(data))]
    data.extend(sorted_data)

def introsort(data, begin, end, maxdepth):
    size = end - begin
    if size < 16:
        insertionsort(data, begin, end)
    elif maxdepth == 0:
        heapsort(data[begin:end+1])
    else:
        pivot = rand_partition(data, begin, end)
        introsort(data, begin, pivot - 1, maxdepth - 1)
        introsort(data, pivot + 1, end, maxdepth - 1)

def sort(data):
    n = len(data)
    maxdepth = math.floor(math.log2(n)) * 2

    start = time.time_ns()
    introsort(data, 0, n - 1, maxdepth)
    end = time.time_ns()
    duration = end - start
    print(f"\nExecution time: {duration} nanoseconds")

def generate_random_data(size):
    return [random.randint(0, 10000) for _ in range(size)]

def generate_sorted_data(size):
    return list(range(size))

def generate_reverse_sorted_data(size):
    return list(range(size, 0, -1))

def main():
    n = 1000

    random_data = generate_random_data(n)
    sorted_data = generate_sorted_data(n)
    reverse_data = generate_reverse_sorted_data(n)

    print("Random \t", end="")
    sort(random_data)
    print("Sorted \t", end="")
    sort(sorted_data)
    print("Reverse \t", end="")
    sort(reverse_data)


if __name__ == "__main__":
    main()
