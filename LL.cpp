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

};
int main(){
    List l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.reverse();
    l1.display();
    bool isCycle = l1.cycle();
    if(isCycle){
        cout<<"\nThere is a cycle"<<endl;
    }
    else{
        cout<<"\nNo cycle"<<endl;
    }
    return 0;
}