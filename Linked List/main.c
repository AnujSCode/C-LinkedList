#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add a node to the end\n");
    printf("2. Remove a node by value\n");
    printf("3. Find a node by value\n");
    printf("4. Print the entire list\n");
    printf("5. Reverse the list\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct LinkedList list;
    list.head = NULL;
    int choice, value;
    struct Node_int* foundNode;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                addNodeToEnd(&list, value);
                printf("Node added.\n");
                break;

            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                removeNodeByValue(&list, value);
                printf("Node removed (if it existed).\n");
                break;

            case 3:
                printf("Enter the value to find: ");
                scanf("%d", &value);
                foundNode = findNode(&list, value);
                if (foundNode != NULL) {
                    printf("Node found: ");
                    printNode(foundNode);
                } else {
                    printf("Node with value %d not found.\n", value);
                }
                break;

            case 4:
                printf("The list is:\n");
                printList(&list);
                break;

            case 5:
                reverseList(&list);
                printf("The list has been reversed.\n");
                break;

            case 6:
                printf("Exiting program.\n");
                freeList(&list);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
