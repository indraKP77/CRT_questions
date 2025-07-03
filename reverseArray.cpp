#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr(5,0);
    for(int i = 0;i<5;i++){
        cin>>arr[i];
    }
    int st = 0;int end = 4;
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<"->";
    }
    return 0;
}