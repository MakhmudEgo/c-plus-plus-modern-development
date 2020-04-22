#include <iostream>
#include <vector>
#include <string>
using namespace std;

void  Command(const int &amount_command)
{
    string command;
    vector<bool> turn;
    int n;
    for (int i = 0; i < amount_command; ++i)
    {
        cin >> command;
        if (command == "COME")
        {
            cin >> n;
            turn.resize(turn.size() + (n));
        }
        else if (command == "WORRY")
        {
            cin >> n;
            turn[n] = true;
        }
        else if (command == "QUIET")
        {
            cin >> n;
            turn[n] = false;
        }
        else if (command == "WORRY_COUNT")
        {
            n = 0;
            for (auto b : turn)
            {
                if(b)
                    n++;
            }
            cout << n << endl;
        }
    }
}

int     main(void)
{
    int amount_command;
    cin >> amount_command;
    Command(amount_command);
    return (0);
}