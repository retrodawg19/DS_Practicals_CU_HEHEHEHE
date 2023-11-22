#include <iostream>
#include <string>
#define MAX 5
using namespace std;

void push(int, int[], int&);
int pop(int[], int&);
void palindrome(int[], int);
void display(int[], int);

int main() {
    int stack[MAX];
    int top = -1;
    int choice, e;
    while(true) {
        cout << "Enter choice (1 for push, 2 for pop, 3 for palindrome check, 4 for display): ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> e;
                push(e, stack, top);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                palindrome(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                cout << "Invalid choice" << endl;
                exit(1);
        }
    }
    return 0;
}

void push(int e, int stack[], int& top) {
    if (top == MAX - 1) {
        cout << "Push not possible. Stack is full." << endl;
    } else {
        top++;
        stack[top] = e;
        cout << "Element pushed successfully." << endl;
    }
}

int pop(int stack[], int& top) {
    if (top == -1) {
        cout << "Pop not possible. Stack is empty." << endl;
        return -1;
    } else {
        int item = stack[top];
        top--;
        cout << "Popped element: " << item << endl;
        return item;
    }
}

void palindrome(int stack[], int top) {
    int flag = 1;
    for (int i = 0, j = top; i < top / 2; i++, j--) {
        if (stack[i] != stack[j]) {
            flag = 0;
            break;
        }
    }
    
    if (flag) {
        cout << "It is a palindrome." << endl;
    } else {
        cout << "It is not a palindrome." << endl;
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << endl;
 }}
}
