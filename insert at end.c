#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Create initial list: 56 -> 96
    struct node *head = malloc(sizeof(struct node));
    head->data = 56;
    head->link = malloc(sizeof(struct node));
    head->link->data = 96;
    head->link->link = NULL;

    // Create new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = 85;
    new_node->link = NULL;

    // Directly access the last node and link new node
    head->link->link = new_node;

    // Print list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");

    return 0;
}
