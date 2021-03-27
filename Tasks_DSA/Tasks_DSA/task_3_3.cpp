#include <iostream>
#include <chrono>
using namespace std;


void insertion_sort(int* list, int n) {
	long long int compare = 2, swapping = 0;
	for (int i = 1; i < n; i++) {
		compare++;
		for (int j = i; j > 0; j--) {
			compare++;
			compare++;
			if (list[j - 1] > list[j]) {
				swapping++;
				//swap(list[j], list[j - 1]);
				int t = list[j - 1];
				list[j - 1] = list[j];
				list[j] = t;
			}
		}
	}
	cout << "Кол-во сравнений: " << compare << endl;
	cout << "Кол-во перемещений: " << swapping << endl;
	cout << compare + swapping << endl;
}

//int main() {
int main_task_3_3() {
	setlocale(0, "");
	const int n = 100000;
	int a[n];

	//С клавиатуры
	//for (int i = 0; i < n; i++) {
	//    cin >> a[i];
	//}

	//Рандомно
	//for (int i = 0; i < n; i++) {
	//    a[i] = rand();
	//}

	//По убыванию
	for (int i = 0; i < n; i++) {
		a[i] = n - i;
	}

	//По возрастанию
	//for (int i = 0; i < n; i++) {
	//    a[i] = i;
	//}

	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1> >;
	chrono::time_point<clock_t> start;
	start = clock_t::now();

	insertion_sort(a, n);

	cout << endl;
	cout << "Время выполнения программы: " << chrono::duration_cast<second_t>(clock_t::now() - start).count();

	return 0;
}