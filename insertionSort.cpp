#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a = {30,10,40,20,50};
    for(int i = 1;i < a.size();i++){
        int temp = a[i];
        int j=i-1;
        while(j>=0 && temp<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    cout<<"After sorting"<<endl;
    for(int i = 0;i < a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}