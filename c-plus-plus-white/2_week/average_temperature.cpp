#include <iostream>
#include <vector>
using namespace std;

vector<int>     HigherTemperature(const vector<int> &t, const int &days, int &h)
{
    vector<int> result;
    int ave_temp = 0;
    for (auto n : t)
        ave_temp += n;
    ave_temp /= days;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] > ave_temp)
        {
            result.push_back(i);
            h++;
        }
    }
    return (result);
}

int     main(void)
{
    int days;
    int higher_days = 0;
    cin >> days;
    vector<int> temp(days);
    for (auto &i : temp)
        cin >> i;
    temp = HigherTemperature(temp, days, higher_days);
    cout << higher_days << endl;
    for (auto i : temp)
        cout << i << " ";
    return (0);
}