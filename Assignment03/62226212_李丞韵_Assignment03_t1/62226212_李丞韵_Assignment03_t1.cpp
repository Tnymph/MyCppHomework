#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	std::srand((unsigned int)std::time(0));
	const int num = std::rand() % 18 + 1;
	const int maxAttempts = 5;

	cout << "请输入所猜数字(1-18)" << endl;
	int guessNum;
	int guessCount = 0;
	for (int i = 1; i <= maxAttempts; i++) {
		cout << "第" << i << "次：";
		cin >> guessNum;
		guessCount = i;

		if (guessNum > num)
			cout << "猜大了\n";
		else if (guessNum < num)
			cout << "猜小了\n";
		else
			break;	
	}

	if (guessNum != num) {
		cout << "游戏失败！正确数字是: " << num;
		return 0;
	}

	switch (guessCount) {
	case 1:
		cout << "真幸运！";
		break;
	case 2:
	case 3:
		cout << "好棒！";
		break;
	case 4:
	case 5:
		cout << "猜对了！";
	}

	return 0;
}
/*
考虑最坏的情况，则倒数第二次选择最多剩三项
此时选择中间的那项，可以在锁定所求项的同时，探明最多项
以此类推，则倒数第三次，选择剩余七项中的第四项。
倒数第n次，选择(2^n - 1)项中的第(2^(n-1))项

1.
	每次猜完，由剩余项数，找n，使得(2^(n-1) - 1) < 剩余项 <= (2^n - 1)
	再取猜剩余项中的第(2^(n-1))项

	由(2^(5-1) - 1) < 18 < (2^5 - 1)得，最多5次

2.
	不存在
*/