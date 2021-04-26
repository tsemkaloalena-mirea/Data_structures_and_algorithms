#include <iostream>
#include "task_7.h"
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
	cout << endl;

	add(&L, "model1", "china", 1991, 10);
	add(&L, "model2", "germany", 1983, 20);
	add(&L, "model3", "italy", 2001, 30);
	add(&L, "model4", "germany", 1998, 40);
	add(&L, "model5", "italy", 1995, 50);
	//add(&L, "m1", "china", 1991, 10);
	//add(&L, "m2", "germany", 1983, 20);
	//add(&L, "m3", "italy", 2001, 30);
	//add(&L, "m4", "germany", 1998, 40);
	//add(&L, "m5", "italy", 1995, 50);
	//add(&L, "m1", "New Zeland", 1991, 10);
	//add(&L, "m2", "Switzerland", 1983, 20);
	//add(&L, "m3", "Japan", 2001, 30);
	//add(&L, "m4", "Germany", 1998, 40);
	//add(&L, "m5", "Italy", 1995, 50);

	//Node* p1 = find_first_coming_value(&L, "year", 1998);
	//Node* p2 = find_first_coming_value(&L, "country", "china");

	cout << "Some symbols are added to the list." << endl << "This is our list left to right:" << endl;
	print(&L, "left_to_right");
	cout << endl;
	//cout << "This is our list right to left:" << endl;
	//print(&L, "right_to_left");
	//cout << endl;

	if (list_is_empty(&L)) {
		cout << "The list is empty" << endl;
	}
	else {
		cout << "The list is not empty" << endl;
	}
	cout << endl;

	cout << "This is our list sorted by country: " << endl;
	sort_list_by_country(&L, L.list_size);
	print(&L, "left_to_right");
	cout << endl;

	//cout << "New car is added to the list. This is our list left to right:" << endl;
	//add_by_country(&L, "model7", "germany", 2021, 70);
	//print(&L, "left_to_right");

	cout << endl;
	cout << "Some cars are sold: " << endl;
	set_date_of_sale(&L, find_first_coming_value(&L, "year", 1983), "today");
	set_date_of_sale(&L, find_first_coming_value(&L, "price", 50), "21.04.2021");
	print(&L, "left_to_right");

	cout << endl;
	cout << "Let's delete sold cars from our list:" << endl;
	delete_sold_automobiles(&L);
	print(&L, "left_to_right");

	return 0;
}