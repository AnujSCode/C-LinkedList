#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>



void addNodeToEnd(struct LinkedList* list, int data) {
    struct Node_int* newNode = createNode(data);
    if (newNode == NULL) {
        return; 
    }

    if (list->head == NULL) {
        list->head = newNode; 
    } else {
        struct Node_int* current = list->head;
        while (current->next != NULL) {
            current = current->next; 
        }
        current->next = newNode; 
    }
}


void printList(struct LinkedList* list) {
    struct Node_int* current = list->head;
    while (current != NULL) {
        printNode(current); 
        current = current->next; 
    }
}


void freeList(struct LinkedList* list) {
    struct Node_int* current = list->head;
    struct Node_int* nextNode;
    while (current != NULL) {
        nextNode = current->next; 
        freeNode(current); 
        current = nextNode; 
    }
}


void removeNodeByValue(struct LinkedList* list, int value) {
    if (list->head == NULL) return;

    struct Node_int* temp = list->head;
    struct Node_int* prev = NULL;

    if (temp != NULL && temp->Data == value) {
        list->head = temp->next;
        freeNode(temp);
        return;
    }

    while (temp != NULL && temp->Data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    freeNode(temp);
}


struct Node_int* findNode(struct LinkedList* list, int value) {
    struct Node_int* current = list->head;
    while (current != NULL) {
        if (current->Data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void reverseList(struct LinkedList* list) {
    struct Node_int* prev = NULL;
    struct Node_int* current = list->head;
    struct Node_int* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}
