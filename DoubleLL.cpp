#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class List{
    public:
    Node* head;Node* tail;
    List(){
        head = tail = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void display(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void reverseUseHead() {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* temp;
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        prev = curr;
        curr = curr->prev;
    }
    head = prev;
}

void displayReverse(Node* temp){
    if(temp == NULL){
        return;
    }
    cout<<temp->data<<" ";
    displayReverse(temp->prev);
}


void addAtPos(int pos,int val){
    if(pos == 1){
        insert(val);
        return;
    }
    Node* curr = head;
    Node* nex = NULL;
    while(pos>2){
        pos--;
        curr = curr->next;
        nex = curr->next;
    }
    Node* newNode = new Node(val);
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = nex;
    nex->prev = newNode;
}

};

int main(){
    List l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();
    cout<<endl;
    l1.addAtPos(3,25);
    l1.display();
    return 0;
}