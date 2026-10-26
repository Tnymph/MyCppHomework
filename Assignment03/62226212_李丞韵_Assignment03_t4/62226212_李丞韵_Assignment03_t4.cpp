#include <iostream>
using namespace std;

int main() {
	long double x = 0;

	cout << "请输入大于0.5的实数x：";
	cin >> x;

	if (x <= 0.5) {
		cout << "大小不符合要求";
		return 0;
	}

	//  首项
	long double t = (x - 1) / x;
	int elementCount = 1;
	long double element = t;
	long double lnx = element;

	while (element > 10e-6) {
		if (elementCount >= 10000) {
			cout << "项数已达到上限，算得lnx = " << lnx;
			return 0;
		}

		// 下一项
		t = t * t;
		elementCount++;
		element = t / elementCount;
		lnx = lnx + element;
	}

	cout << "lnx = " << lnx;
	return 0;
}
/*
1.
	不成立
	t = 0.99，近似为1；721、722、723作为分母，近似相等
	则这三项近似相等，这里都看作10e-7
	722、723相加近似为10e-6，再加上后面的无穷多项，无法证明|lnx - Sn| < 10e-6

2.
	x -> 0.5+时，t -> -1；x -> 无穷时，t -> 1；
	这两种情况下，每项的绝对值趋近于1/n，
	x > 0.5时的其他情况则均小于1/n
	故这两种情况下收敛更慢，更容易超出10000的数量限制
	但这并不代表它发散，因为 n -> 无穷，1/n -> 0
*/