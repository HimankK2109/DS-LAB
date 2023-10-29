#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue element." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }

        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek element." << endl;
            return -1;
        }

        return front->data;
    }
};

int main() {
    Queue queue;
    cout<<"Himank Kumar C0/206"<<endl;
    
    queue.enqueue(23);
    queue.enqueue(75);
    queue.enqueue(49);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.peek() << endl;

    int ans = queue.isEmpty();
    if(ans == 1) cout<<"Queue is Empty. "<<endl;
    else cout<<"Queue is not Empty. "<<endl;

    return 0;
}
