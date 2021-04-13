#include <iostream>
#include <chrono>
using namespace std;

void cocktail_sort(int* list, int n) {
	long long int compare = 3, swapping = 0;
	int left = 0;
	int right = n - 1;
	int k;
	while (left < right) {
		compare++;
		k = 0;
		for (int i = left; i < right; i++) {
			compare++;
			compare++;
			if (list[i] > list[i + 1]) {
				swapping++;
				int t = list[i + 1];
				list[i + 1] = list[i];
				list[i] = t;
				k = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			compare++;
			compare++;
			if (list[i] < list[i - 1]) {
				swapping++;
				int t = list[i - 1];
				list[i - 1] = list[i];
				list[i] = t;
				k = 1;
			}
		}
		left++;
		compare++;
		if (k == 0) {
			break;
		}
	}
	cout << "Number of comparisons: " << compare << endl;
	cout << "Number of swappings: " << swapping << endl;

}

void bubble_sort(int* list, int n) {
	long long int compare = 2, swapping = 0;
	int k;
	for (int i = 0; i < n; i++) {
		compare++;
		k = 0;
		for (int j = n - 1; j > i; j--) {
			compare++;
			compare++;
			if (list[j - 1] > list[j]) {
				swapping++;
				int t = list[j];
				list[j] = list[j - 1];
				list[j - 1] = t;
				k = 1;
			}
		}
		compare++;
		if (k == 0) {
			break;
		}
	}
	cout << "Number of comparisons: " << compare << endl;
	cout << "Number of swappings: " << swapping << endl;
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
//int main_task_4_1() {
	setlocale(0, "");

	int n = 1000000;
	int *a = new int[n];
	

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

	//bubble_sort(a, n);
	cocktail_sort(a, n);

	//cout << endl;
	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count();
	//cout << endl;
	//print_list(a, n);

	return 0;
}
