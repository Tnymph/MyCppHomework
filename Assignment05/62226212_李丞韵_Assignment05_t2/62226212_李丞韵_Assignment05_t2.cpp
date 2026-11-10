#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int exponentiation(int num, int count)
{
	if (count == 0) {
		return 1;
	}

	int result = num;
	for (int i = 1; i < count; i++) {
		result *= num;
	}
	return result;
}

bool judge(int num)
{
	if (num <= 0)
		return false;

	int level = 1;
	while (num / exponentiation(10, level - 1) >= 10) {
		level++;
	}

	int rawLevel = level;
	int addResult = 0;
	int temp = 0;

	for (level;level > 0;level--) {
		temp = floor(num / exponentiation(10, level - 1)) - floor(num / exponentiation(10, level)) * 10;
		addResult += exponentiation(temp, rawLevel);
	}

	if (addResult == num)
		return true;
	return false;
}

int main() {
	int n1, n2;
	cout << "输入端点值:" << endl;
	cin >> n1 >> n2;
	cout << "结果如下:\n";

	bool findFlag = false;
	for (int i = min(n1, n2);i <= max(n1, n2);i++) {
		if (judge(i)) {
			cout << i << endl;
			findFlag = true;
		}
	}

	if (!findFlag)
		cout << "未找到";

	return 0;
}