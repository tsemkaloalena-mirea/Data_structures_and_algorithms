#include <iostream>
#include <chrono>
using namespace std;

void bubble_sort(int* list, int n) {
    long long int compare = 2, swapping = 0;
    for (int i = 0; i < n; i++) {
        compare++;
        for (int j = n - 1; j > i; j--) {
            compare++;
            compare++;
            if (list[j - 1] > list[j]) {
                swapping++;
                int t = list[j];
                list[j] = list[j - 1];
                list[j - 1] = t;
            }
        }
    }
    cout << "Кол-во сравнений: " << compare << endl;
    cout << "Кол-во перемещений: " << swapping << endl;
}

void print_list(int *list, int n) {
    for (int i = 0; i < n; i++) {
        cout << list[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
}

//int main() {
int main_task_3_1() {
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

    //print_list(a, n);
    //cout << endl;

    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, std::ratio<1> >;
    chrono::time_point<clock_t> start;
    start = clock_t::now();

    bubble_sort(a, n);

    cout << endl;
    cout << chrono::duration_cast<second_t>(clock_t::now() - start).count();
    //print_list(a, n);

	return 0;
}
