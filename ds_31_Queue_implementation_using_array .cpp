#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue element." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue element." << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek element." << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    Queue queue;

    queue.enqueue(50);
    queue.enqueue(40);
    queue.enqueue(85);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.peek() << endl;

    int ans = queue.isEmpty();
    if(ans == 1) cout<<"Queue is Empty. "<<endl;
    else cout<<"Queue is not Empty. "<<endl;
    return 0;
}
