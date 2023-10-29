#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

void insertNode(Node* &tail, int element, int d) {
    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}    

void print(Node* tail) {

    Node* temp = tail;
    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    Node* tail = NULL;

    cout<<"Inserting first element: ";
    insertNode(tail, 5, 3);
    print(tail);

    cout<<"Inserting element after 3: ";
    insertNode(tail, 3, 5);
    print(tail);

    cout<<"Inserting element after 3: ";
    insertNode(tail, 3, 8);
    print(tail);

    cout<<"Inserting element after 5: ";
    insertNode(tail, 5, 10);
    print(tail);

    cout<<"Deleting node with vakue 5: ";
    deleteNode(tail, 5);
    print(tail);

    return 0;
}