#include <iostream>
using namespace std;

long long it_count(int a[55]) {
	int i = 0, j = 0;
	long long result = 1, s;
	while (i < 55) {
		s = 0;
		j++;
		for (int k = 0; k < j; k++) {
			s += a[i++];
		}
		result *= s;
	}
	return result;
}

long long count(int i, int j, int a[55]) {
	long long s = 0;
	for (int k = 0; k < j; k++) s += a[i++];
	if (j < 10) return s * count(i, j+1, a);
	else if (j == 10) return s;
	else return 1;
}

int main() {
	int a[55];
	for (int i = 0; i < 55; i++) {
		a[i] = i + 1;
	}
	cout << "Result for recursive algorithm: " << count(0, 1, a) << endl;
	cout << "Result for iterative algorithm: " << it_count(a);
	return 0;
}