#include <iostream>
using namespace std;

int main() {
	char rawString[20] = {};
	char tempChar;

	cout << "ÇëÊäÈëÒ»´®ASCII×Ö·û:\n";
	cin.getline(rawString, 19);

	for (int i = 0;i < 20;i++) {
		for (int j = i + 1;j < 20;j++) {
			tempChar = rawString[i];
			if (rawString[j] > rawString[i]) {
				rawString[i] = rawString[j];
				rawString[j] = tempChar;
			}
		}
	}

	cout << rawString;

	return 0;
}