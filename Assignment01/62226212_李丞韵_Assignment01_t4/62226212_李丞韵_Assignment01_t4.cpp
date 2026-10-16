#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const string n = "\n\n";
	const int stringSize = 80;
	char aa[stringSize] = {};
	char bb[stringSize] = {};
	char cc[stringSize] = {};

	cout << "输入姓名拼音与学号，姓氏和名字间用 1 个空格，姓名与学号间用 1 个英文逗号"<<endl;
	cout << "例如\"Zhang San,20260001\"，整行最多 79 个字符，不计换行"<< n;

	cin.getline(aa, stringSize);
	cout << "\n获取到：\n" << aa << n;

	strcpy_s(bb, aa);
	cout << "经过strcpy_c复制后，得到的bb为：\n" << bb << n;

	for (int i = 0; i < stringSize; i++) {
		cc[i] = aa[i];
	}
	cout << "经过逐个字符复制后，得到的cc为：\n" << cc << n;

	return 0;
}
/*
第一次：computer
第二次：catputer
第一次存储在数组里的是computer\0\0
第二次则是只覆盖了前三个值，所以是catputer\0\0
每次输出时，系统在读取到\0时自动截止，而第二次复制时，没有把原字符串的\0带过去，所以出现这种问题

可以解决，不必这样做
可以连带着字符串末尾的\0一起复制，源字符串空时也有效，""内容是'\0'
*/