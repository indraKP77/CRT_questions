#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        right = left = NULL;
    }
};

Node* insert(Node* root,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

Node* buildBST(vector<int>& arr){
    Node* root = NULL;
    for(int data:arr){
        root = insert(root,data);
    }
    return root;
}

int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    return 1 + max(lh,rh);
}

void zigzagLevelOrder(Node* root){
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        while(n--){
            Node* front = q.front();
            q.pop();
            level.push_back(front->data);
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        result.push_back(level);
    }
    for(int i = 0;i < result.size();i++){
        if(i%2 == 0){
            for(int j = 0;j < result[i].size();j++){
                cout<<result[i][j]<<" ";
            }
        }
        else{
                for(int j = result[i].size()-1;j>=0;j--){
                    cout<<result[i][j]<<" ";
                }
            }
            cout<<endl;
    }
}

Node* getIS(Node* root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(key<root->data){
        root->left = delNode(root->left,key);
    }
    else if(key>root->data){
        root->right = delNode(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS = getIS(root->right);
            root->data = IS->data;
            root->right = delNode(root->right,IS->data);
        }
    }
    return root;
}

int maxValue(Node* root) {
    if (root == NULL) {
        return -1;
    }
    Node* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr->data;
}

void leftView(Node* root){
    queue<Node*> q;
    vector<vector<int>> res;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        while(n--){
            Node* front = q.front();
            q.pop();
            level.push_back(front->data);
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        res.push_back(level);
    }
    for(int i = 0;i < res.size();i++){
        cout<<res[i][0]<<" ";
    }
}

bool search(Node* root,int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}


int main(){
    vector<int> arr = {27,14,35,10,19,31,42};
    Node* root =  buildBST(arr);
    root = delNode(root,14);
    inorder(root);
    return 0;
}