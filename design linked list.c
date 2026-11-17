#include <stdio.h>
#include <stdlib.h>

// Definition of a single linked list node
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Definition of the MyLinkedList structure
typedef struct {
    Node* head; // Dummy head node
    int size; // Tracks the current length of the list
} MyLinkedList;

// Initialize your data structure here.
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = (Node*)malloc(sizeof(Node)); // Create dummy head
    obj->head->val = 0;
    obj->head->next = NULL;
    obj->size = 0;
    return obj;
}

// Get the value of the index-th node. If index is invalid, return -1.
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1;
    }

    Node* curr = obj->head->next;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) {
        return;
    }
    if (index < 0) {
        index = 0; // Negative index means insert at head
    }

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

// Add a node of value val before the first element of the linked list.
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

// Append a node of value val as the last element of the linked list.
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

// Add a node before the index-th node. If index equals size, append to the end. If index > size, don't insert.


// Delete the index-th node in the linked list, if the index is valid.
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return;
    }

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node* toDelete = curr->next;
    curr->next = toDelete->next;
    free(toDelete);
    obj->size--;
}

// Free the memory allocated for the linked list to avoid memory leaks.
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    free(obj);
}
