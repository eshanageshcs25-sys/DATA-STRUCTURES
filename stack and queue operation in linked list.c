#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed (Overflow)!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped %d from the stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
}
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        // Queue is initially empty
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued %d into the queue.\n", data);
}
void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    printf("Dequeued %d from the queue.\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

// Display Queue
void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue (Front to Rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ============================================================================
   MAIN MENU
   ============================================================================ */

int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, val;

    while (1) {
        printf("\n--- SINGLY LINKED LIST: STACK & QUEUE SIMULATION ---\n");
        printf("1. Stack: Push\n");
        printf("2. Stack: Pop\n");
        printf("3. Stack: Display\n");
        printf("4. Queue: Enqueue\n");
        printf("5. Queue: Dequeue\n");
        printf("6. Queue: Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&stackTop, val);
                break;

            case 2:
                pop(&stackTop);
                break;

            case 3:
                displayStack(stackTop);
                break;

            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&queueFront, &queueRear, val);
                break;

            case 5:
                dequeue(&queueFront, &queueRear);
                break;

            case 6:
                displayQueue(queueFront);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
