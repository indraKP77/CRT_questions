#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums(5,0);
    cout<<"Enter elements"<<endl;
    for(int i = 0;i < 5;i++){
        cin>>nums[i];
    }
    int key;
    cout<<"Enter key"<<endl;
    cin>>key;
    for(int i = 0;i < 5;i++){
        if(nums[i] == key){
            cout<<"Key found at position "<<i<<endl;
            return 0;
        }
    }
    cout<<"Key not found"<<endl;
    return 0;
}