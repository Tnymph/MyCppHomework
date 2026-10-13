#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double PI = 3.1415926;
    double radius = 0;
    double perimeter = 0;
    double area = 0;

    cout << "请输入面积: ";
    cin >> area;

    if (area < 0) {
        cout << "请输入正确的数字" << endl;
        return 0;
    }

    radius = sqrt(area / PI);
    perimeter = 2 * PI * radius;

    cout << "半径为：" << radius << "\n周长为：" << perimeter << endl;

    return 0;
}