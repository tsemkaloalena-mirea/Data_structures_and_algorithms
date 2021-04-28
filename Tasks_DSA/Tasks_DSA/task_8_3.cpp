//#include <iostream>
//#include <queue>
//#include <stack>
//#include <string>
//using namespace std;
//
//
//int main() {
//	string long_int_1, long_int_2, result = "";
//	//cin >> long_int_1 >> long_int_2;
//	long_int_1 = "985123345";
//	long_int_2 = "168955";
//
//	queue <int> Q1;
//	queue <int> Q2;
//	for (int i = long_int_1.size() - 1; i >= 0; i--) {
//		Q1.push(static_cast<int>(long_int_1[i]) - '0');
//	}
//	for (int i = long_int_2.size() - 1; i >= 0; i--) {
//		Q2.push(static_cast<int>(long_int_2[i]) - '0');
//	}
//	int n = long_int_1.size();
//	if (n < long_int_2.size()) {
//		n = long_int_2.size();
//	}
//	int q = 1, r = 0;
//	while(q != 0 || r != 0) {
//		if (!Q1.empty() && !Q2.empty()) {
//			q = Q1.front() + Q2.front() + r;
//			Q1.pop();
//			Q2.pop();
//			r = q / 10;
//			result += to_string(q % 10);
//		}
//		else if (!Q1.empty()) {
//			q = Q1.front() + r;
//			Q1.pop();
//			r = q / 10;
//			result += to_string(q % 10);
//		}
//		else if (!Q2.empty()) {
//			q = Q2.front() + r;
//			Q2.pop();
//			r = q / 10;
//			result += to_string(q % 10);
//		}
//		else {
//			q = r;
//			r = q / 10;
//			if (!(q == 0 && r == 0)) {
//				result += to_string(q % 10);
//			}
//		}
//	}
//	reverse(result.begin(), result.end());
//	std::cout << result;
//	return 0;
//}
