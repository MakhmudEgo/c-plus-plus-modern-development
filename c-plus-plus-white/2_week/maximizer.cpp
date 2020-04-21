#include <iostream>
using namespace std;

void    UpdateIfGreater(int first, int& second)
{
    if (first > second)
        second = first;
}

int     main(void)
{
    int a = 4;
    int b = 2;
    int c = 3;
    int d = 377;
    cout << b <<  endl;
    UpdateIfGreater(a, b);
    cout << b << endl;

    cout << d << endl;
    UpdateIfGreater(c, d);
    cout << d << endl;

    return (0);
}