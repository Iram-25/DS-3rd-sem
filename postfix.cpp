#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack overflow\n";
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        cout << "Stack underflow\n";
        return -1;
    }
    return stack[top--];
}

int main() {
    char exp[100];
    cout << "Enter postfix expression (single digit only): ";
    cin >> exp;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop();
            int a = pop();
            int result;

            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            else if (b != 0) result = a / b;
            else {
                cout << "Error: Division by zero.\n";
                return 1;
            }

            push(result);
        }
    }

    if (top != 0) {
        cout << "Error: Invalid postfix expression.\n";
        return 1;
    }

    cout << "Result = " << pop() << endl;
    return 0;
}
