#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push element." << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop element." << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek element." << endl;
            return -1;
        }
        return arr[top];
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
