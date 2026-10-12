#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed into stack\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Popped element: %d\n", stack[top--]);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push  2.Pop  3.Peek");
        printf("\n4.isEmpty  5.isFull  6.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                printf(isEmpty() ? "Stack is empty\n"
                                 : "Stack is not empty\n");
                break;

            case 5:
                printf(isFull() ? "Stack is full\n"
                                : "Stack is not full\n");
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
