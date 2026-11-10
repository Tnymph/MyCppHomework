#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream file("random_numbers.txt");
	if (!file) {
		cout << "文件打开失败";
		return -1;
	}
	if (file.eof()) {
		cout << "文件中没有数据";
		return -1;
	}

	int num = 0;
	int frequency[20];
	for (int i = 0;i < 20;i++)
		frequency[i] = 0;

	for (int i = 0;i < 450;i++) {
		if (!(file >> num)) {
			break;
		}
		if (num > 20) {
			cout << "出现了大于20的数字";
			return -1;
		}
		frequency[num - 1]++;
	}

	int less = frequency[0];
	for (int i = 0;i < 20;i++) {
		if (less > frequency[i])
			less = frequency[i];
	}
	cout << "出现次数最少的数字是: \n";
	for (int i = 0;i < 20;i++) {
		if (frequency[i] == less)
			cout << i + 1 << " ";
	}
	cout << "\n出现了 " << less << " 次";

	file.close();
	return 0;
}
/*
k为20时，
方法一工作时，进行了150次赋值，k次判断，k次输出(最坏情况)。数组容量k
方法二工作时，进行了150*2次赋值，(1+150)*150/2次比较，k次输出(最坏情况)。数组容量min(2*k,150)
这种条件下，甲消耗时间更短，占用内存更小，所以用甲

k为10000时，
甲的判断次数大大增加，导致运行耗时增加;且数组容量也大大增加，占用更多内存，且初始化时赋值次数也变多
此时选用甲不再合适
*/