#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    if (fgets(infix, MAX, stdin) == NULL) {
        return 1;
    }

    infix[strcspn(infix, "\n")] = '\0';

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            if (top == -1) {
                printf("Invalid expression!\n");
                return 1;
            }

            pop();
        } else if (c == '+' || c == '-' ||
                   c == '*' || c == '/' || c == '^') {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(c) ||
                   (precedence(stack[top]) == precedence(c)
                    && c != '^'))) {
                postfix[j++] = pop();
            }

            push(c);
        } else {
            printf("Invalid character!\n");
            return 1;
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Unbalanced parentheses!\n");
            return 1;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
