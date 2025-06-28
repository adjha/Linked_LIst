#include<iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// 🔹 Delete at head
Node* del_head(Node* &head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    return head;
}
// Delete Tail Elements
Node* del_Tail(Node* &head)
{
    if(head == NULL) return NULL;

    //assume only one element
    if(head->next == NULL){
        delete head;
        head = NULL;
        return head;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
    return head;
    
}
// DELETE AT GIVEN{KTH} POSITION
 Node* del_kthPos(Node* &head , int k){
    if(head == NULL && k <= 0) return NULL;

    if(k == 1) return del_head(head);

    Node* temp = head;
    int count = 1;
    while(temp != NULL && count < k){
        temp = temp->next;
        count++;
    }
    // Position out of bound
    if(temp == NULL) return head;

    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
    return head;
 }
// 🔹 Print the list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50,90,80,789};
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < arr.size(); i++) {  
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;   
        temp = newNode;
    }

    cout << "Before the deletion of kth position: ";
    print(head);

    del_kthPos(head,2);

    cout << "After the deletion of kth position: ";
    print(head);

    


    return 0;
}
