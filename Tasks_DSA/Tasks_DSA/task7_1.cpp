#include <iostream>
using namespace std;

struct Node {
	string car_model;
	string country;
	int year;
	int price;
	string date_of_sale;
	Node* next;
	Node* previous;
	Node(string _car_model, string _country, int _year, int _price, string _date_of_sale = "") : next(nullptr), previous(nullptr), car_model(_car_model), country(_country), year(_year), price(_price), date_of_sale(_date_of_sale) {}
};

struct list {
	Node* first;
	Node* last;
	int list_size = 0;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr && last == nullptr;
	}

	Node* add(string _car_model, string _country, int _year, int _price, string _date_of_sale = "") {
		list_size++;
		Node* p = new Node(_car_model, _country, _year, _price, _date_of_sale);
		if (is_empty()) {
			first = p;
			last = p;
			return p;
		}

		last->next = p;
		p->previous = last;
		last = p;
		return p;
	}

	Node* add_by_country(string _car_model, string _country, int _year, int _price, string _date_of_sale = "") {
		list_size++;
		Node* p = new Node(_car_model, _country, _year, _price, _date_of_sale);
		if (is_empty()) {
			first = p;
			last = p;
			return p;
		}
		Node* old_p = find_first_coming_value("country", _country);
		if (old_p == NULL) {
			last->next = p;
			p->previous = last;
			last = p;
			return p;
		}
		old_p->previous->next = p;
		p->previous = old_p->previous;
		p->next = old_p;
		old_p->previous = p;
		return p;
	}

	void print(string direction) {
		if (is_empty()) return;
		if (direction == "left_to_right") {
			Node* p = first;
			while (p) {
				cout << p->car_model << " " << p->country << " " << p->year << " " << p->price;
				if (p->date_of_sale != "") {
					cout << " " << p->date_of_sale;
				}
				cout << endl;
				p = p->next;
			}
		}
		else if (direction == "right_to_left") {
			Node* p = last;
			while (p) {
				cout << p->car_model << " " << p->country << " " << p->year << " " << p->price;
				if (p->date_of_sale != "") {
					cout << " " << p->date_of_sale;
				}
				cout << endl;
				p = p->previous;
			}
		}
	}

	Node* find_first_coming_value(string type, string value) {
		Node* p = first;
		bool f = true;
		// поиск идёт с двух сторон сразу
		while (f) {
			if (type == "car_model" && p->car_model == value) {
				return p;
			}
			else if (type == "country" && p->country == value) {
				return p;
			}
			else if (type == "date_of_sale" && p->date_of_sale == value) {
				return p;
			}
			f = p != last;
			p = p->next;
		}
		return NULL;
	}

	Node* find_first_coming_value(string type, int value) {
		Node* p = first;
		bool f = true;
		// поиск идёт с двух сторон сразу
		while (f) {
			if (type == "year" && p->year == value) {
				return p;
			}
			else if (type == "price" && p->price == value) {
				return p;
			}
			f = p != last;
			p = p->next;
		}
	}

	void set_date_of_sale(Node* p, string date) {
		p->date_of_sale = date;
	}

	void delete_sold_automobiles() {
		Node* p = first;
		bool f = true;
		while (f) {
			if (p->date_of_sale != "") {
				if (p->previous != NULL) {
					p->previous->next = p->next;
				}
				if (p->next != NULL) {
					p->next->previous = p->previous;
				}
				//free(p);
			}
			f = p != last;
			p = p->next;
		}
	}
};

void sort_list_by_country(list* L, int n) {
	if (n == 0 || n == 1) {
		return;
	}
	int left_len = n / 2;
	int right_len = n - left_len;
	list left;
	list right;
	Node* p = (*L).first;
	for (int i = 0; i < left_len; i++) {
		left.add(p->car_model, p->country, p->year, p->price, p->date_of_sale);
		p = p->next;
	}
	for (int i = 0; i < right_len; i++) {
		right.add(p->car_model, p->country, p->year, p->price, p->date_of_sale);
		p = p->next;
	}
	sort_list_by_country(&left, n / 2);
	sort_list_by_country(&right, n - n / 2);
	int x = 0, y = 0, k = 0;
	Node* p_x = left.first, * p_y = right.first;
	list new_L;
	while (x < left_len && y < right_len) {
		if (p_x->country <= p_y->country) {
			new_L.add(p_x->car_model, p_x->country, p_x->year, p_x->price, p_x->date_of_sale);
			p_x = p_x->next;
			x++;
		}
		else {
			new_L.add(p_y->car_model, p_y->country, p_y->year, p_y->price, p_y->date_of_sale);
			p_y = p_y->next;
			y++;
		}
	}
	while (x < left_len) {
		new_L.add(p_x->car_model, p_x->country, p_x->year, p_x->price, p_x->date_of_sale);
		p_x = p_x->next;
		x++;
	}
	while (y < right_len) {
		new_L.add(p_y->car_model, p_y->country, p_y->year, p_y->price, p_y->date_of_sale);
		p_y = p_y->next;
		y++;
	}
	(*L) = new_L;
}

int main() {
	list L;
	cout << "The list is created" << endl;
	if (L.is_empty()) {
		cout << "The list is empty" << endl;
	}
	else {
		cout << "The list is not empty" << endl;
	}

	L.add("model1", "china", 1, 10);
	L.add("model2", "germany", 2, 20);
	L.add("model3", "italy", 3, 30);
	L.add("model4", "germany", 4, 40);
	L.add("model5", "italy", 5, 50);
	
	Node* p1 = L.find_first_coming_value("year", 4);
	Node* p2 = L.find_first_coming_value("country", "china");


	//cout << "Some symbols are added to the list" << endl << "This is our list: ";
	L.print("left_to_right");
	//L.print("right_to_left");

	cout << endl;
	if (L.is_empty()) {
		cout << "The list is empty" << endl;
	}
	else {
		cout << "The list is not empty" << endl;
	}

	sort_list_by_country(&L, L.list_size);
	L.print("left_to_right");

	L.add_by_country("model7", "germany", 7, 70);

	cout << endl;
	L.print("left_to_right");

	L.set_date_of_sale(L.find_first_coming_value("year", 3), "today");
	cout << endl;
	L.print("left_to_right");
	L.delete_sold_automobiles();
	cout << endl;
	L.print("left_to_right");
	//cout << "The symbol repeated more times in a row is: " << L.longest_sequence() << endl;

	//cout << "Let's remove repeated symbols." << endl << "Now our list is: ";
	//L.remove_same_symbols();
	//L.print();
	//cout << endl;

	//cout << "New sorted list made of our old list without taking repeating symbols is: ";
	//list new_L = L.make_sorted_list();
	//new_L.print();
	//cout << endl;

	return 0;
}