#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    double n, m;
    cout << " Введите значение n " << endl;
    cin >> n;
    cout << " Введите значение m " << endl;
    cin >> m;
    cout << "Значение выражения n+++m = " << n + ++m << endl;
    cout << "Значение выражения n-- >m = " << (m-- > n) << endl;
    cout << "Значение выражения n-- >m = " << (n-- > m) << endl;
    system("pause");
}
