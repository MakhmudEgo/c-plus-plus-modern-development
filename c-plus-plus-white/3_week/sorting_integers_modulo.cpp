#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void    ft_print(const vector<int> &n) {
    for (auto &item : n)
        cout << item << " ";
}

int     main(void) {
    int num;
    cin >> num;
    vector<int> nums(num);
    for (auto &n : nums)
        cin >> n;
    sort(begin(nums), end(nums), [](const int &x, const int &y) { return abs(x) < abs(y);});

    ft_print(nums);
    return (0);
}