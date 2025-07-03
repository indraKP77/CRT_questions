#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr(5,0);
    for(int i = 0; i<5;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<arr[0]<<endl;
    cout<<arr[4]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[3]<<endl;
    return 0;
}