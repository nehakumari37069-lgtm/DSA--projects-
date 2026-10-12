#include <stdio.h>

#define MAX 100

int q1[MAX], q2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

void push(int value) {
    int i;

    if (rear1 == MAX - 1) {
        printf("Stack is full!\n");
        return;
    }

    q2[++rear2] = value;

    while (front1 <= rear1) {
        q2[++rear2] = q1[front1++];
    }

    for (i = 0; i <= rear2; i++) {
        q1[i] = q2[i];
    }

    front1 = 0;
    rear1 = rear2;

    front2 = 0;
    rear2 = -1;

    printf("%d pushed\n", value);
}

void pop() {
    if (front1 > rear1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Popped element: %d\n", q1[front1++]);

    if (front1 > rear1) {
        front1 = 0;
        rear1 = -1;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push  2.Pop  3.Exit");
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
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
