#include <iostream>
using namespace std;

bool transport(int& repo1, int& repo2, const int& count)
{
	if (repo1 < count)
		return false;

	repo1 -= count;
	repo2 += count;
	return true;
}

int main() {
	int repo[2] = {};
	int count;

	cout << "分别输入两个仓库的初始货物量 ：\n";
	cin >> repo[0] >> repo[1];

	int name1, name2;
	cout << "输入源仓库(1/2)、目标仓库(1/2)、数量：\n";
	cin >> name1 >> name2 >> count;

	if (name1 - 1 < 0 || name1 - 1 > 1 || name2 - 1 < 0 || name2 - 1 > 1) {
		cout << "输入数字与仓库编号不符";
		return -1;
	}
	if (name1 == name2) {
		cout << "不能输入相同的仓库编号";
		return - 1;
	}

	if (transport(repo[name1 - 1], repo[name2 - 1], count))
		cout << "调拨成功";
	else
		cout << "调拨失败";
	cout << "\n\t仓库1：" << repo[0] << "\n\t仓库2：" << repo[1] << endl;

	return 0;
}
/*
不成立
12 4 6
ok == false, 调用后为 7 9 6
先执行&&左侧的语句，此时成功，即便&&右侧语句执行结果为失败，左半部分移动的货物也不会返还

不能
当遇到 12 6 6 时，本可以搬运两次，但条件判断为无法执行
正确应为 a >= 5 && b >=5
此时一旦判定能进行，则可顺序进行所有任务；若判定为不能进行，则不会进行任何一步
*/