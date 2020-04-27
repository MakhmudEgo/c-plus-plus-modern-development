#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void    ft_print(vector<string> &n) {
    for (auto &item : n)
        cout << item << " ";
    cout << endl;
}

int main() {
    int i;
    cin >> i;
    vector<string> c(i);
    for (auto &item : c)
        cin >> item;
    sort(begin(c), end(c), [](string x, string y) {
        for (int j = 0; j < y.size(); ++j) {
            if (x[j] >= 'A' && x[j] <= 'Z')
                x[j] += 32;
            if (y[j] >= 'A' && y[j] <= 'Z')
                y[j] += 32;
        }
        return x < y;
    });
    ft_print(c);
    return 0;
}
