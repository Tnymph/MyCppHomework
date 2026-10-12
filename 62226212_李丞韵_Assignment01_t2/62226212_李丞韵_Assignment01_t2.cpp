#include <iostream>
#include <cmath>
using namespace std;

int main(){
	const float taxRate[5] = {0, 0.03, 0.1, 0.2, 0.25};
	float tax = 0;
	float incomeStandard[6] = {0, 60000, 96000, 204000, 360000, 0};
	float incomePieceForCalculate = 0;
	float income = 0;
	bool flag = true;

	cout << "请输入收入: ";
	cin >> income;
	incomeStandard[5] = income + 1;

	if (income < 0) {
		cout << "请输入一个非负的数";
		return 0;
	}

	int i = 0;

	incomePieceForCalculate = income - incomeStandard[i];
	if ((incomePieceForCalculate > incomeStandard[i + 1] - incomeStandard[i]) && flag) {
		tax = tax + (incomeStandard[i + 1] - incomeStandard[i]) * taxRate[i];
	}
	else {
		tax = tax + max(incomePieceForCalculate, 0.0f) * taxRate[i];
		flag = false;
	}
	i = i + 1;

	incomePieceForCalculate = income - incomeStandard[i];
	if ((incomePieceForCalculate > incomeStandard[i + 1] - incomeStandard[i]) && flag) {
		tax = tax + (incomeStandard[i + 1] - incomeStandard[i]) * taxRate[i];
	}
	else {
		tax = tax + max(incomePieceForCalculate, 0.0f) * taxRate[i];
		flag = false;
	}
	i = i + 1;

	incomePieceForCalculate = income - incomeStandard[i];
	if ((incomePieceForCalculate > incomeStandard[i + 1] - incomeStandard[i]) && flag) {
		tax = tax + (incomeStandard[i + 1] - incomeStandard[i]) * taxRate[i];
	}
	else {
		tax = tax + max(incomePieceForCalculate, 0.0f) * taxRate[i];
		flag = false;
	}
	i = i + 1;

	incomePieceForCalculate = income - incomeStandard[i];
	if ((incomePieceForCalculate > incomeStandard[i + 1] - incomeStandard[i]) && flag) {
		tax = tax + (incomeStandard[i + 1] - incomeStandard[i]) * taxRate[i];
	}
	else {
		tax = tax + max(incomePieceForCalculate, 0.0f) * taxRate[i];
		flag = false;
	}
	i = i + 1;

	incomePieceForCalculate = income - incomeStandard[i];
	if ((incomePieceForCalculate > incomeStandard[i + 1] - incomeStandard[i]) && flag) {
		tax = tax + (incomeStandard[i + 1] - incomeStandard[i]) * taxRate[i];
	}
	else {
		tax = tax + max(incomePieceForCalculate, 0.0f) * taxRate[i];
		flag = false;
	}
	
	cout << "应缴税额为: " << tax;

	return 0;
}