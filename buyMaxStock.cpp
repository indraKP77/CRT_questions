#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int buyMax(vector<int>& nums, int idx, int target) {
    if (target < 0) return -1e9;
    if (idx == nums.size()) return 0;
    int take = 1 + buyMax(nums, idx, target - nums[idx]);
    int notTake = buyMax(nums, idx + 1, target);

    return max(take, notTake);
}

int main() {
    vector<int> nums = {10, 7, 19};
    int target = 45;

    int count = buyMax(nums, 0, target);
    cout << count << endl;

    return 0;
}
