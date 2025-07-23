#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Creating first node
    struct node *head = malloc(sizeof(struct node));
    head->data = 56;
    head->link = NULL;

    // Creating second node
    struct node *second = malloc(sizeof(struct node));
    second->data = 96;
    second->link = NULL;
    head->link = second;

    // Delete node with data = 96
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL && temp->data != 96) {
        prev = temp;
        temp = temp->link;
    }

    if (temp != NULL) {
        prev->link = temp->link; // Skip the node
        free(temp);              // Free memory
    }

    // Print the list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");

    return 0;
}
