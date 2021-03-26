#include <iostream>
#include <malloc.h>

using namespace std;

void fill_in(int* list) {
	for (int i = 0; i < _msize(list) / sizeof(int); i++) {
		cin >> list[i];
	}
}

void print_massiv(int* list) {
	for (int i = 0; i < _msize(list) / sizeof(int); i++) { //!!!!!
		cout << list[i];
		if (i < _msize(list) / sizeof(int) - 1) { //!!!!!!!
			cout << " ";
		}
	}
}

void random_fill_in(int* list, int n) {
	for (int i = 0; i < n; i++) {
		list[i] = rand();
	}
}

int find_first_comer(int* list, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (list[i] == x) {
			return i;
		}
	}
	return -1;
}

int find_first_negative(int* list, int n) {
	for (int i = 0; i < n; i++) {
		if (list[i] < 0) {
			return i;
		}
	}
	return -1;
}

int find_all_comers(int* list, int n, int x) {
	bool f = false;
	for (int i = 0; i < n; i++) {
		if (list[i] == x) {
			if (f != false) {
				cout << " ";

			}
			f = true;
			cout << i;
		}
	}
	if (f == false) {
		return -1;
	}
	else {
		return 0;
	}
}

void insert_x(int** list, int i, int x) {
	*list = (int*)realloc(*list, (_msize(*list) / sizeof(int) + 1) * sizeof(int));
	for (int j = _msize(*list) / sizeof(int) - 2; j >= i; j--) {
		(*list)[j + 1] = (*list)[j];
	}
	
	(*list)[i] = x;
}

void delete_index(int** list, int index) {
	for (int i = index + 1; i < _msize(*list) / sizeof(int); i++) {
		(*list)[i - 1] = (*list)[i];
	}
	*list = (int*)realloc(*list, (_msize(*list) / sizeof(int) - 1) * sizeof(int));
}

void delete_all_comers_n2(int** list, int x) {
	int i = 0;
	while (i < _msize(*list) / sizeof(int)) {
		if ((*list)[i] == x) {
			for (int j = i; j < _msize(*list) / sizeof(int) - 1; j++) {
				(*list)[j] = (*list)[j + 1];
			}
			*list = (int*)realloc(*list, (_msize(*list) / sizeof(int) - 1) * sizeof(int));
		}
		else {
			i++;
		}
	}
}

void delete_all_comers_n(int** list, int x) {
	int j = 0;
	for (int i = 0; i < _msize(*list) / sizeof(int); i++) {
		(*list)[j] = (*list)[i];
		if ((*list)[i] != x) {
			j++;
		}
	}
	*list = (int*)realloc(*list, j * sizeof(int));
}

int main_task_2_2() {
//int main() {
	setlocale(0, "");
	
	int n;
	cin >> n;
	if (n < 1 || n > 1000) {
		cout << "Недопустимый размер массива";
		return 1;
	}

	int* massiv;
	massiv = (int*)malloc(n * sizeof(int));
	
	fill_in(massiv);

	//print_massiv(massiv, n);
	//cout << endl;
	//random_fill_in(massiv, n);
	//print_massiv(massiv, n);

	//cout << endl;
	//int index = find_first_comer(massiv, n, 3);
	//if (index == -1) {
	//	cout << "Такого значения в массиве нет";
	//	return 1;
	//}
	//else {
	//	cout << index;
	//}

	//cout << endl;
	//int negative_number_index = find_first_negative(massiv, n);
	//if (negative_number_index == -1) {
	//	cout << "Отрицательного числа в массиве нет";
	//	return 1;
	//}
	//else {
	//	cout << negative_number_index;
	//}

	cout << endl;
	int indexes = find_all_comers(massiv, n, 3);
	if (indexes == -1) {
		cout << "Такого значения в массиве нет";
		return 1;
	}

	//int x;
	//int index;
	//cin >> index >> x;
	//if (index >= 0 && index < _msize(massiv) / sizeof(int)) {
	//	insert_x(&massiv, index, x);
	//}
	//else {
	//	cout << "Недопустимый индекс";
	//	return 1;
	//}
	
	//print_massiv(massiv);
	

	//cout << endl;

	//int deleted_index;
	//cin >> deleted_index;
	//if (deleted_index >= 0 && deleted_index < _msize(massiv) / sizeof(int)) {
	//	delete_index(&massiv, deleted_index);
	//}
	//else {
	//	cout << "Недопустимый индекс";
	//	return 1;
	//}

	//int deleted_x_n2;
	//cin >> deleted_x_n2;
	//delete_all_comers_n2(&massiv, deleted_x_n2);

	//int deleted_x_n;
	//cin >> deleted_x_n;
	//delete_all_comers_n(&massiv, deleted_x_n);

	cout << endl;
	print_massiv(massiv);

	return 0;
}
