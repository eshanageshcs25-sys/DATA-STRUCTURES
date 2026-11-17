#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void createList(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertLeft(struct Node** head, int targetVal, int newData) {
    if (*head == NULL) {
        printf("List is empty. Cannot find target node %d.\n", targetVal);
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target value %d not found in the list.\n", targetVal);
        return;
    }
    struct Node* newNode = createNode(newData);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev == NULL) {
        *head = newNode;
    } else {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
    printf("Inserted %d to the left of %d.\n", newData, targetVal);
}
void deleteByValue(struct Node** head, int targetVal) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != targetVal) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", targetVal);
        return;
    }
    if (temp == *head) {
        *head = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted node with value %d.\n", targetVal);
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, n, i, val, target;
    while (1) {
        printf("\n--- DOUBLY LINKED LIST OPERATIONS ---\n");
        printf("1. Create / Add nodes to Doubly Linked List\n");
        printf("2. Insert a new node to the left of a specific node\n");
        printf("3. Delete a node based on a specific value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("How many nodes do you want to add? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &val);
                    createList(&head, val);
                }
                break;
            case 2:
                printf("Enter the target node value (insert to its left): ");
                scanf("%d", &target);
                printf("Enter the new value to insert: ");
                scanf("%d", &val);
                insertLeft(&head, target, val);
                break;
            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &val);
                deleteByValue(&head, val);
                break;
            case 4:
                printf("Doubly Linked List: ");
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
