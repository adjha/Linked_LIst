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

//DELETE HEAD
Node* del_Head(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

//DELETE TAIL
Node* del_Tail(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
// DELETE AT KTH{ANY} POSITION
Node* del_kth(Node* head, int k){
    if(head == NULL || k<0) return NULL;

    //case 1 : when K == 0 // head
    if(k==0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    Node* prev = nullptr;
    int count = 0;
    while(curr != nullptr && count < k){
        prev = curr;
        curr = curr->next;
        count++;
    }
    // check out of bound
    if(curr == nullptr) return head;

    prev->next = curr->next;
    delete curr;
    return head;
}
// PRINTING THE LINKED LIST
void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main() {
    // Create a sample linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

     cout << "Original List: ";
    printLL(head);

    int k = 2;
    del_kth(head,k);

    cout<<"\nafter deletion at kth position:"<<endl;
     printLL(head);


    return 0;
}
