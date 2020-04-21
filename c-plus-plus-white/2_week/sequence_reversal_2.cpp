#include <iostream>
#include <vector>
using namespace std;

vector<int>     Reversed(const vector<int>& v)
{
    vector<int> reverse_v;
    for (int i = v.size() - 1; i >= 0; i--)
        reverse_v.push_back(v[i]);
    return(reverse_v);
}

int     main(void)
{
    vector<int> nums = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (auto num : nums)
        cout << num << ", ";
    vector<int> nums_reverse = Reversed(nums);
    cout << endl << "After" << endl;
    for (auto num : nums_reverse)
        cout << num << ", ";
    return (0);
}