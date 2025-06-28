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
Node* delete_k(Node* head,int k){
    // Head deleting
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    int cnt = 1;
    Node* temp = head;

    // Traverse to (k-1)th node
    while(temp != nullptr && cnt<k-1){
        temp = temp->next;
        cnt++;
    }

    // If position is invalid
    if(temp==nullptr || temp->next == nullptr){
        cout<<"postion out of bounds";
        return head;
    }

    // delete kth node
    Node* node_to_del = temp->next;
    temp->next = temp->next->next;
    delete node_to_del;

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
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list:\n";
    printLL(head);

    int k = 3;
    head = delete_k(head,k);

    cout << "After deleting position " << k << ":\n";
    printLL(head);

    return 0;
}