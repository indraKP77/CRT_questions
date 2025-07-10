#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {3,5,2,6,7,8};
    for(int i = 0;i < nums.size();i++){
        for(int j = i+1;j < nums.size();j++){
            if(nums[j]<nums[i]){
                swap(nums[j],nums[i]);
            }
        }
    }
    cout<<"Sorted array"<<endl;
    for(int i = 0;i < nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}