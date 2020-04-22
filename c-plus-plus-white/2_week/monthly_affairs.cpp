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
    cin >> amount_command;
    vector<vector<vector<string>>> affairs(12);
    for (int i = 0; i < month.size(); i++)
        affairs[i].resize(month[i]);



    affairs[0][0].push_back("hello");
    affairs[0][0].push_back("hello");
    affairs[0][0].push_back("hello");
    for(auto a : affairs[0][0])
        cout << a << endl;

//    for (int i = 0; i < amount_o; i++)
//    {
//        cin >> command;
//        if (command == "ADD")
//        {
//            affairs[amount_command]
//        }
//    }

}
