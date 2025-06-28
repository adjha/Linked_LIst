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
Node* remove_el(Node* head, int el){
    // head
    if(head==NULL) return head;
    if(head->data == el){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
    }
   //non-head
    Node* curr = head;
    Node* prev = NULL;
    while(curr != nullptr){
        if(curr->data == el){
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list:\n";
    printLL(head);

    int el = 20;
    head = remove_el(head,el);

    cout << "After deleting value " << el << ":\n";
    printLL(head);

    return 0;
}
