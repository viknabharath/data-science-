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

    // Insert after first node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = 75;

       head->link = new_node;         // 56 link now points to 75                            56 | link                                96
       new_node->link = head->link;    // new node link(75) points to 96                                 --------  75| link -----------

    // Print list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");

    return 0;
}
