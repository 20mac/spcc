#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to generate three address code for an expression
void generateThreeAddressCode(string expression) {
    stack<char> operatorStack;
    stack<string> operandStack;
    string operand1, operand2, result;
    char op;

    for (int i = 0; i < expression.length(); i++) {
        if (isOperator(expression[i])) {
            op = expression[i];

            // Pop two operands and one operator from the stacks
            operand2 = operandStack.top();
            operandStack.pop();
            operand1 = operandStack.top();
            operandStack.pop();

            result = "t" + to_string(i); // Generate temporary variable
            operandStack.push(result); // Push result onto operand stack

            // Generate three address code for the operation
            cout << result << " = " << operand1 << " " << op << " " << operand2 << endl;
        }
        else {
            // Push operands onto operand stack
            operandStack.push(string(1, expression[i]));
        }
    }

    // Print final result
    cout << "Result = " << operandStack.top() << endl;
}

int main() {
    string expression;

    do {
        cout << "Enter an arithmetic expression (or press Enter to exit): ";
        getline(cin, expression);

        if (!expression.empty()) {
            generateThreeAddressCode(expression);
            cout << endl;
        }
    } while (!expression.empty());

    return 0;
}
