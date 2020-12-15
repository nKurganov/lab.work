#include <iostream>   
#include <math.h>       

using namespace std;

int main()
{
    const float eps = 0.0001;
    const int n = 10;

    for (double x = 0.1; x <= 1; x += 0.1)
    {
        double y = pow(3, x);
        int fact = 1;
        double S = 1;
        for (int i = 1; i <= n; i++)
        {
            S += pow(x, i) * pow(log(3), i) / fact;
            fact = fact * i;
        }
        cout << "X = " << x << " Y = " << y << " SN = " << S;
        S = 1;
        fact = 1;
        int N = 1;
        double Y = 1;
        while (abs(Y) >= eps)
        {
            Y = pow(x, N) * pow(log(3), N) / fact;
            N++;
            fact = fact * N;
            S += Y;
        }
        cout << " SE = " << S << "\n";
    }
    return 0;
}
