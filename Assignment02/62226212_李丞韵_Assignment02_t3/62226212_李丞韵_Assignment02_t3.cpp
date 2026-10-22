#include <iostream>
using namespace std;

int main() {
	int height = 5;

	//图一
	for (int i = height;i >=1 ; i--) {
		for (int k = 1;k < i;k++)
			cout << " ";
		for (int k = 1;k <= 2 * (height - i) + 1;k++)
			cout << "*";
		for (int k = 1;k < i;k++)
			cout << " ";

		cout << endl;
	}
	cout << endl;

	//图二
	height = 4;

	for (int i = height;i >= 1; i--) {
		for (int k = 1;k < i;k++)
			cout << " ";
		for (int k = 1;k <= 2 * (height - i) + 1;k++)
			cout << "*";
		for (int k = 1;k < i;k++)
			cout << " ";

		cout << endl;
	}
	for (int i = 2;i <= height; i++) {
		for (int k = 1;k < i;k++)
			cout << " ";
		for (int k = 1;k <= 2 * (height - i) + 1;k++)
			cout << "*";
		for (int k = 1;k < i;k++)
			cout << " ";

		cout << endl;
	}

	return 0;
}