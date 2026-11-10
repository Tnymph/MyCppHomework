#include <iostream>
using namespace std;

int main() {
	int a[5] = {};
	int b[5] = {};

	cout << "请输入数组a中五个元素(整形):" << endl;
	for (int i = 0;i < 5;i++) {
		cin >> a[i];
	}

	cout << "请输入数组b中五个元素(整形):" << endl;
	for (int i = 0;i < 5;i++) {
		cin >> b[i];
	}

	for (int i = 0; i < 5;i++) {
		bool same = false;
		for (int k = 0;k < 5;k++) {
			if (a[i] == b[k]) {
				same = true;
				break;
			}
		}
		if (!same)	cout << a[i] << " ";
	}

	for (int i = 0; i < 5;i++) {
		bool same = false;
		for (int k = 0;k < 5;k++) {
			if (b[i] == a[k]) {
				same = true;
				break;
			}
		}
		if (!same)	cout << b[i] << " ";
	}

	return 0;
}