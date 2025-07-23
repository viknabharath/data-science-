#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    // First node
    struct node *head = malloc(sizeof(struct node));
    head->data = 56;
    head->prev = NULL;
    head->next = NULL;

    // Second node
    struct node *second = malloc(sizeof(struct node));
    second->data = 96;
    second->prev = head;
    second->next = NULL;
    head->next = second;

    // Third node
    struct node *third = malloc(sizeof(struct node));
    third->data = 85;
    third->prev = second;
    third->next = NULL;
    second->next = third;

    // Print list forward
    printf("Forward: ");
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");

    // Print list backward from the last node
    printf("Backward: ");
    ptr = third;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");

    return 0;
}
