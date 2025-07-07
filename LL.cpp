#include<iostream>
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
};

int main(){
    List l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();
    return 0;
}