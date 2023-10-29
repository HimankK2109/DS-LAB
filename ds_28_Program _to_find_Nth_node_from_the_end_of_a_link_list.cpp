#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    Node* findNthFromEnd(int n) {
        if (head == nullptr || n <= 0) {
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;

        // Move the fast pointer ahead by n nodes
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) {
                return nullptr; // List length is less than n
            }
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
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

    // Insert some values
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

    cout << "Linked List: ";
    list.display();

    int n = 2;

    Node* nthNode = list.findNthFromEnd(n);

    if (nthNode != nullptr) {
        cout << "The " << n << "nd node from the end is: " << nthNode->data << endl;
    } else {
        cout << "Invalid input or node not found." << endl;
    }

    return 0;
}
