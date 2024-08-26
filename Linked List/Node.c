#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


struct Node_int* createNode(int data) {
    struct Node_int* newNode = (struct Node_int*)malloc(sizeof(struct Node_int));
    if (newNode == NULL) {
        return NULL; 
    }
    newNode->Data = data;
    newNode->next = NULL; 
    return newNode;
}


void printNode(struct Node_int* node) {
    if (node != NULL) {
        printf("Data: %d\n", node->Data);
    } else {
        printf("Node is NULL\n");
    }
}


void freeNode(struct Node_int* node) {
    if (node != NULL) {
        free(node);
    }
}