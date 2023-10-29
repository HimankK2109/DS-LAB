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

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

LinkedList mergeSortedLists(LinkedList list1, LinkedList list2) {
    LinkedList result;

    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            result.insert(current1->data);
            current1 = current1->next;
        } else {
            result.insert(current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != nullptr) {
        result.insert(current1->data);
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        result.insert(current2->data);
        current2 = current2->next;
    }

    return result;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    LinkedList list1;
    list1.insert(20);
    list1.insert(10);
    list1.insert(5);

    LinkedList list2;
    list2.insert(15);
    list2.insert(9);
    list2.insert(2);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    LinkedList mergedList = mergeSortedLists(list1, list2);

    cout << "Merged List: ";
    mergedList.display();

    return 0;
}