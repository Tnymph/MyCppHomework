#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//分数段左闭右开
	const int judgeNum = 7;
	const int standardNum = 5;

	const char levelName[standardNum] = { 'D', 'C', 'B', 'A', '\0'};
	const int standard[standardNum] = {0, 72, 82, 92, 101 };
	int judges[judgeNum];
	int maxJudge = 0;
	int minJudge = 0;
	double average = 0;
	char levels[7] = {};

	//获取裁判给出的分数, 并获取最大、最小值对应的裁判编号
	for (int i = 0; i < judgeNum; i++) {
		cout << "请输入裁判" << i + 1 << "的评分(0-100):";
		cin >> judges[i];

		if (judges[i] > 100 || judges[i] < 0)
			cout << "请输入规定范围内的数字";

		//判断最大和最小时, 使用 < 和 >= 来避免最大和最小裁判为一人
		if (judges[maxJudge] < judges[i])
			maxJudge = i;
		else if (judges[minJudge] >= judges[i])
			minJudge = i;
	}

	cout << "最高分: " << judges[maxJudge] << endl;
	cout << "最低分" << judges[minJudge] << endl;

	//累加去极求平均
	for (int i = 0; i < judgeNum; i++)
		average = average + judges[i];
	average = (average - judges[maxJudge] - judges[minJudge]) / (judgeNum - 2);

	cout << "两个极值以外, 评分的平均值为: " << average << endl;

	for (int i = 0; i < judgeNum; i++) {
		//先对应赋值编号
		for (int k = standardNum - 1; k >= 0; k--) {
			if (judges[i] >= standard[k]) {
				levels[i] = k;
				break;
			}
		}

		//依照编号查找实际等级名
		switch (levels[i]) {
		case 0:
			levels[i] = levelName[0];
			break;
		case 1:
			levels[i] = levelName[1];
			break;
		case 2:
			levels[i] = levelName[2];
			break;
		case 3:
			levels[i] = levelName[3];
			break;
		}

		cout << "第" << i + 1 << "位评委的评级是" << levels[i] << endl;
	}

	return 0;
}