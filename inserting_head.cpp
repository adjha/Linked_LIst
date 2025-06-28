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

    Node(int val , Node* nextNode){
        data = val;
        next = nextNode;
    }
};

//insert at head
Node* insert_at_Head(Node* head , int val){
    return new Node(val,head);
}

// printing
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){

    Node* head = new Node(30);
    head->next = new Node(40);
    head->next->next = new Node(50);
    cout<<"before adding new head:"<<endl;
    printList(head);

    head = insert_at_Head(head,99);
    cout<<"new list after adding head:"<<endl;
        printList(head);


    return 0;
}