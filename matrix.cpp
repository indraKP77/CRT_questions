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

bool identMat(vector<vector<int>>& mat1,vector<vector<int>>& mat2){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(mat1[i][j] != mat2[i][j]){
                return false;
            }
        }
    }
    return true;
}

void upperTri(vector<vector<int>>& mat){
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(i<j){
                cout<<"0 ";
            }
            else{
                cout<<mat[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int sumUpperTri(vector<vector<int>>& mat){
    int sum = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(i<j){
                continue;
            }
            else{
                sum+=mat[i][j];
            }
        }
    }
    return sum;
}

void spiralMat(vector<vector<int>>& matrix){
int m = matrix.size(),n = matrix[0].size();
        int srow = 0,erow = m-1;int scol = 0,ecol = n-1;
        while(srow <= erow && scol <= ecol){
            for(int j = scol;j<=ecol;j++){
                cout<<matrix[srow][j];
            }
            for(int i = srow+1;i<=erow;i++){
                cout<<matrix[i][ecol];
            }
            for(int j=ecol-1;j>=scol;j--){
                if(srow == erow){
                    break;
                }
                cout<<matrix[erow][j];
            }
            for(int i = erow-1;i>=srow+1;i--){
                if(scol == ecol){
                    break;
                }
                cout<<matrix[i][scol];
            }
            srow++;
            scol++;
            erow--;
            ecol--;
        }

}

int diagSum(vector<vector<int>>& mat){
    int sum = 0;
    int i = 0,j =0;
    while(i<3&&j<3){
        sum+=mat[i][j];
        i++;
        j++;
    }
    int k = mat[0].size()-1;
    for(int i = 0;i<mat.size();i++){
        sum += mat[i][k];
        k--;
    }
    return sum - mat[1][1];
}

int main(){
    vector<vector<int>> mat1 = readMat();
    int sum = diagSum(mat1);
    cout<<sum;
    return 0;
}