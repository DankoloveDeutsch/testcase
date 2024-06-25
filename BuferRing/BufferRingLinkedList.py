class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class BufferRingLinkedList:
    def __init__(self, max_size):
        self.head = None
        self.tail = None
        self.size = 0
        self.max_size = max_size

    def push_back(self, data):
        if self.size == self.max_size:
            print("Buffer is full")
            return
        
        new_node = Node(data)
        if self.tail:
            self.tail.next = new_node
            new_node.prev = self.tail
        self.tail = new_node
        if not self.head:
            self.head = new_node
        self.size += 1

    def pop_front(self):
        if not self.head:
            print("Buffer is empty")
            return
        
        if self.head:
            temp = self.head
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            else:
                self.tail = None
            del temp
            self.size -= 1

    def is_empty(self):
        return self.head is None

    def get_size(self):
        return self.size

    def __del__(self):
        while self.head:
            temp = self.head
            self.head = self.head.next
            del temp

def main():
    buffer = BufferRingLinkedList(5)

    buffer.push_back(1.1)
    buffer.push_back(2.2)
    buffer.push_back(3.3)
    buffer.push_back(3.3)
    buffer.push_back(3.3)
    buffer.push_back(3.3)
    buffer.push_back(3.3)
    buffer.push_back(3.3)

    print("Current size:", buffer.get_size())

    buffer.pop_front()
    buffer.pop_front()
    buffer.pop_front()
    buffer.pop_front()
    buffer.pop_front()
    buffer.pop_front()

    print("Current size:", buffer.get_size())

    buffer.push_back(4.4)
    buffer.push_back(5.5)

    print("Current size:", buffer.get_size())

    while not buffer.is_empty():
        buffer.pop_front()

    print("Current size:", buffer.get_size())

if __name__ == "__main__":
    main()
