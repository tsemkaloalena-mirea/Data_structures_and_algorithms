#ifndef __Task7_H
#define __Task7_H
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

	//bool is_empty();
	//Node* add(string _car_model, string _country, int _year, int _price, string _date_of_sale = "");
	//Node* add_by_country(string _car_model, string _country, int _year, int _price, string _date_of_sale = "");
	//void print(string direction);
	//Node* find_first_coming_value(string type, string value);
	//Node* find_first_coming_value(string type, int value);
	//void set_date_of_sale(Node* p, string date);
	//void delete_sold_automobiles();
};

#endif