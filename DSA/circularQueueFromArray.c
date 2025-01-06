c
Copy code
#include <stdio.h>
#define MAX 5

int circularQueue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) { // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    circularQueue[rear] = value;
    printf("%d enqueued into circular queue\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow\n");
        return -1;
    }
    int data = circularQueue[front];
    if (front == rear) { // Single element left
        front = rear = -1;
    } else if (front == MAX - 1) { // Wrap around
        front = 0;
    } else {
        front++;
    }
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", circularQueue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", circularQueue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", circularQueue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printf("Dequeued element: %d\n", dequeue());
    enqueue(60);
    display();
    return 0;
}
