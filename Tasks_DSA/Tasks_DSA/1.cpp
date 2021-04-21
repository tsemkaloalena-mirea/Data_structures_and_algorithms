//#include <iostream>
//#include <fstream>
//#include <chrono>
//#include <vector>
//using namespace std;
//
//long long int compare = 0, swapping = 0;
//
//void divide(int s1, int s2, int mark) {
//	ifstream a("a.bin", ios::binary);
//	ofstream b;
//	ofstream c;
//	b.open("b.bin", ios::binary);
//	c.open("c.bin", ios::binary);
//	string line_1;
//	string line_2;
//	bool eof_b = false;
//
//	if (getline(a, line_1, '\n')) {
//		b << line_1;
//	}
//	if (getline(a, line_2, '\n')) {
//		c << line_2;
//	}
//	while (!a.eof()) {
//		if (line_2 < line_1) {
//			switch (mark) {
//			case 1:
//				b << "' ";
//				mark = 2;
//				s1++;
//			case 2:
//				c << "' ";
//				mark = 1;
//				s2++;
//			}
//		}
//		if (mark == 1) {
//			b << line_2;
//			s1++;
//		}
//		else {
//			c << line_2;
//			s2++;
//		}
//		line_1 = line_2;
//		getline(a, line_2, '\n');
//	}
//
//
//	if (s2 > 0 && mark == 2) {
//		c << "'";
//	}
//	if (s1 > 0 && mark == 1) {
//		b << "'";
//	}
//
//
//
//	a.close();
//	b.close();
//	c.close();
//}
//
//bool End_Range(string line) {
//	char a = line[line.size() - 1];
//	int tmp;
//	//tmp = fgetc(f);
//	//tmp = fgetc(f);
//	//if (tmp != '\'') fseek(f, -2, 1);
//	//else fseek(f, 1, 1);
//	//return tmp == '\'' ? true : false;
//	return true;
//}
//
//void unite() {
//	ofstream a;
//	a.open("a.bin", ios::binary);
//	ifstream b("b.bin", ios::binary);
//	ifstream c("c.bin", ios::binary);
//	string line_1, line_2;
//	bool f_b, f_c;
//
//	getline(b, line_1, '\n');
//	getline(c, line_2, '\n');
//	while (!b.eof() && !c.eof()) {
//		f_b = f_c = false;
//		while (!f_b && !f_c) {
//			if (line_1 <= line_2) {
//				a << line_1;
//				f_b = End_Range(line_1);
//				getline(b, line_1, '\n');
//			}
//			else {
//				a << line_2;
//				f_c = End_Range(line_2);
//				getline(c, line_2, '\n');
//			}
//		}
//		while (!f_b) {
//			a << line_1;
//			f_b = End_Range(line_1);
//			getline(b, line_1, '\n');
//		}
//		while (!f_c) {
//			a << line_2;
//			f_c = End_Range(line_2);
//			getline(c, line_2, '\n');
//		}
//	}
//	f_b = f_c = false;
//	while (!f_b && !b.eof()) {
//		a << line_1;
//		f_b = End_Range(line_1);
//		getline(b, line_1, '\n');
//	}
//	while (!f_c && !c.eof()) {
//		a << line_2;
//		f_c = End_Range(line_2);
//		getline(c, line_2, '\n');
//	}
//
//
//
//	a.close();
//	b.close();
//	c.close();
//}
//
//
//
//void natural_merge_sort() {
//	ifstream a("a.bin", ios::binary);
//
//	int s1, s2, mark;
//	s1 = s2 = 1;
//	while (s1 > 0 && s2 > 0) {
//		mark = 1;
//		s1 = 0;
//		s2 = 0;
//		divide(s1, s2, mark);
//		unite();
//	}
//
//	a.close();
//
//}
//
//int main() {
//	//int main_task_5_2() {
//
//	using clock_t = chrono::high_resolution_clock;
//	using second_t = chrono::duration<double, std::ratio<1> >;
//	chrono::time_point<clock_t> start;
//	start = clock_t::now();
//
//	natural_merge_sort();
//
//
//	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count();
//	return 0;
//}
