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

int lenthOfLL(Node* head){
  int cnt = 0;
  Node* temp = head;
    while(temp != nullptr){
      temp = temp ->next;
      cnt++;
    }
    return cnt;
}
//searching value in the Linked List
int searchval(Node* head, int val){
  Node* temp = head;
    while(temp != nullptr){
      if(temp->data == val) return 1;
      temp = temp ->next;
     
    }
    return 0;
}


int main() 
{
    Node* head = new Node(30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    
    Node* temp = head;
    while(temp != nullptr){
      cout<<temp->data<<" ";
      temp = temp ->next;
    }
    
    cout<<endl;
    int len = lenthOfLL(head);
    cout<<"length of Linked List:"<<len<<endl;
    
    
    cout<<"value presetn or not:"<<searchval(head,30);
    return 0;
}