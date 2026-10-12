#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX], stack[MAX];
    int top = -1, i;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        stack[++top] = str[i];
    }

    printf("Reversed string: ");

    while (top != -1) {
        printf("%c", stack[top--]);
    }

    printf("\n");

    return 0;
}
