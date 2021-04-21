//#include <iostream>
//#include <fstream>
//#include <chrono>
//#include <vector>
//using namespace std;
//
//long long int compare = 0, swapping = 0;
//
//void divide() {
//	ifstream a("a.bin", ios::binary);
//	ofstream b("b.bin", ios::binary);
//	ofstream c("c.bin", ios::binary);
//	string line;
//	int k = 0;
//	while (getline(a, line, '\n')) {
//		if (k % 2 == 0) {
//			b << line;
//			b << '\n';
//		}
//		else {
//			c << line;
//			c << '\n';
//		}
//		if (line.find("'") != -1) {
//			k++;
//		}
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
//void unite() {
//	ofstream a;
//	a.open("a.bin", ios::binary);
//	ifstream b("b.bin", ios::binary);
//	ifstream c("c.bin", ios::binary);
//	string line_b, line_c;
//	bool eof_b = false, eof_c = false;
//	int mark_found_b, mark_found_c;
//
//	while (!eof_b || !eof_c) {
//		mark_found_b = false;
//		mark_found_c = false;
//		if (!getline(b, line_b, '\n')) {
//			eof_b = true;
//		}
//		if (!getline(c, line_c, '\n')) {
//			eof_c = true;
//		}
//		while (!(mark_found_b && mark_found_c)) {
//			if (eof_b && eof_c) {
//				break;
//			}
//			if (mark_found_b || eof_b) {
//				a << line_c;
//				a << '\n';
//				if (line_c.find("'") != -1) {
//					mark_found_c = true;
//				}
//				if (!mark_found_c) {
//					if (!getline(c, line_c, '\n')) {
//						eof_c = true;
//					}
//				}
//
//			}
//			else if (mark_found_c || eof_c) {
//				a << line_b;
//				a << '\n';
//				if (line_b.find("'") != -1) {
//					mark_found_b = true;
//				}
//				if (!mark_found_b) {
//					if (!getline(b, line_b, '\n')) {
//						eof_b = true;
//					}
//				}
//
//			}
//			else {
//				if (line_b < line_c) {
//					a << line_b;
//					a << '\n';
//					if (line_b.find("'") != -1) {
//						mark_found_b = true;
//					}
//					if (!mark_found_b) {
//						if (!getline(b, line_b, '\n')) {
//							eof_b = true;
//						}
//					}
//
//				}
//				else {
//					a << line_c;
//					a << '\n';
//					if (line_c.find("'") != -1) {
//						mark_found_c = true;
//					}
//					if (!mark_found_c) {
//						if (!getline(c, line_c, '\n')) {
//							eof_c = true;
//						}
//					}
//
//				}
//			}
//		}
//	}
//
//	a.close();
//	b.close();
//	c.close();
//}
//
//int series_divide() {
//	int s = 0;
//	ifstream a("a.bin", ios::binary);
//	ofstream b;
//	b.open("b.bin", ios::binary);
//	string line_1, line_2;
//
//	if (getline(a, line_1, '\n')) {
//		b << line_1;
//		while (getline(a, line_2, '\n')) {
//			if (line_2 <= line_1) {
//				b << "'";
//				s++;
//			}
//			b << '\n';
//			b << line_2;
//			line_1 = line_2;
//		}
//	}
//
//	a.close();
//	b.close();
//
//	ifstream bb("b.bin", ios::binary);
//	ofstream aa("a.bin", ios::binary);
//
//	while (getline(bb, line_1, '\n')) {
//		aa << line_1;
//		aa << '\n';
//	}
//
//	aa.close();
//	bb.close();
//	return s;
//}
//
//void natural_merge_sort() {
//	int s;
//	s = series_divide();
//
//	divide();
//	unite();
//
//
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
