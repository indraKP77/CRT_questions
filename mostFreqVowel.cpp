#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    unordered_map<char,int> mpp;
    for(int i = 0;i < s.size();i++){
            mpp[s[i]]++;
    }
    char ch = ' ';int maxCount = 0;
    for(auto it:mpp){
        if(it.second>maxCount){
            maxCount = it.second;
            ch = it.first;
        }
        else if(it.second == maxCount){
            if(it.first - 'a' < ch - 'a'){
                ch = it.first;
            }
        }
        else{
            continue;
        }
    }
    char rep;
    cout<<"Enter character to replace"<<endl;
    cin>>rep;
    for(int i = 0;i < s.size();i++){
        if(s[i] == ch){
            s[i] = rep;
        }
    }
    cout<<"Replaced string is "<<s;
    return 0;
}