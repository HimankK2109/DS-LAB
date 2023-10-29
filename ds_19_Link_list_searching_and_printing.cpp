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

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
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

    // Insert some values
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

    // Display the linked list
    cout << "Linked List: ";
    list.display();

    int searchValue = 10;
    if (list.search(searchValue)) {
        cout << searchValue << " is found in the linked list." << endl;
    } else {
        cout << searchValue << " is not found in the linked list." << endl;
    }

    return 0;
}