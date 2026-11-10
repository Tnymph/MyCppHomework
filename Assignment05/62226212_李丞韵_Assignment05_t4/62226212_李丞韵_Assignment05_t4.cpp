#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double trap_area(const double& a, const double& b, const double& h)
{
	return (a + b) * h / 2;
}

double integral(const auto& f, const double& a, const double& b, const int& n)
{
	double left = min(a, b);
	double right = max(a, b);
	double step = (right - left) / n;
	double area = 0;

	// 分块计算，再相加
	for (double i = 0; i < n; i++) {
		area += trap_area(f(left + i * step), f(left + (i + 1) * step), step);
	}

	return area;
}

int main() {
	// 要计算的函数
	auto f = [](double x){return x * x + 2 * x + 2;};

	// 左右端点
	double a = 0;
	double b = 0;
	cout << "输入区间左、右端点:" << endl;
	cin >> a >> b;

	cout << "n = 10: " << ::integral(f, a, b, 10) << endl;
	cout << "n = 100: " << ::integral(f, a, b, 100) << endl;
	cout << "n = 1000: " << ::integral(f, a, b, 1000) << endl;

	return 0;
}