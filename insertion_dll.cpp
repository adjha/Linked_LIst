#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* prev;
Node* next;
Node(int val){
    data = val;
    prev = NULL;
    next = NULL;
}
};
//INSERTING AT HEAD
void insert_at_Head(Node* &head , int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}
// INSERTING AT TAIL
void insert_at_Tail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
//INSERTING AT KTH POSITION
void insert_at_pos(Node* &head , int pos , int val){
// case 1: insert at head
if(pos == 1){
    insert_at_Head(head,val);
    return;
}
Node* temp = head;
int count = 1;
while(temp != NULL && count<pos-1){
    temp = temp->next;
    count++;
}
// case 2: insertion at tail
if(temp == NULL || temp->next == NULL){
    insert_at_Tail(head,val);
    return;
}
Node* n = new Node(val);
n->next = temp->next;
temp->next->prev = n;
temp->next = n;
n->prev = temp;
}

//print forward
void printForward(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//PRINT BACKWARD
void printBackward(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    insert_at_Head(head, 10);
    insert_at_Tail(head, 20);
    insert_at_Tail(head, 30);
    insert_at_pos(head, 2, 15);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(head);



    return 0;
}