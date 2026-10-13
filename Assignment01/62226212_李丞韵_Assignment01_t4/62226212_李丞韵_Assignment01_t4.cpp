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