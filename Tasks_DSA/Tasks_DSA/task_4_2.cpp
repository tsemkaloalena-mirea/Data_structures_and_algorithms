#include <iostream>
#include <chrono>
using namespace std;

long long int compare = 0, swapping = 0;

void merge_sort(int* list, int n) {
	compare++;
	if (n == 0 || n == 1) return;
	int left_len = n / 2;
	int right_len = n - left_len;
	int* left = new int[left_len];
	int* right = new int[right_len];
	compare++;
	for (int i = 0; i < left_len; i++) {
		compare++;
		swapping++;
		left[i] = list[i];
	}
	compare++;
	for (int i = 0; i < right_len; i++) {
		compare++;
		swapping++;
		right[i] = list[n / 2 + i];
	}
	merge_sort(left, n / 2);
	merge_sort(right, n - n / 2);
	int x = 0, y = 0, k = 0;
	int* new_list = new int[n];
	compare++;
	while (x < left_len && y < right_len) {
		compare++;
		compare++;
		if (left[x] <= right[y]) {
			swapping++;
			new_list[k] = left[x];
			x++;
		}
		else {
			compare++;
			swapping++;
			new_list[k] = right[y];
			y++;
		}
		k++;
	}
	compare++;
	while (x < left_len) {
		compare++;
		swapping++;
		new_list[k] = left[x];
		x++;
		k++;
	}
	compare++;
	while (y < right_len) {
		swapping++;
		compare++;
		new_list[k] = right[y];
		y++;
		k++;
	}
	compare++;
	for (int i = 0; i < n; i++) {
		compare++;
		swapping++;
		list[i] = new_list[i];
	}
	delete new_list;
}

void print_list(int* list, int n) {
	for (int i = 0; i < n; i++) {
		cout << list[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
}

int main() {
	//int main_task_4_2() {
	setlocale(0, "");

	int n = 1000000;
	int* a = new int[n];

	//С клавиатуры
	//for (int i = 0; i < n; i++) {
	//    cin >> a[i];
	//}

	//Рандомно
	//for (int i = 0; i < n; i++) {
	//	a[i] = rand();
	//}

	//По убыванию
	for (int i = 0; i < n; i++) {
	    a[i] = n - i;
	}

	//По возрастанию
	//for (int i = 0; i < n; i++) {
	//    a[i] = i;
	//}

	//print_list(a, n);
	//cout << endl;

	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1> >;
	chrono::time_point<clock_t> start;
	start = clock_t::now();
	
	merge_sort(a, n);
	cout << "Number of comparisons: " << compare << endl;
	cout << "Number of swappings: " << swapping << endl;
	//cout << endl;
	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count();
	//cout << endl;
	//print_list(a, n);
	return 0;
}
