#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = (Node*)malloc(sizeof(Node));
    obj->head->val = 0;
    obj->head->next = NULL;
    obj->size = 0;
    return obj;
}

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
        index = 0;
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

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

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

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    free(obj);
}
