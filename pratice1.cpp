// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};
//insert at head
Node* insertHead(Node* head , int val){
    Node* newNode = new Node(val);
    if(head == NULL) return newNode;
    newNode->next = head;
    return newNode;
}
//INSERT AT TAIL;
Node* insertTail(Node* head, int val){
    Node* newNode = new Node(val);
    if (head == NULL) return newNode;

    Node* temp = temp;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
// insert at kth pos 
Node* insertKthPos(Node* head , int pos , int val){
    if(pos==0) return insertHead(head,val);
    Node* temp = head;
    for(int i = 0; i<pos-1 && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr) return head;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
void printlist (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}


int main(){
    Node* head = insertHead(head,30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    head->next->next->next = new Node(69);
    cout<<"before operation:"<<endl;
    printlist(head);
    cout<<"\n after operations:"<<endl;
    insertKthPos(head,2,15);
    insertKthPos(head,5,232);
    printlist(head);
return 0;
}






