#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums, int st, int mid, int end) {
    vector<int> temp;
    int left = st, right = mid + 1;
    while (left <= mid && right <= end) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= end) {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = 0; i < temp.size(); ++i) {
        nums[st + i] = temp[i];
    }
}

void mergeSort(vector<int>& nums, int st, int end) {
    if (st >= end) {
        return;
    }
    int mid = st + (end - st) / 2;
    mergeSort(nums, st, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, st, mid, end);
}

int main() {
    vector<int> nums = {60, 40, 30, 50, 10, 20};
    int end = nums.size() - 1;
    mergeSort(nums, 0, end);

    cout << "Sorted Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
