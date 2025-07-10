#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums(7,0);
    cout<<"Enter elements"<<endl;
    for(int i = 0;i < 7;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    cout<<"Enter key"<<endl;
    int key;
    cin>>key;
    int st = 0;
    int end = nums.size()-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(nums[mid] == key){
            cout<<"Key found at "<<mid<<endl;
            return 0;
        }
        else if(nums[mid]<key){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<"Element not found"<<endl;
    return 0;
}