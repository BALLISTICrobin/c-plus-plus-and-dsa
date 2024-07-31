#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            int result = 1;
            while (operand2 != 0) {
                result *= operand1;
                --operand2;
            }
            return result;
        default:
            return 0;
    }
}

int evaluateInfixExpression(string expression) {
    stack<int> operands;
    stack<char> operators;
    
    for (char& c : expression) {
        if (isspace(c))
            continue;
        
        if (isdigit(c)) {
            stringstream ss;
            ss << c;
            int num;
            ss >> num;
            operands.push(num);
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = performOperation(operand1, operand2, op);
                operands.push(result);
            }
            
            // Pop the opening parenthesis
            operators.pop();
        }
        else {
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = performOperation(operand1, operand2, op);
                operands.push(result);
            }
            
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        int result = performOperation(operand1, operand2, op);
        operands.push(result);
    }
    
    return operands.top();
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    
    int result = evaluateInfixExpression(expression);
    cout << "Result: " << result << endl;
    
    return 0;
}
