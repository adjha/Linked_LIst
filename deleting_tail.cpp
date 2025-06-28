#include <iostream>
using namespace std;
class Node {
  public:
  int data;
  Node* next;
  
  Node(int val){
    data = val;
    next = nullptr;
  }
};
Node* del_tail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp -> next = nullptr;
    return head;
}
int main () {

    Node* head = new Node(30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    head->next->next->next = new Node(60);

    cout<<"original Linked List:";
    Node* temp = head;
    while(temp != nullptr){
      cout<<temp->data<<" ";
      temp = temp ->next;
    }
    cout<<endl;

    head = del_tail(head);

     cout<<"deleted Tail Linked List:";
    temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}