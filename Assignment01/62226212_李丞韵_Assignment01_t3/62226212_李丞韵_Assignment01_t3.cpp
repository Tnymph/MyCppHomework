#include<iostream>
#include<cmath>
using namespace std;

int main() {
	//存储点坐标时，依次为xA yA xB yB...
	const int pointNum = 4;
	double point[2*pointNum] = {};

	const double accuracy = 0.000001;
	
	//使用acsii码简化提示词，如'B'为'A' + 1
	cout << "请依次输入"<<pointNum<<"个点的坐标\n";
	for (int i = 0; i < pointNum; i++) {
		cout << (char)('A' + i) << "的x坐标：";
		cin >> point[2*i];
		cout << (char)('A' + i) << "的y坐标：";
		cin >> point[2*i+1];
	}

	//检查重合的点
	for (int i = 0; i < pointNum - 1; i++) {//最后一个点已经被所有点检查过
		for (int j = i + 1; j < pointNum; j++) {//每个点依次检查其他的点
			if (abs(point[2*i] - point[2*j]) < accuracy && abs(point[2*i+1] - point[2*j+1]) < accuracy) {
				cout << "请输入不重合的点";
				return 0;
			}
		}
	}

	//获取从A出发的AB、AC等向量
	const int vecNum = pointNum - 1;
	double vec[2*vecNum] = {};
	for (int i = 0;i < vecNum; i++) {
		vec[2*i] = point[2*(i+1)] - point[0];
		vec[2*i+1] = point[2*(i+1)+1] - point[1];
	}

	//检验是否存在两向量和等于另一向量，证明是平行四边形
	double tempVec[2];
	bool rectangleFlag = false;

	for (int i = 0;i < vecNum; i++) {
		if (rectangleFlag) {//检测出矩形特征就不必再循环
			break;
		}

		for (int j = i + 1; j < vecNum; j++) {
			if (rectangleFlag) {
				break;
			}

			tempVec[0] = vec[2*i] + vec[2*j];//两向量相加，若能得第三向量，则必定为平四
			tempVec[1] = vec[2*i+1] + vec[2*j+1];
			for (int k = 0;k < vecNum; k++) {
				if (rectangleFlag) {
					break;
				}

				if (k != i && k != j) {//第一层if验平四，第二层if验邻边垂直
					if ((abs(tempVec[0] - vec[2*k]) < accuracy) && (abs(tempVec[1] - vec[2*k+1]) < accuracy)) {
						if (abs((vec[2*i] * vec[2*i] + vec[2*i+1] * vec[2*i+1])
							+ (vec[2*j] * vec[2*j] + vec[2*j+1] * vec[2*j+1])
							- (vec[2*k] * vec[2*k] + vec[2*k+1] * vec[2*k+1]))
							< accuracy) {
							rectangleFlag = true;
						}
					}
				}
			}
		}
	}

	if (rectangleFlag) {
		cout << "矩形";
	}
	else {
		cout << "不是矩形";
	}

	return 0;
}
/*
测试1: 0,0 0,1 1,0 1,1 矩形
测试2: 0,1 0,1 1,2 2,1 不是矩形
测试3: 0,0 1,1 0,1 1,0 矩形
测试4: 1,1 1,2 2,2 2,3 不是矩形--针对平行四边形

针对可能出现的漏洞进行测试，更贴近程序实际应用时的场景
用户事先不知道四个点能不能构成矩形，所以有概率碰见极端情况：
如共线、重合、甚至于输入其他形式的坐标如(一，二)
所以有必要根据各种极端情况进行测试，
使算法、程序更加完善，以避免实际运用中造成严重后果
*/