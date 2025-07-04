#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;//Leetcode Next Greater Element and Next Greater Element 2
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int miss = 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - nums[i - 1] != 1)
        {
            miss = nums[i - 1] + 1;
        }
    }
    cout << miss << endl;
    return 0;
}