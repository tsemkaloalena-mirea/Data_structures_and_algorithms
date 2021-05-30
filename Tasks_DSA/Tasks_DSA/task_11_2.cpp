#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

long long int comparing = 0;

vector<int> make_shift_table(string text, string substr) {
	int n = text.size();
	vector<int> shifts(substr.size() + 1, substr.size());
	vector<int> z(substr.size(), 0);
	comparing++;
	for (int j = 1, maxZidx = 0, maxZ = 0; j < substr.size(); ++j) {
		comparing++;
		comparing++;
		if (j <= maxZ) z[j] = std::min(maxZ - j + 1, z[j - maxZidx]);
		comparing++;
		while (j + z[j] < substr.size() && substr[substr.size() - 1 - z[j]] == substr[substr.size() - 1 - (j + z[j])]) z[j]++;
		comparing++;
		if (j + z[j] - 1 > maxZ) {
			maxZidx = j;
			maxZ = j + z[j] - 1;
		}
	}
	comparing++;
	for (int j = substr.size() - 1; j > 0; j--) shifts[substr.size() - z[j]] = j;
	comparing++;
	for (int j = 1; j <= substr.size() - 1; j++) {
		comparing++;
		if (j + z[j] == substr.size()) {
			comparing++;
			for (int r = 0; r <= j; r++) {
				comparing++;
				if (shifts[r] == substr.size()) shifts[r] = j;
			}
		}
	}
	return shifts;
}

int search_for_substring(string text, string substr) {
	vector<int> shift_table = make_shift_table(text, substr);
	int n = text.size();
	comparing++;
	for (int i = 0, j = 0; i <= n - substr.size() && j >= 0; i += shift_table[j + 1]) {
		comparing++;
		for (j = substr.size() - 1; j >= 0 && substr[j] == text[i + j]; j--);
		comparing++;
		if (j < 0)
			return i;
	}
}

//int find_max_poly(string s, int& n) {
//	int i, j, right, left, k, m = 0, p = string::npos, len = s.length();
//	for (i = 0; i < len; ++i) {
//		for (j = i + 1; j < len; ++j) {
//			right = i;
//			left = j;
//			while ((right < left) && (s[right] == s[left])) {
//				++right;
//				--left;
//			}
//
//			k = j - i;
//			if ((right >= left) && (k > m)) {
//				m = k;
//				p = i;
//			}
//		}
//	}
//	n = (m > 0) ? m + 1 : m;
//	return p;
//}

int find_max_palindrome(string text, int& n) {
	int i, j, p, k, m = 0, pos = 0;
	comparing++;
	for (i = 0; i < text.size(); ++i) {
		comparing++;
		for (j = i + 1; j < text.size(); ++j) {
			comparing++;
			string first = text.substr(i, j - i);
			comparing++;
			if (first.size() > (text.size() - j) / 2) break;
			string second = first;
			reverse(second.begin(), second.end());
			p = search_for_substring(text.substr(j), second) + j;
			comparing++;
			if (p < text.size()) {
				comparing++;
				if ((p == j + 1) || (p == j)) {
					k = p + j - i - i - 1;
					comparing++;
					if (k > m) {
						m = k;
						pos = i;
					}
				}
			}
		}
	}
	n = (m > 0) ? m + 1 : m;
	return pos;
}

int main() {
	//string s = "a12325bc9e9c321";
	//string s = "a123gg325bc9e9c";
	//string s = "123456789";

	string s = "";
	for (int i = 0; i < 10000; i++) {
		s += rand() % (122 - 97 + 1) + 97;
	}

	int pos, len;
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1> >;
	chrono::time_point<clock_t> start;
	start = clock_t::now();
	pos = find_max_palindrome(s, len);
	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count() << endl;

	int i, n = pos + len;
	if (len == 0) {
		cout << "no palindrome was found";
	}
	else {
		for (i = pos; i < n; ++i) cout << s[i];
	}
	cout << endl << "Number of comparisons: " << comparing << endl;
	return 0;
}
