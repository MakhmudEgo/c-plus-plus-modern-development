#include <iostream>
using namespace std;

int Factorial(int n)
{
    int factorial = 1;

    if (n < 2)
        return (1);
    else
    {
         while (n >=1)
         {
             factorial *= n;
             --n;
         }
    }
    return (factorial);
}

int     main(void)
{
    cout << Factorial(4) << endl;
    cout << Factorial(-2) << endl;
    cout << Factorial(1) << endl;
    cout << Factorial(0) << endl;
    cout << Factorial(10) << endl;
    return (0);
}