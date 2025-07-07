#include<iostream>
using namespace std;

int main(){
    int a[] = {8,18,28,38,48};
    int *ptr = NULL;
    --ptr;
    --*ptr;
    ++ptr;
    ++*ptr;
    cout<<ptr[0];
    return 0;
}