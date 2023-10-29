#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void setNext(Node* nextNode) {
        head = nextNode;
    }

    Node* getHead() {
        return head;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

Node* findMergePoint(Node* headA, Node* headB) {
    Node* currentA = headA;
    Node* currentB = headB;

    while (currentA != currentB) {
        currentA = (currentA == nullptr) ? headB : currentA->next;
        currentB = (currentB == nullptr) ? headA : currentB->next;
    }

    return currentA;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    LinkedList listA;
    listA.insert(5);
    listA.insert(10);
    listA.insert(15);

    LinkedList listB;
    listB.insert(20);

    Node* commonNode = new Node(25);
    listA.setNext(commonNode);
    listB.setNext(commonNode);

    cout << "Linked List A: ";
    listA.display();

    cout << "Linked List B: ";
    listB.display();

    Node* mergePoint = findMergePoint(listA.getHead(), listB.getHead());

    if (mergePoint != nullptr) {
        cout << "Merge Point Value: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}