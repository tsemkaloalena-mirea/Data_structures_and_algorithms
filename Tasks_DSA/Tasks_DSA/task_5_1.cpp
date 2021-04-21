#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

long long int prints = 0;
void divide(int portion) {
	ifstream a("a.bin", ios::binary);
	ofstream b;
	ofstream c;
	b.open("b.bin", ios::binary);
	c.open("c.bin", ios::binary);
	string line;
	int n = 0;
	
	while (getline(a, line, '\n')) {
		
		if (n < portion) {
			prints++;
			b << line;
			b << '\n';
		}
		else {
			prints++;
			c << line;
			c << '\n';
		}
		n++;
		n %= (portion * 2);
	}
	a.close();
	b.close();
	c.close();
}

void unite(int portion, int n) {
	ofstream a;
	a.open("a.bin", ios::binary);
	ifstream b("b.bin", ios::binary);
	ifstream c("c.bin", ios::binary);
	string line_b, line_c;
	bool eof_b = false;
	bool eof_c = false;
	int enters = 0;
	int portion_b = portion;
	int portion_c = portion;
	
	while (!eof_b || !eof_c) {
		
		portion_b = portion - 1;
		portion_c = portion - 1;
		
		if (!getline(b, line_b, '\n')) {
			eof_b = true;
		}
		
		if (!getline(c, line_c, '\n')) {
			eof_c = true;
		}
		
		while (portion_b >= 0 || portion_c >= 0) {
			
			
			if (eof_b && eof_c) {
				break;
			}
			
			if (portion_b < 0) {
				a << line_c;
				prints++;
				
				if (enters < n) {
					enters++;
					a << '\n';
				}
				
				if (portion_c > 0) {
					
					if (!getline(c, line_c, '\n')) {
						portion_c = 0;
						eof_c = true;
					}
				}
				portion_c--;
			}
			else if (portion_c < 0) {
				
				a << line_b;
				prints++;
				if (enters < n) {
					enters++;
					a << '\n';
				}
				
				if (portion_b > 0) {
					if (!getline(b, line_b, '\n')) {
						portion_b = 0;
						eof_b = true;
					}
				}
				portion_b--;
			}
			else {
				
				if (line_b < line_c) {
					
					a << line_b;
					prints++;
					if (enters < n) {
						enters++;
						a << '\n';
					}
					
					if (portion_b > 0) {
						
						if (!getline(b, line_b, '\n')) {
							portion_b = 0;
							eof_b = true;
						}
					}
					portion_b--;
				}
				else {
					
					a << line_c;
					prints++;
					if (enters < n) {
						enters++;
						a << '\n';
					}
					
					if (portion_c > 0) {
						
						if (!getline(c, line_c, '\n')) {
							portion_c = 0;
							eof_c = true;
						}
					}
					portion_c--;
				}
			}
		}
	}

	a.close();
	b.close();
	c.close();
}

void merge_sort() {
	int portion = 1;

	ifstream a("a.bin", ios::binary);
	string line;
	int n = 0;
	while (getline(a, line, '\n')) {
		n++;
	}
	a.close();

	
	while (portion < n * 2) {
		
		divide(portion);
		unite(portion, n);
		portion *= 2;
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
	//int main_task_5_1() {
	//fill_in_file(100);

	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1> >;
	chrono::time_point<clock_t> start;
	start = clock_t::now();

	merge_sort();
	cout << "Number of prints: " << prints << endl;
	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count();
	return 0;
}
