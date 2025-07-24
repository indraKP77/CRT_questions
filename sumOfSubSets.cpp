#include<iostream>
#include<vector>
using namespace std;

void sumOfSubSets(vector<int>& nums,int idx,vector<int>& combin,int target,vector<vector<int>>& res){
    if(target == 0){
        res.push_back(combin);
        return;
    }
    if(idx == nums.size() || target<0){
        return;
    }
    combin.push_back(nums[idx]);
    sumOfSubSets(nums,idx+1,combin,target-nums[idx],res);
    combin.pop_back();
    sumOfSubSets(nums,idx+1,combin,target,res);
}

int main(){
    vector<int> nums = {3,4,5,2};
    vector<vector<int>> res;
    vector<int> combin;
    int target = 9;
    sumOfSubSets(nums,0,combin,target,res);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}