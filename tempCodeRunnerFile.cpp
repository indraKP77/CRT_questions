#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> nums = {1,2,3,4,1,2};
    unordered_map<int,int> mpp;
    for(int i = 0;i<nums.size();i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        cout<<"Element "<<it.first<<"Frequency "<<it.second<<endl;
    }
    return 0;
}