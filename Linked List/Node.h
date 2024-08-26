#ifndef Node_h
#define Node_h

struct Node_int{
    int Data;
    struct Node_int *next;

};

struct Node_int* createNode(int data);
void printNode(struct Node_int* node);
void freeNode(struct Node_int* node);




#endif /*Node_h*/