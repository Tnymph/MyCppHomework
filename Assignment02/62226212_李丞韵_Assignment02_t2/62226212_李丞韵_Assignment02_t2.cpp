#include <iostream>
using namespace std;

int main() {
	const double zhangDeposit = 10000;
	const double liDeposit = 8000;
	const double zhangRate = 0.06;
	const double liRate = 0.04;

	double zhangProfit = 0;
	double liProfit = 0;
	int turns = 0;

	while (liProfit <= 2 * zhangProfit || turns > 10000) {
		turns++;

		zhangProfit = zhangProfit + zhangDeposit * zhangRate;
		liProfit = liProfit + (liDeposit + liProfit) * liRate;

		cout << "截至第" << turns << "年末小张累计收益" << zhangProfit << endl;
		cout << "截至第" << turns << "年末小李累计收益" << liProfit << endl;
	}

	if (liProfit > 2 * zhangProfit)
		cout << "到第" << turns << "年末, 小李累计收益已经超过小张两倍";

	return 0;
}