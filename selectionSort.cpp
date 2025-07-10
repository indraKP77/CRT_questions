#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {5,3,8,6,7,2};
    for(int i = 0;i < nums.size();i++){
        int minIdx = i;
        for(int j = i+1;j < nums.size();j++){
            if(nums[j]<nums[minIdx]){
                minIdx = j;
            }
        }
        swap(nums[minIdx],nums[i]);
    }
    for(int i = 0;i < nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}