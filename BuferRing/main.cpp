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

class LinkedList {
public:
	Node* head, * tail;

public:
	LinkedList(int maxSize) {
		int size = 0;
		head = tail = NULL;
		int maxSize = maxSize;
	}

	Node* push_front(double data) {
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != NULL)
			head->prev = ptr;
		if (tail == NULL)
			tail = ptr;
		head = ptr;
		return ptr;
	}
	void pop_back() {
		if (tail == NULL) return;

		Node* ptr = tail->prev;
		if (ptr != NULL)
			ptr->next = NULL;
		else
			head = NULL;

		delete tail;
		tail = ptr;
	}

	// Для тестирования
	Node* push_back(double data) {
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != NULL)
			tail->next = ptr;
		if (head == NULL)
			head = ptr;
		tail = ptr;
		return ptr;
	}
	// Для тестирования
	void pop_front() {
		if (head == NULL) return;

		Node* ptr = head->next;
		if (ptr != NULL)
			ptr->prev = NULL;
		else
			tail = NULL;

		delete head;
		head = ptr;
	}

};

int main() {
	LinkedList lst(5);
	lst.push_back(1.0);
	lst.push_back(2.0);
	lst.push_back(3.0);
	lst.push_back(4.0);
	lst.push_back(5.0);

	for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next) {
		std::cout << ptr->data << " ";
	}
	lst.pop_back();
	lst.pop_front();
	for (Node* ptr = lst.head; ptr != NULL; ptr = ptr->next) {
		std::cout << ptr->data << " ";
	}
}