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

// Deleting head
Node* del_head(Node* head){
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
 Node* head = new Node(30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    cout<<"original Linked List:";
    Node* temp = head;
    while(temp != nullptr){
      cout<<temp->data<<" ";
      temp = temp ->next;
    }
    cout<<endl;
    
    head = del_head(head); //calling deleteion function 
    cout<<"deleted head Linked List:";
    temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }


    return 0;
}