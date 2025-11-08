#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = x;
}

void pop() {
    if(top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}

void display() {
    if(top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements:\n");
        for(int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void palindrome() {
    char str[50];
    printf("Enter string: ");
    scanf("%s", str);
    int len = 0;
    while(str[len] != '\0') len++;
    int flag = 1;
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 0; break;
        }
    }
    if(flag) printf("Palindrome\n");
    else printf("Not Palindrome\n");
}

int main() {
    int ch, val;
    while(1) {
        printf("\n1.Push  2.Pop  3.Palindrome  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter element: "); scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: palindrome(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
