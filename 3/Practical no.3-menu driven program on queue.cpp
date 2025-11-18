#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % MAX) == front;
}

int isEmpty() {
    return (front == -1);
}

void insert(char x) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty()) {      // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = x;
    printf("Inserted: %c\n", x);
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted: %c\n", queue[front]);
    if (front == rear) { // last element was removed
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch;
    char val;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\nEnter choice: ");
        if (scanf("%d", &ch) != 1) return 0;
        switch (ch) {
            case 1:
                printf("Enter character: ");
                scanf(" %c", &val);
                insert(val);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
