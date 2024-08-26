#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

struct LinkedList {
    struct Node_int* head;
};

void addNodeToEnd(struct LinkedList* list, int data);
void printList(struct LinkedList* list);
void freeList(struct LinkedList* list);
void removeNodeByValue(struct LinkedList* list, int value);
struct Node_int* findNode(struct LinkedList* list, int value);
void reverseList(struct LinkedList* list);

#endif /* LINKEDLIST_H */
