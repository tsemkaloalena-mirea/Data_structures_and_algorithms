#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
	Node* previous;
	Node(int _value) : next(nullptr), previous(nullptr), value(_value) {}
};

struct list {
	Node* first;
	Node* last;
	list() : first(nullptr), last(nullptr) {}

	bool list_is_empty() {
		return first == nullptr && last == nullptr;
	}

	Node* add(int _value) {
		Node* p = new Node(_value);
		if (list_is_empty()) {
			first = p;
			last = p;
			return p;
		}
		last->next = p;
		p->previous = last;
		last = p;
		return p;
	}

	void print(string direction = "left_to_right") {
		if (list_is_empty()) return;
		if (direction == "left_to_right") {
			Node* p = first;
			while (p) {
				cout << p->value << " ";
				p = p->next;
			}
		}
		else if (direction == "right_to_left") {
			Node* p = last;
			while (p) {
				cout << p->value << " ";
				p = p->previous;
			}
		}
	}

	void delete_list(Node* p) {
		if (list_is_empty()) return;
		first = p->next;
		if (p->next != NULL) {
			p->next->previous = p->previous;
		}
		else {
			last = p->previous;
			return;
		}
		delete_list(p->next);
	}
};

int main() {
	list L;
	for (int i = 0; i < 10; i++) {
		L.add(i);
	}
	cout << "original list: ";
	L.print();
	L.delete_list(L.first);
	cout << endl << "deleted list: ";
	L.print();
	return 0;
}