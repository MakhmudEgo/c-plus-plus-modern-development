#include <iostream>
#include <vector>
using namespace std;

void    Reverse(vector<int>& v)
{
    vector<int> tmp = v;
    for (int i = 0; i < v.size(); i++)
        v[i] = tmp[tmp.size() - i - 1];
}

int     main(void)
{
    vector<int> test = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (auto i : test)
        cout << i << ", ";
    Reverse(test);
    cout << endl << "After" << endl;
    for (auto i : test)
        cout << i << ", ";
    return (0);
}