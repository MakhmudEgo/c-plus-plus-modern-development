#include <iostream>
using namespace std;

int     main(void)
{
    int a, b;
    
    cin >> a >> b;
    while (a <= b)
    {
        if (a % 2 == 0)
            cout << a << " ";
        ++a;
    }
    return 0;
}