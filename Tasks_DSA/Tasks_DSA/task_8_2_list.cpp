////#ifndef __Task7_H
////#define __Task7_H
//#include <iostream>
//using namespace std;
//
//struct Node {
//	char val;
//	Node* previous;
//	Node(char value) : previous(nullptr), val(value) {}
//};
//
//struct listStack {
//	Node* last;
//	listStack() : last(nullptr) {}
//
//	bool is_empty() {
//		return last == nullptr;
//	}
//
//	void push_back(char value) {
//		Node* p = new Node(value);
//		if (is_empty()) {
//			last = p;
//			return;
//		}
//		p->previous = last;
//		last = p;
//	}
//
//	void pop() {
//		if (is_empty()) return;
//		Node* p = last->previous;
//		delete last;
//		last = p;
//	}
//
//	char top() {
//		return last->val;
//	}
//	
//	void clear() {
//		while (!is_empty()) {
//			pop();
//		}
//		last = nullptr;
//	}
//};
//
////#endif