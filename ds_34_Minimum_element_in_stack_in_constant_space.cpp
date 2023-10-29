#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int value) {
        mainStack.push(value);
        if (minStack.empty() || value <= getMin())
            minStack.push(value);
    }

    void pop() {
        if (mainStack.top() == getMin())
            minStack.pop();
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);

    cout << "Minimum element: " << minStack.getMin() << endl;

    minStack.pop();
    minStack.pop();

    cout << "Minimum element after popping: " << minStack.getMin() << endl;

    return 0;
}
