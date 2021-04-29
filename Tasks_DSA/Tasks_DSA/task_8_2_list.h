#ifndef __Task8_list_H
#define __Task8_list_H
#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T val;
	Node* previous;
	Node(char value) : previous(nullptr), val(value) {}
};

template <typename T>
struct listStack {
	Node<T>* last;
	listStack() : last(nullptr) {}

	bool empty() {
		return last == nullptr;
	}

	void push(char value) {
		Node<T>* p = new Node<T>(value);
		if (empty()) {
			last = p;
			return;
		}
		p->previous = last;
		last = p;
	}

	void pop() {
		if (empty()) return;
		Node<T>* p = last->previous;
		delete last;
		last = p;
	}

	char top() {
		return last->val;
	}
	
	void clear() {
		while (!empty()) {
			pop();
		}
		last = nullptr;
	}
};

#endif