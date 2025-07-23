#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Original list
    struct node *head = malloc(sizeof(struct node));
    head->data = 56;
    head->link = NULL;

    // Insert at beginning
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = 100;
    new_node->link = head;  // new node points to the old head
    head = new_node;        // update head to new node

    // Print list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");

    return 0;
}
