#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> sumMat(vector<vector<int>>& mat1,vector<vector<int>>& mat2){
    vector<vector<int>> sum(3,vector<int>(3,0));
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return sum;
}

vector<vector<int>> readMat(){
    vector<vector<int>> mat(3,vector<int>(3,0));
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin>>mat[i][j];
        }
    }
    return mat;
}

void printMat(vector<vector<int>>& mat){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> mat1 = readMat();
    vector<vector<int>> mat2 = readMat();
    vector<vector<int>> sum = sumMat(mat1,mat2);
    printMat(sum);
    return 0;
}