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

    void createCycle(int pos) {
        if (pos < 0 || pos >= length()) {
            cout << "Invalid position for cycle creation." << endl;
            return;
        }

        Node* current = head;
        Node* cycleNode = nullptr;
        int count = 0;

        while (current != nullptr) {
            if (count == pos) {
                cycleNode = current;
            }
            if (current->next == nullptr) {
                current->next = cycleNode;
                break;
            }
            current = current->next;
            count++;
        }
    }

    bool detectCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    void removeCycle() {
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        if (fast == nullptr || fast->next == nullptr) {
            return; // No cycle found
        }

        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = nullptr;
    }

    int length() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
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
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

    cout << "Linked List: ";
    list.display();
    // Create a cycle at position 1 (0-based indexing)
    cout<<"Creating a cycle from last node to 1st node in 0-based indexing: "<<endl;
    list.createCycle(1);

    // Detect and remove the cycle
    if (list.detectCycle()) {
        cout << "Cycle detected." << endl;
        list.removeCycle();
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    cout << "Linked List: ";
    list.display();

    return 0;
}