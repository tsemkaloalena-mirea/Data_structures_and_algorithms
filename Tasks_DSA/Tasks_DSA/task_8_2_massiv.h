#ifndef __Task8_massiv_H
#define __Task8_massiv_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
template <typename T>
struct massivStack {
	int size = 0;
	T* x = new T[size];

	bool empty() {
		return size == 0;
	}

	void push(char value) {
		x[size++] = value;
	}

	void pop() {
		if (empty()) return;
		size--;
	}

	char top() {
		return x[size - 1];
	}

	void clear() {
		delete[]x;
		size = 0;
		x = new char[size];
	}
};
#endif