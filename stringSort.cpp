#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMax(unordered_map<int,int>& mpp){
    int max = 0;int maxPos = 0;
    for(auto it: mpp){
        if(it.second>max){
            max = it.second;
            maxPos = it.first;
        }
    }
    mpp.erase(maxPos);
    return maxPos;
}

int main(){
    vector<string> str;
    int n;
    cout<<"Enter no. of strings"<<endl;
    cin>>n;
    string s;
    for(int i = 0;i < n;i++){
        cin>>s;
        str.push_back(s);
    }
    unordered_map<int,int>  mpp;
    for(int i = 0;i < str.size();i++){
        mpp[i] = str[i].size();
    }
    vector<string> str1;
    for(int i = 0;i < n;i++){
        int max = findMax(mpp);
        str1.push_back(str[max]);
    }
    for(int i = 0;i < n;i++){
        cout<<str1[i]<<" "<<endl;
    }
    return 0;
}