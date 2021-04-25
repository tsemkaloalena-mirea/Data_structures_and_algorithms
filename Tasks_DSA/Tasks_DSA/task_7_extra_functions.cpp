#include <iostream>
#include "task_7.h"
using namespace std;

bool list_is_empty(list* L) {
	return L->first == nullptr && L->last == nullptr;
}

Node* find_first_coming_value(list* L, string type, string value) {
	Node* p = L->first;
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
		f = p != L->last;
		p = p->next;
	}
	return NULL;
}

Node* find_first_coming_value(list* L, string type, int value) {
	Node* p = L->first;
	bool f = true;
	// поиск идёт с двух сторон сразу
	while (f) {
		if (type == "year" && p->year == value) {
			return p;
		}
		else if (type == "price" && p->price == value) {
			return p;
		}
		f = p != L->last;
		p = p->next;
	}
}

Node* add(list* L, string _car_model, string _country, int _year, int _price, string _date_of_sale) {
	L->list_size++;
	Node* p = new Node(_car_model, _country, _year, _price, _date_of_sale);
	if (list_is_empty(L)) {
		L->first = p;
		L->last = p;
		return p;
	}

	L->last->next = p;
	p->previous = L->last;
	L->last = p;
	return p;
}

Node* add_by_country(list* L, string _car_model, string _country, int _year, int _price, string _date_of_sale) {
	L->list_size++;
	Node* p = new Node(_car_model, _country, _year, _price, _date_of_sale);
	if (list_is_empty(L)) {
		L->first = p;
		L->last = p;
		return p;
	}
	Node* old_p = find_first_coming_value(L, "country", _country);
	if (old_p == NULL) {
		L->last->next = p;
		p->previous = L->last;
		L->last = p;
		return p;
	}
	old_p->previous->next = p;
	p->previous = old_p->previous;
	p->next = old_p;
	old_p->previous = p;
	return p;
}

void print(list* L, string direction) {
	if (list_is_empty(L)) return;
	if (direction == "left_to_right") {
		Node* p = L->first;
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
		Node* p = L->last;
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

void set_date_of_sale(list* L, Node* p, string date) {
	p->date_of_sale = date;
}

void delete_sold_automobiles(list* L) {
	Node* p = L->first;
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
		f = p != L->last;
		p = p->next;
	}
}

void sort_list_by_country(list* L, int n) {
	if (n == 0 || n == 1) {
		return;
	}
	int left_len = n / 2;
	int right_len = n - left_len;
	list left;
	list right;
	Node* p = L->first;
	for (int i = 0; i < left_len; i++) {
		add(&left, p->car_model, p->country, p->year, p->price, p->date_of_sale);
		p = p->next;
	}
	for (int i = 0; i < right_len; i++) {
		add(&right, p->car_model, p->country, p->year, p->price, p->date_of_sale);
		p = p->next;
	}
	sort_list_by_country(&left, n / 2);
	sort_list_by_country(&right, n - n / 2);
	int x = 0, y = 0, k = 0;
	Node* p_x = left.first, * p_y = right.first;
	list new_L;
	while (x < left_len && y < right_len) {
		if (p_x->country <= p_y->country) {
			add(&new_L, p_x->car_model, p_x->country, p_x->year, p_x->price, p_x->date_of_sale);
			p_x = p_x->next;
			x++;
		}
		else {
			add(&new_L, p_y->car_model, p_y->country, p_y->year, p_y->price, p_y->date_of_sale);
			p_y = p_y->next;
			y++;
		}
	}
	while (x < left_len) {
		add(&new_L, p_x->car_model, p_x->country, p_x->year, p_x->price, p_x->date_of_sale);
		p_x = p_x->next;
		x++;
	}
	while (y < right_len) {
		add(&new_L, p_y->car_model, p_y->country, p_y->year, p_y->price, p_y->date_of_sale);
		p_y = p_y->next;
		y++;
	}
	(*L) = new_L;
}
