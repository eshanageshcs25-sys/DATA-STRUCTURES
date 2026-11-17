#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data){
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
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to sort.\n");
        return;
    }
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Linked list sorted successfully.\n");
}
void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to reverse.\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Linked list reversed successfully.\n");
}
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, val, n, i;

    while (1) {
        printf("\n--- SINGLY LINKED LIST OPERATIONS ---\n");
        printf("1. Insert element into List 1\n");
        printf("2. Display List 1\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Create List 2 & Concatenate with List 1\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(&list1, val);
                break;
            case 2:
                printf("List 1: ");
                displayList(list1);
                break;
            case 3:
                sortList(list1);
                printf("Sorted List 1: ");
                displayList(list1);
                break;
            case 4:
                reverseList(&list1);
                printf("Reversed List 1: ");
                displayList(list1);
                break;
            case 5:
                list2 = NULL;
                printf("How many elements do you want in List 2? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &val);
                    insertEnd(&list2, val);
                }
                printf("List 2: ");
                displayList(list2);
                list1 = concatenateLists(list1, list2);
                printf("Concatenated List (List 1 + List 2): ");
                displayList(list1);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
