#include <iostream>
#include "task_7.h"
//#include "task_7_extra_functions.cpp"
using namespace std;

bool list_is_empty(list* L);
Node* find_first_coming_value(list* L, string type, string value);
Node* find_first_coming_value(list* L, string type, int value);
Node* add(list* L, string _car_model, string _country, int _year, int _price, string _date_of_sale = " ");
Node* add_by_country(list* L, string _car_model, string _country, int _year, int _price, string _date_of_sale = " ");
void print(list* L, string direction);
void set_date_of_sale(list* L, Node* p, string date);
void delete_sold_automobiles(list* L);
void sort_list_by_country(list* L, int n);

int main() {
	list L;
	cout << "The list is created" << endl;
	if (list_is_empty(&L)) {
		cout << "The list is empty" << endl;
	}
	else {
		cout << "The list is not empty" << endl;
	}

	add(&L, "model1", "china", 1, 10);
	add(&L, "model2", "germany", 2, 20);
	add(&L, "model3", "italy", 3, 30);
	add(&L, "model4", "germany", 4, 40);
	add(&L, "model5", "italy", 5, 50);

	Node* p1 = find_first_coming_value(&L, "year", 4);
	Node* p2 = find_first_coming_value(&L, "country", "china");


	//cout << "Some symbols are added to the list" << endl << "This is our list: ";
	print(&L, "left_to_right");
	//L.print("right_to_left");

	cout << endl;
	if (list_is_empty(&L)) {
		cout << "The list is empty" << endl;
	}
	else {
		cout << "The list is not empty" << endl;
	}

	sort_list_by_country(&L, L.list_size);
	print(&L, "left_to_right");

	add_by_country(&L, "model7", "germany", 7, 70);

	cout << endl;
	print(&L, "left_to_right");

	set_date_of_sale(&L, find_first_coming_value(&L, "year", 3), "today");
	cout << endl;
	print(&L, "left_to_right");
	delete_sold_automobiles(&L);
	cout << endl;
	print(&L, "left_to_right");
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