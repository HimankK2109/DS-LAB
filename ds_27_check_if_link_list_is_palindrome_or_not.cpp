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

    bool isPalindrome() {
        LinkedList reversedList;
        Node* current = head;

        while (current != nullptr) {
            reversedList.insert(current->data);
            current = current->next;
        }

        Node* original = head;
        Node* reversed = reversedList.head;

        while (original != nullptr && reversed != nullptr) {
            if (original->data != reversed->data) {
                return false;
            }
            original = original->next;
            reversed = reversed->next;
        }

        return true;
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
    LinkedList list;
    cout<<"Himank Kumar C0/206"<<endl;
    // Insert some values
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Linked List: ";
    list.display();

    list.reverse();
    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
