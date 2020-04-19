#include <iostream>
#include <cmath>
using namespace std;

int     main(void)
{
    double a, b, c, d, x;

    cin >> a >> b >> c;
    d = b * b - (4 * a * c);
    if ((a == 0 && c == 0) || (b == 0 && b == c))
        cout << 0;
    else if  (a == 0 && a != b)
        cout << (-1 * c)/b;
    else if (d == 0 && a != 0 && b != 0)
        cout << (-1 * b)/(2 * a);
    else if (d > 0) 
        cout << (-1 * b + sqrt(d)) / (2 * a) << " " << (-1 * b - sqrt(d)) / (2 * a);
    return 0;
}