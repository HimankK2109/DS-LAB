#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> operands;

    for (char ch : expr) {
        if (isdigit(ch)) {
            operands.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    string expr = "54+72-*"; // Represents the expression: (5 + 4) * (7 - 2)

    cout << "Postfix Notation: " << expr << endl;

    string infixExpr = "";
    for (char ch : expr) {
        if (isdigit(ch)) {
            infixExpr += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            infixExpr = "(" + infixExpr;
            infixExpr += ch;
            infixExpr += ")";
        }
    }
    cout << "Infix Notation: " << infixExpr << endl;

    int result = evaluatePostfix(expr);

    cout << "Result: " << result << endl;

    return 0;
}