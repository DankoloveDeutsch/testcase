#include <iostream>
class BufferRingArray {
public:
	int start;
	int end;
	int maxSize;
	int count;
	int* buffer;

public:
	BufferRingArray(int Size) {
		start = 0;
		end = 0;
		maxSize = Size;
		count = 0;
		buffer = new int[maxSize];
	}
	bool isFull() {
		return count == maxSize;
	}
	bool isEmpty() {
		return count == 0;
	}
	void push_back(int data) {
		if (isFull()) {
			std::cout << "Buffer is full" << std::endl;
		}
		else {
			buffer[end] = data;
			end = (end + 1) % maxSize;
			count++;
		}
	}
	int pop_front() {
		if (isEmpty()) {
			std::cout << "Buffer is empty" << std::endl;
		}
		else {
			int data = buffer[start];
			start = (start + 1) % maxSize;
			count--;
			return data;
		}
	}
	int size() {
		return count;
	}
	~BufferRingArray() {
		delete[] buffer;
	}
};

int main() {
	BufferRingArray buffer(5);


	buffer.push_back(10);
	buffer.push_back(20);
	buffer.push_back(30);
	buffer.push_back(40);
	buffer.push_back(50);
	std::cout << "Delete: " << buffer.pop_front() << std::endl;
	std::cout << "Delete: " << buffer.pop_front() << std::endl;

	buffer.push_back(60);
	buffer.push_back(70);

	while (!buffer.isEmpty()) {
		std::cout << "Delete: " << buffer.pop_front() << std::endl;
	}

	buffer.pop_front();
}
