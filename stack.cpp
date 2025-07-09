#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
    string s = "Indra";
    stack<char> rev;
    for(int i = 0;i < s.size();i++){
        if(i == s.size()/2){
            continue;
        }
        else{
            rev.push(s[i]);
        }
    }
    string ans = "";
    while(!rev.empty()){
        ans = ans + rev.top();
        rev.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}