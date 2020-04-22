#include <iostream>
#include <vector>
#include <string>
using namespace std;

int     main(void)
{
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_index = 0;
    string command;
    int amount_command;
    int day;
    string aff;

    cin >> amount_command;
    vector<vector<vector<string>>> affairs(12);
    affairs[month_index].resize(month[month_index]);
    for (int i = 0; i < amount_command; i++)
    {
        cin >> command;
        if (command == "ADD")
        {
            cin >> day >> aff;
            affairs[month_index][day - 1].push_back(aff);
        }
        else if (command == "DUMP")
        {
            cin >> day;
            if (!affairs[month_index][day - 1].size())
                cout << 0 << endl;
            else
            {
                for (auto a : affairs[month_index][day - 1])
                    cout << a << " ";
                cout << endl;
            }
        }
        else if (command == "NEXT")
        {
            if (month_index == 11)
            {
                month_index = 0;
                affairs[month_index].insert(end(affairs[month_index]), begin(affairs[11]), end(affairs[11]));
            }
            else
            {
                ++month_index;
                affairs[month_index].insert(end(affairs[month_index]), begin(affairs[month_index - 1]), end(affairs[month_index - 1]));
            }
            affairs[month_index].resize(month[month_index]);
            if (month[month_index - 1] > month[month_index])
            {
                int tmp = month[month_index];
                while (tmp < month[month_index - 1])
                {
                    for (auto a : affairs[month_index - 1][tmp])
                        affairs[month_index][month[month_index] - 1].push_back(a);
                    tmp++;
                }
            }
            if (month_index == 0)
                affairs[11].clear();
            else
                affairs[month_index - 1].clear();
        }
    }
    return (0);
}