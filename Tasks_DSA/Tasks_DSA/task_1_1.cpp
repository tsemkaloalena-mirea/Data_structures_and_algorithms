#include <iostream>
using namespace std;

void delFirstMethod(int& n, int key, int* x) {
	int i = 0;
	int k_moving = 0, k_comparing = 0;
	// Перед началом цикла i < n, так как i = 0, а n - длина массива
	while (i < n) {
		k_comparing++;
		if (x[i] == key) {
			for (int j = i; j < n - 1; j++) {
				x[j] = x[j + 1];
				k_moving++;
			}
			n--;
		}
		else {
			i++;
		}
		fgdm
		// Если элемент удалён из массива, то элементы от i до n-1 становятся равны элементам от i+1 до n, то есть "соседу справа",
		// а n уменьшается на 1, таким образом последний лишний элемент отсекается.

		// Если же элемент не удалён, то i увеличивается на 1, чтобы перейти к анализу следующего элемента.
	}
	// Цикл завершается, когда i = n-1, то есть цикл проверил все элементы массива от 0 до n-1, ненужные - удалены.

	cout << "Number of movements: " << k_moving << endl;
	cout << "Number of comparisons: " << k_comparing << endl;
}

void delOtherMethod(int& n, int key, int* x) {
	int k_moving = 0, k_comparing = 0;
	int j = 0;
	// Перед началом цикла i < n, так как i = 0, а n - длина массива
	for (int i = 0; i < n; i++) {
		if (i != j) {
			k_moving++;
		}
		x[j] = x[i];

		k_comparing++;
		if (x[i] != key) {
			j++;
		}
		// Если элемент не должен быть удалён, то j не увеличивается, чтобы при следующей итерации поверх этого элемента не был записан другой.
		// При этом увеличивается и длина будущего массива x, тк потом n будет равно j.
		// Если же элемент должен быть удалён, то значение j увеличено не будет, то есть при следующей итерации на место этого элемента будет записан следующий, который удалять не нужно.
	}
	// Цикл завершается, когда i = n-1, то есть цикл проверил все элементы массива от 0 до n-1.
	n = j;
	cout << "Number of movements: " << k_moving << endl;
	cout << "Number of comparisons: " << k_comparing << endl;
}

int main_task_1() {
	int key = 9;
	int n = 10;
	int* x = new int[n];
	//int* x = new int[n] { 1, 2, 3, 2, 5, 2, 2, 5, 7, 2 };
	//int* x = new int[n] { 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2, 1, 2, 3, 2, 5, 2, 2, 5, 7, 2 };
	//int* x = new int[n] { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
	cout << "Old array: ";
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100;
		cout << x[i] << " ";
	}
	cout << endl;

	//delFirstMethod(*&n, key, x);
	delOtherMethod(*&n, key, x);
	cout << "New array (" << key << " was deleted): ";
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
	return 0;
}
