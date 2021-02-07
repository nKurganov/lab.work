#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    int s = 0;
    for (int n = 1; n < 200; n = n + 3)
        s = n + s;
    cout << "Сумма целых положительных чисел кратных трем и меньше 200 равна - " << s << endl;

    system("pause");

    return 0;
}