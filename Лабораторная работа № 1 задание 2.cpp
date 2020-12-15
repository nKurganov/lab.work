#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float a, b, res;
    cout << "Введите значение а" << endl;
    cin >> a;
    cout << "Введите значение b" << endl;
    cin >> b;

    res = (pow(a + b, 2) - (pow(a, 2) + 2 * a * b)) / (pow(b, 2));

    cout << "Значение выражения = ";
    cout << res << endl;
    system("pause");
}
