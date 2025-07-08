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
    Node* head;Node* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    void display(){
        Node* temp = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while(temp!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void reverse(){
        Node* tempHead = head;
        tail->next = NULL;
        Node* curr = head;
        Node* prev = NULL;
        Node* nex = NULL;
        while(curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
        tempHead->next = prev;
    }
};

int main(){
    List l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.display();
    l1.reverse();
    cout<<endl;
    l1.display();
    return 0;
}