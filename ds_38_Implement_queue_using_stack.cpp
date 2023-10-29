#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void shiftStacks() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        shiftStacks();
        int result = outputStack.top();
        outputStack.pop();
        return result;
    }

    int peek() {
        shiftStacks();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Output: 1

    q.pop();

    cout << "Front element after pop: " << q.peek() << endl; // Output: 2

    q.pop();
    q.pop();

    if (q.empty()) {
        cout << "Queue is empty." << endl; // Output: Queue is empty.
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}