#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int sum = 0;
    for(int i = 0;i < 5;i++){
        sum+=arr[i];
    }
    cout<<"Sum of elements = "<<sum<<endl;
    cout<<"Average of elements = "<<sum/5.0<<endl;
    return 0;
}