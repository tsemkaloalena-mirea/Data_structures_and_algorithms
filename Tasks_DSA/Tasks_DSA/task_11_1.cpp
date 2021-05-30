#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

vector<string> search(string text, string substring) {
	long long int comparing = 1;
	vector<string> words;
	string word = "";
	int k = 0;
	bool found = false;
	bool full_found = false;
	for (int i = 0; i < text.size(); i++) {
		comparing++;
		if (text[i] > 31 && text[i] < 48 || text[i] == 58 || text[i] == 59) {
			comparing++;
			if (full_found) {
				words.push_back(word);
				//cout << "Number of comparisons: " << comparing << endl;
			}
			found = false;
			full_found = false;
			word = "";
			k = 0;
		}
		else {
			word += text[i];
			comparing++;
			if (!full_found) {
				comparing++;
				if (text[i] == substring[k]) {
					k++;
					comparing++;
					comparing++;
					if (k == substring.size()) {
						full_found = true;
						comparing--;
					}
					else if (!found) {
						found = true;
					}
				}
				else {
					comparing++;
					if (found) {
						found = false;
						k = 0;
					}
				}
			}
		}
	}
	comparing++;
	if (full_found) {
		words.push_back(word);
	}
	cout << "Number of comparisons: " << comparing << endl;
	return words;
}

int main() {
	string text = "";
	for (int i = 0; i < 10; i++) {
		if (i % 5 == rand() % 5) text += rand() % (47 - 32 + 1) + 32;
		else text += rand() % (122 - 97 + 1) + 97;
	}
	//cout << text << endl;
	//string text = "J Strother Moore (his first name is the alphabetic character 'J' – not an abbreviated 'J.') is a computer scientist. He is a co-developer of the Boyer–Moore string-search algorithm, Boyer–Moore majority vote algorithm, and the Boyer–Moore automated theorem prover, Nqthm. He made pioneering contributions to structure sharing including the piece table data structure and early logic programming. An example of the workings of the Boyer–Moore string search algorithm is given in Moore's website. Moore received his Bachelor of Science (SB) in mathematics at Massachusetts Institute of Technology in 1970 and his Doctor of Philosophy (Ph.D.) in computational logic at the University of Edinburgh in Scotland in 1973.";
	
	//string text = "njk string inf dings";
	//string text = "njk strshs, shtlk. ag";
	//string text = "/&#!";

	string substring = "x";
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1> >;
	chrono::time_point<clock_t> start;
	start = clock_t::now();
	vector<string> words = search(text, substring);
	cout << chrono::duration_cast<second_t>(clock_t::now() - start).count() << endl;
	if (words.empty()) {
		cout << "no matching words";
	}
	else {
		//for (string word : words) cout << word << endl;
	}

	return 0;
}
