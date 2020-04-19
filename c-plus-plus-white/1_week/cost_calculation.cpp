#include <iostream>
using namespace std;

int     main(void)
{
    double n, a, b, x, y;

    cin >> n >> a >> b >> x >> y;
    if (n > a && a < b && n <= b)
        cout << (n / 100) *(100 - x);
    else if (n > b)
        cout << (n / 100) *(100 - y);
    else 
        cout << n;
    return 0;
}