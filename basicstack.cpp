#include <iostream>
using namespace std;
int stack[100]; 
int top= -1;     
void push(int x) {
    if (top >=100) {
        cout << "Stack Overflow";
    } 
    else {
        top++;
        stack[top] = x;
    }
}
void pop() {
    if (top == -1) {
        cout << "Stack Underflow";
    } 
    else {
        cout << stack[top] << "popped";
        top--;
    }
}
int main()
{
    push(3);
    push(2);
    push(7);
    push(8);
    push(9);
    push(4);
    pop();
    
}