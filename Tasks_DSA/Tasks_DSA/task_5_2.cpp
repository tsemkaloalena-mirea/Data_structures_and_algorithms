#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

long long int prints = 0;

void divide() {
	ifstream a("a.bin", ios::binary);
	ofstream b("b.bin", ios::binary);
	ofstream c("c.bin", ios::binary);
	string line;
	int k = 0;
	bool new_line_b = false, new_line_c = false;
	while (getline(a, line, '\n')) {
		if (k % 2 == 0) {
			if (new_line_b) {
				b << '\n';
			}
			new_line_b = true;
			prints++;
			b << line;
		}
		else {
			if (new_line_c) {
				c << '\n';
			}
			new_line_c = true;
			prints++;
			c << line;
		}
		if (line.find("'") != -1) {
			k++;
		}
	}
	a.close();
	b.close();
	c.close();
}


int unite() {
	int s = 0;
	ofstream a;
	a.open("a.bin", ios::binary);
	ifstream b("b.bin", ios::binary);
	ifstream c("c.bin", ios::binary);
	string line_b, line_c;
	bool eof_b = false, eof_c = false;
	int mark_found_b, mark_found_c;
	bool new_line = false;

	while (!eof_b || !eof_c) {
		mark_found_b = false;
		mark_found_c = false;
		if (!getline(b, line_b, '\n')) {
			eof_b = true;
		}
		if (!getline(c, line_c, '\n')) {
			eof_c = true;
		}
		while (!(mark_found_b && mark_found_c)) {
			if (eof_b && eof_c) {
				break;
			}
			if (new_line) {
				a << '\n';
			}
			new_line = true;
			if (mark_found_b || eof_b) {
				if (line_c.find("'") != -1) {
					mark_found_c = true;
					line_c = line_c.substr(0, line_c.find("'"));
				}
				a << line_c;
				prints++;
				if (!mark_found_c) {
					if (!getline(c, line_c, '\n')) {
						eof_c = true;
					}
				}
			}
			else if (mark_found_c || eof_c) {
				if (line_b.find("'") != -1) {
					mark_found_b = true;
					line_b = line_b.substr(0, line_b.find("'"));
				}
				a << line_b;
				prints++;
				if (!mark_found_b) {
					if (!getline(b, line_b, '\n')) {
						eof_b = true;
					}
				}

			}
			else {
				if (line_b < line_c) {
					if (line_b.find("'") != -1) {
						mark_found_b = true;
						line_b = line_b.substr(0, line_b.find("'"));
					}
					a << line_b;
					prints++;
					if (!mark_found_b) {
						if (!getline(b, line_b, '\n')) {
							eof_b = true;
						}
					}
				}
				else {
					if (line_c.find("'") != -1) {
						mark_found_c = true;
						line_c = line_c.substr(0, line_c.find("'"));
					}
					a << line_c;
					prints++;
					if (!mark_found_c) {
						if (!getline(c, line_c, '\n')) {
							eof_c = true;
						}
					}

				}

			}
			if (mark_found_b) {
				eof_b = b.eof();
			}
			if (mark_found_c) {
				eof_c = c.eof();
			}
		}
		if (!(eof_b && eof_c)) {
			a << "'";
			s++;
		}
	}

	a.close();
	b.close();
	c.close();
	return s;
}

int series_divide() {
	int s = 0;
	ifstream a("a.bin", ios::binary);
	ofstream b;
	b.open("b.bin", ios::binary);
	string line_1, line_2;

	if (getline(a, line_1, '\n')) {
		b << line_1;
		while (getline(a, line_2, '\n')) {
			if (line_2 <= line_1) {
				b << "'";
				s++;
			}
			b << '\n';
			b << line_2;
			line_1 = line_2;
		}
	}

	a.close();
	b.close();

	ifstream bb("b.bin", ios::binary);
	ofstream aa("a.bin", ios::binary);

	while (getline(bb, line_1, '\n')) {
		aa << line_1;
		aa << '\n';
	}

	aa.close();
	bb.close();
	return s;
}

void natural_merge_sort() {
	int s;
	s = series_divide();
	while (s != 0) {
		divide();
		s = unite();
	}
}

void fill_in_file(int n) {
	ofstream a("a.bin", ios::binary);
	for (int i = 0; i < n; i++) {
		a << rand();
		a << '\n';
	}
	a.close();
}

int main() {
	//int main_task_5_2() {
	fill_in_file(1000000);
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1> >;
	chrono::time_point<clock_t> start;
	start = clock_t::now();

	natural_merge_sort();
	cout << "Number of prints: " << prints << endl;

	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count();
	return 0;
}
