#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node *head,*tail;
    public:
    List(){
        head = tail = NULL;
    }
    void insertATBeg(int val){
        if(head == NULL){
            Node* newNode = new Node(val);
            head = newNode;
        }
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL && tail == NULL){

            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
    void reverse() {
    Node* curr = head;
    Node* prev = NULL;
    Node* nex = NULL;

    while (curr != NULL) {
        nex = curr->next;   
        curr->next = prev; 
        prev = curr;       
        curr = nex;         
    }

    head = prev;  
}

void insertAtEnd(int val){
    Node* newNode = new Node(val);
    if(tail == NULL){
        tail = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    tail = newNode;
}
void insertAtPos(int val,int pos){
    if(pos == 1){
        insertATBeg(val);
        return;
    }
    Node* temp = head;
    while(pos!=0){
        pos--;
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->next = temp2;
}

bool cycle(){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void helper(Node* temp){
    if(temp == NULL){
        return;
    }
    cout<<temp->data<<" ";
    helper(temp->next);
}

void display1(){
    Node* temp =head;
    cout<<temp->data<<" ";
    helper(temp->next);
}

void deleteDup(){
    Node* temp = head;
    while(temp!=NULL){
        Node* nextNode = temp->next;
        while(nextNode!=NULL && temp->data == nextNode->data){
            Node* dup = nextNode;
            nextNode = nextNode->next;
            delete(dup);
        }
        temp->next = nextNode;
        temp = temp->next;
    }
}

void deleteAtBeg(){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete(temp);
}

void delAtEnd(){
    if(tail == NULL){
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete(temp);
    tail = prev;
}

void delSpecPos(int pos) {
    if (head == NULL || pos <= 0) {
        cout << "Invalid position or empty list" << endl;
        return;
    }

    if (pos == 1) {
        deleteAtBeg();
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void removeCycle() {
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            prev->next = NULL;
            return;
        }
        mpp[temp] = 1;
        prev = temp;
        temp = temp->next;
    }
}


};
int main(){
    List l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(7);
    l1.display1();
    l1.delSpecPos(3);
    cout<<endl;
    l1.display1();
    return 0;
}