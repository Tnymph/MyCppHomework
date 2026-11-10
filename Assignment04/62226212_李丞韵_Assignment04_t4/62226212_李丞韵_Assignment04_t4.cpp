#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c2 = 0;
	ofstream ofile("gougu.txt");
	if (!ofile) {
		cout << "目标文件不存在";
		return -1;
	}

	for (int i = 1;i <= 50;i++) {
		a = i;
		for (int j = i;j <= 50;j++) {
			b = j;
			c2 = a * a + b * b;
			double c = sqrt(c2);
			if (c - floor(c) > 0.000001)	continue;
			if (c > 50)		break;
			ofile << a << " " << b << " " << c << endl;
		}
	}
	ofile.close();

	ifstream ifile("gougu.txt");
	if (!ifile) {
		cout << "目标文件不存在";
		return -1;
	}

	char numOut[10] = {};
	while (ifile.getline(numOut, 10)) {
		cout << numOut << endl;
		*numOut = {};
	}

	return 0;
}
/*
甲：
3 4 5
5 12 13

乙：
3 4 5
5 12 13
5 12 13
甲不再循环（读到文档末尾）
乙继续循环（eof()读取到'\n'）


可以每次读取之前都用eof判断一次，三次判断有一次不成立就结束程序
原来的条件，只要每组第一个之前不为eof，就必定触发一次整租输出
*/