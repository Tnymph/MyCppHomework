#include <iostream>
using namespace std;

int main() {
	const int lastDay = 8;

	int day_count[lastDay] = {};
	day_count[lastDay - 1] = 1;

	for (int i = lastDay - 2; i >= 0; i--) {
		day_count[i] = (day_count[i + 1] + 1) * 2;
	}

	for (int i = 1; i <= lastDay; i++)
		cout << "第" << i << "天初始数量：" << day_count[i - 1] << endl;

	return 0;
}