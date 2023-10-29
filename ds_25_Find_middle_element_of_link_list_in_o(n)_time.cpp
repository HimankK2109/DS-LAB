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

    Node* findMiddle() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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

    // Inserting some values
    list.insert(34);
    list.insert(12);
    list.insert(15);
    list.insert(89);
    list.insert(99);

    // Find the middle of the linked list
    Node* middleNode = list.findMiddle();

    cout << "Linked List: ";
    list.display();

    if (middleNode != nullptr) {
        cout << "Middle Node Value: " << middleNode->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
