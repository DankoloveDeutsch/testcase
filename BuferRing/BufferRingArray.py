class BufferRingArray:
    def __init__(self, size):
        self.start = 0
        self.end = 0
        self.max_size = size
        self.count = 0
        self.buffer = [0] * self.max_size

    def is_full(self):
        return self.count == self.max_size

    def is_empty(self):
        return self.count == 0

    def push_back(self, data):
        if self.is_full():
            print("Buffer is full")
        else:
            self.buffer[self.end] = data
            self.end = (self.end + 1) % self.max_size
            self.count += 1

    def pop_front(self):
        if self.is_empty():
            print("Buffer is empty")
        else:
            data = self.buffer[self.start]
            self.start = (self.start + 1) % self.max_size
            self.count -= 1
            return data

    def size(self):
        return self.count

def main():
    buffer = BufferRingArray(5)

    buffer.push_back(10)
    buffer.push_back(20)
    buffer.push_back(30)
    buffer.push_back(40)
    buffer.push_back(50)
    
    print("Delete:", buffer.pop_front())
    print("Delete:", buffer.pop_front())

    buffer.push_back(60)
    buffer.push_back(70)

    while not buffer.is_empty():
        print("Delete:", buffer.pop_front())

    buffer.pop_front()

if __name__ == "__main__":
    main()
