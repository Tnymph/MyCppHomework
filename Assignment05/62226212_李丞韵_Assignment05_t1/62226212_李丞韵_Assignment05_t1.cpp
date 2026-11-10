#include <iostream>
using namespace std;

char getCalculation()
{
	char c;
	cout << "输入 x 或 X 以退出\n";
	cout << "请输入想要的运算( + - * / ):";
	cin >> c;
	cout << "\n你选择了:" << c << endl;
	return c;
}

int main() {
	char calculation = '\0';
	while (calculation != 'x' && calculation != 'X')
	{
		double n1, n2;
		calculation = getCalculation();
		if (calculation == 'x' || calculation == 'X')
			return 0;
		if (calculation != '+' && calculation != '-' && calculation != '*' && calculation != '/') {
			cout << "不属于规定的计算" << endl;
			continue;
		}

		cout << "输入要进行运算的数字：";
		cin >> n1 >> n2;
		if (n2 == 0 && calculation == '/') {
			cout << "不是合法的除数\n";
			continue;
		}

		cout << "结果为: ";
		switch (calculation) {
		case('+'):
			cout << n1 + n2;
			break;
		case('-'):
			cout << n1 - n2;
			break;
		case('*'):
			cout << n1 * n2;
			break;
		case('/'):
			cout << n1 / n2;
		}
		cout << endl;
	}

	return 0;
}