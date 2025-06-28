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
Node* insertTail(Node* head, int val){
    if (head == NULL){
        return new Node(val);
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        temp->next = newNode;
    }
    return head;
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
    cout<<"before adding new tail:"<<endl;
    printList(head);

    head = insertTail(head,99);
    cout<<"new list after adding tail:"<<endl;
        printList(head);


    return 0;
}