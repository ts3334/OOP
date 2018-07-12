#include "std_lib_facilities.h"

int main() {

	vector<string> text;

	cout << "Please enter a phrase, ctrl D to end: \n";
	for (string word; cin >> word;) {
		text.push_back(word);
	}
	sort(text);

	vector <string> concordance;
	vector<int> concordanceCount;
	string curr = text[0];
	string prev = text[0];
	int count = 0;
	for (int x = 0; x < text.size(); x++) {
		curr = text[x];
		if (curr != prev) {
			concordance.push_back(prev);
			concordanceCount.push_back(count);
			count = 1;
			prev = curr;
		}
		else {
			count = count + 1;
		}
	}
	concordance.push_back(curr);
	concordanceCount.push_back(count);

	for (int x = 0; x < concordance.size(); x++) {
		cout << concordance[x] << ": " << concordanceCount[x] << "\n";
	}

	keep_window_open();
	return 0;
}