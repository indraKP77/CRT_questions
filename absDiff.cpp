#include<iostream>
#include<vector>
using namespace std;

vector<int> getAbsDiff(vector<int>& nums,int num,int diff){
    vector<int> res;
    for(int i = 0;i<nums.size();i++){
        if(abs(nums[i]-num)<=diff){
            res.push_back(nums[i]);
        }
    }
    return res;
}

int main(){
    vector<int> nums(6,0);
    for(int i = 0;i<6;i++){
        cin>>nums[i];
    }
    int num = 13;
    int diff = 2;
    vector<int> result = getAbsDiff(nums,num,diff);
    cout<<result.size();
    return 0;
}