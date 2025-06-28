#include<iostream>
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

//INSERT AT HEAD
Node* insertAtHEAD(Node* head , int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}
//INSERT AT TAIL
Node* insertAtTAIL(Node* head, int val){
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//INSERT AT ANY POSTION
Node* insertatPost(Node* head , int pos,int val){
    if (pos == 0) return insertAtHEAD(head,val);
    
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

//PRINTING
void printlist (Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}


int main(){
    Node* head = insertAtHEAD(head,30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    head->next->next->next = new Node(69);
    cout<<"before operation:"<<endl;
    printlist(head);
    cout<<"\n after operations:"<<endl;
    insertatPost(head,2,15);
    insertatPost(head,5,232);
    printlist(head);



    return 0;
}