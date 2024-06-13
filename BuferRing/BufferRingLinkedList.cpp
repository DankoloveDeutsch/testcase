#include <iostream>

class Node {
public:
	double data;
	Node* prev, * next;
public:
	Node(double data) {
		this->data = data;
		this->prev = this->prev = NULL;
	}
};

class BufferRingLinkedList {
public:
	Node* head, * tail;
	int size;
	int maxSize;
public:
	BufferRingLinkedList(int newSize) {
		head = tail = NULL;
		size = 0;
		maxSize = newSize;

	}

	void push_back(double data) {
		if (size == maxSize) {
			std::cout << "Buffer is full" << std::endl;
			return;
		}
		else {
			Node* ptr = new Node(data);
			ptr->prev = tail;
			if (tail != NULL)
				tail->next = ptr;
			if (head == NULL)
				head = ptr;
			tail = ptr;
			size++;
		}
	}
	void pop_front() {
		if (head == nullptr) {
			std::cout << "Buffer is empty" << std::endl;
			return;
		}
		if (head == NULL) return;

		Node* ptr = head->next;
		if (ptr != NULL)
			ptr->prev = NULL;
		else
			tail = NULL;

		delete head;
		head = ptr;
		size--;
	}
	bool isEmpty() {
		return tail == NULL;
	}
	int getSize() const {
		return size;
	}
	~BufferRingLinkedList() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
int main() {
	BufferRingLinkedList buffer(5);

	buffer.push_back(1.1);
	buffer.push_back(2.2);
	buffer.push_back(3.3);
	buffer.push_back(3.3);
	buffer.push_back(3.3);
	buffer.push_back(3.3);
	buffer.push_back(3.3);
	buffer.push_back(3.3);

	std::cout << "Current size: " << buffer.getSize() << std::endl;

	buffer.pop_front();
	buffer.pop_front();
	buffer.pop_front();
	buffer.pop_front();
	buffer.pop_front();
	buffer.pop_front();

	std::cout << "Current size: " << buffer.getSize() << std::endl;

	buffer.push_back(4.4);
	buffer.push_back(5.5);

	std::cout << "Current size: " << buffer.getSize() << std::endl;

	while (!buffer.isEmpty()) {
		buffer.pop_front();
	}

	std::cout << "Current size: " << buffer.getSize() << std::endl;
}
