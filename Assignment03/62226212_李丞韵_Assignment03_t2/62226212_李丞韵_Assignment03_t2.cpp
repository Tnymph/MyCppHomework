#include <iostream>
using namespace std;

/*
思路：
	先计算牛奶的最大数量，牛奶数量从0到最大，枚举
	每轮内，算得豆奶的最大数量
	之后算出总价格、蛋白质，和上一轮数据比较
	蛋白质多，则覆盖所有上轮数据
	遍历所有可能之后，即得蛋白质最大值
*/

int main() {
	// 预算
	const int maxBudget = 27;
	// 价格、蛋白质含量
	const double milk[2] = { 5, 7.1 };
	const double soyMilk[2] = { 3, 4 };
	// 牛奶数量、豆奶数量、总费用、蛋白质总量
	double plan[4] = { 0 ,0 ,0 ,0 };

	int maxMilkCount = int(maxBudget / milk[0]);
	for (int i = 0; i <= maxMilkCount; i++) {
		plan[2] = i * milk[0];
		int soyMilkCount = (maxBudget - plan[2]) / soyMilk[0];
		int Protein = i * milk[1] + soyMilkCount * soyMilk[1];
		if (Protein > plan[3]) {
			plan[0] = i;
			plan[1] = soyMilkCount;
			plan[2] = i * milk[1] + soyMilkCount * soyMilk[1];
			plan[3] = Protein;
		}else
			continue;
	}
	cout << "牛奶数量" << plan[0]
		<< "\n豆奶数量" << plan[1]
		<< "\n总费用" << plan[2]
		<< "\n蛋白质总量" << plan[3];

	return 0;
}