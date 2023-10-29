#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    //created a new node
    Node* node1 = new Node(10);

    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;

    cout<<"Initially Linked List"<<endl;
    print(head);

    cout<<"Linked List after insertion at tail"<<endl;
    insertAtTail(tail, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);

    deleteNode(3,head);
    cout<<"Linked List after deletion at tail"<<endl;
    print(head);
    
    return 0;
}