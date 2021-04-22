#include <iostream>
using namespace std;

struct Node {
	char val;
	Node* ptr;
	Node(char value) : ptr(nullptr), val(value) {}
};

struct list {
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr && last == nullptr;
	}

	Node* add(char value, Node* current = NULL) {
		Node* p = new Node(value);
		if (is_empty()) {
			first = p;
			last = p;
			return p;
		}
		if (current == NULL) {
			p->ptr = first;
			first = p;
		}
		else {
			p->ptr = current->ptr;
			current->ptr = p;
		}
		return p;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			cout << p->val << " ";
			p = p->ptr;
		}
	}

	char longest_sequence() {
		if (!is_empty()) {
			char symb_1, symb_2, symb_max;
			int k = 0, k_max = 1;
			Node* p = first;
			symb_max = p->val;
			symb_1 = p->val;
			while (p) {
				symb_2 = p->val;
				if (symb_1 == symb_2) {
					k++;
				}
				else {
					symb_1 = symb_2;
					k = 1;
				}
				if (k > k_max) {
					symb_max = symb_1;
					k_max = k;
				}
				p = p->ptr;
			}
			return symb_max;
		}
	}
	Node* find_previous(Node* p) {
		if (p == first) {
			first = p->ptr;
			return p;
		}
		Node* previous_p = first;
		while (previous_p->ptr != p) {
			previous_p = previous_p->ptr;
		}
		return previous_p;
	}

	void remove_same_symbols() {
		if (is_empty()) return;
		char symb_1, symb_2;
		Node* p = first;
		symb_1 = ' ';
		while (p) {
			symb_2 = p->val;
			if (symb_1 == symb_2) {
				Node* previous_p = find_previous(p);
				previous_p->ptr = p->ptr;
				delete p;
				p = previous_p;
			}
			else symb_1 = symb_2;
			p = p->ptr;
		}
	}

	bool symbol_in_list(char symb) {
		Node* p = first;
		while (p) {
			if (symb == p->val) return true;
			p = p->ptr;
		}
		return false;
	}

	list make_sorted_list() {
		list new_list;
		if (is_empty()) return new_list;
		Node* p = first;
		while (p) {
			if (!new_list.symbol_in_list(p->val)) {
				if (new_list.is_empty()) new_list.add(p->val);
				else {
					Node* new_p = new_list.first;
					while (new_p->val < p->val && new_p != new_list.last) {
						new_p = new_p->ptr;
					}
					if (new_p->val > p->val) {
						if (new_p->ptr == new_list.first->ptr) new_list.add(p->val);
						else new_list.add(p->val, new_list.find_previous(new_p));
					}
					else new_list.add(p->val, new_p);					
				}
			}
			p = p->ptr;
		}
		return new_list;
	}
};

int main() {
	list L;
	cout << "The list is created" << endl;
	//if (L.is_empty()) {
	//	cout << "The list is empty" << endl;
	//}
	//else {
	//	cout << "The list is not empty" << endl;
	//}

	//Node* p = L.add('b');
	//L.add('c', p);
	L.add('a');
	L.add('k');
	L.add('l');
	L.add('c');
	L.add('c');
	L.add('c');
	L.add('h');
	L.add('a');
	L.add('a');
	L.add('a');
	L.add('a');
	L.add('c');
	L.add('c');
	L.add('x');	
	
	cout << "Some symbols are added to the list" << endl << "This is our list: ";
	L.print();
	cout << endl;
	//if (L.is_empty()) {
	//	cout << "The list is empty" << endl;
	//}
	//else {
	//	cout << "The list is not empty" << endl;
	//}
	//cout << "The symbol repeated more times in a row is: " << L.longest_sequence() << endl;
	
	//cout << "Let's remove repeated symbols." << endl << "Now our list is: ";
	//L.remove_same_symbols();
	//L.print();
	//cout << endl;

	cout << "New sorted list made of our old list without taking repeating symbols is: ";
	list new_L = L.make_sorted_list();
	new_L.print();
	cout << endl;

	return 0;
}
