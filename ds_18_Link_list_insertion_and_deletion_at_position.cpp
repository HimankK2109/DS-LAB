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

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

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

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {
    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
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
    else
    {
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

    Node* head = node1; 
    Node* tail = node1;

    
    cout<<"Initially Linked List"<<endl;
    print(head);

    cout<<"Linked List after insertion at tail"<<endl;
    insertAtTail(tail, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);

    cout<<"Linked List after insertion at 2nd Position"<<endl;
    insertAtPosition(tail,head, 2, 22);
    print(head);

    cout<<"Linked List after insertion at 4th Position"<<endl;
    insertAtPosition(tail,head, 4, 68);
    print(head);

    cout<<"Linked List after deletion at 2nd Position"<<endl;
    deleteNode(2,head);
    print(head);

    cout<<"Linked List after deletion at 4th Position"<<endl;
    deleteNode(4,head);
    print(head);
    
    return 0;
}