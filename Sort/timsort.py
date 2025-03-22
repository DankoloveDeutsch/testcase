import random
import time

def insertion_sort(arr, left=0, right=None):
    if right is None:
        right = len(arr) - 1
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def timsort(arr):
    start = time.time_ns()
    minrun = 32
    n = len(arr)
    
    for i in range(0, n, minrun):
        insertion_sort(arr, i, min(i + minrun - 1, n - 1))
    
    size = minrun
    while size < n:
        for start in range(0, n, size * 2):
            mid = start + size - 1
            end = min(start + size * 2 - 1, n - 1)
            if mid < end:
                merge(arr, start, mid, end)
        size *= 2


    end = time.time_ns()
    duration = end - start
    print(f"\nExecution time: {duration} nanoseconds")

    return arr

def merge(arr, start, mid, end):
    left = arr[start:mid + 1]
    right = arr[mid + 1:end + 1]
    i = j = 0
    k = start
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1
    
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
    
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1



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
    timsort(random_data)
    print("Sorted \t", end="")
    timsort(sorted_data)
    print("Reverse \t", end="")
    timsort(reverse_data)


if __name__ == "__main__":
    main()
