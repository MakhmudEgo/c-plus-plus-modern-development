#include <iostream>
using namespace std;

int     main(void)
{
    int x, y, z;

    cin >> x >> y;
    while (y)
    {
        z = x % y;
        x = y;
        y = z;
    }
    cout << x;
}