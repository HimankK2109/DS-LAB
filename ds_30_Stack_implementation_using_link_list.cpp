#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "Stack is empty! Cannot pop element." << endl;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return top->data;
        } else {
            cout << "Stack is empty! Cannot peek element." << endl;
            return -1;
        }
    }
};

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    cout << "Top element after pop: " << stack.peek() << endl;

    int ans = stack.isEmpty();
    if(ans == 1) cout<<"Stack is Empty. "<<endl;
    else cout<<"Stack is not Empty. "<<endl;

    return 0;
}
