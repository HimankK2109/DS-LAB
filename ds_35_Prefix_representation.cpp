#include <iostream>
#include <stack>
using namespace std;

int evaluatePrefix(string expr) {
    stack<char> operators;
    stack<int> operands;

    for (int i = expr.size() - 1; i >= 0; i--) {
        char ch = expr[i];
        if (isdigit(ch)) {
            operands.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        int operand1 = operands.top();
        operands.pop();
        int operand2 = operands.top();
        operands.pop();

        int result;
        switch (op) {
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

    return operands.top();
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    string expr = "* + 5 4 - 7 2"; // Represents the expression: (5 + 4) * (7 - 2)

    cout << "Prefix Notation: " << expr << endl;

    string infixExpr = "";
    for (char ch : expr) {
        if (isdigit(ch)) {
            infixExpr += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            infixExpr = "(" + infixExpr + ch;
        }
    }
    infixExpr += ')';
    cout << "Infix Notation: " << infixExpr << endl;

    int result = evaluatePrefix(expr);

    cout << "Result: " << result << endl;

    return 0;
}