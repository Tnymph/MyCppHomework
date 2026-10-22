#include <iostream>
using namespace std;

int main() {
	const int maxCount = 20;

	char str[20] = {};
	int count = maxCount;

	cout << "请输入文本(单字节字符组成):" << endl;
	for (int i = 0; i < maxCount; i++) {
		count = i + 1;
		cin.get(str[i]);
		if (i >= 2 && str[i] == 'd' && str[i - 1] == 'n' && str[i - 2] == 'e')
			break;
	}
	cout << endl;

	for (int i = count - 1; i >= 0; i--) {
		cout << str[i];
	}

	return 0;
}

/*
1.
甲
	先求出(n >= 3)为假，之后不再求值；

乙
	先求出(n >= 3)为假，再求(s[n-3] == 'e')，
	此时由于下标小于0，访问到内存中，存储在s[0]的前8个字节的数据(或者报错)
	转化为字符类型之后,先判断是否等于'e'，再和前一步得到的false进行按位与，得到0
	之后步骤类似，最后得到0，返回false；

丙
	先求存储在s[0]的前8个字节的数据(或者报错)，
	转化为字符类型之后先判断是否等于'e'，
	如果得到true再判断(s[n-2] == 'n')，得到false，
	之后不再执行后续判断，返回false；

甲能安全得出，乙丙会访问数组外的数据
s[n-3]，因为n-2<0

2.
一致；不能
不同的运算符代表的运算含义不同，结果往往大相径庭
排列会影响运算执行的顺序，可能导致结果不同
*/