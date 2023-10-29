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

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
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

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    LinkedList list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

    // Display original linked list
    cout << "Original Linked List: ";
    list.display();

    // Reverse the linked list
    list.reverse();

    // Display reversed linked list
    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}