#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node  *link;  //pointer to the struct node(self referential structure)
   
};
int main()
 {
    struct node *head = malloc(sizeof(struct node)); //head can access both data and link
    head->data= 56;
    head->link = NULL; //first node

// creating second node

     struct node *current = malloc(sizeof(struct node));
    current-> data= 96;
    current-> link= NULL;
    head-> link= current; // this contains the address of first link

// third node
    current = malloc(sizeof(struct node));
    current-> data= 85;
    current-> link= NULL;

    head->link->link = current; // contains all the nodes data together

    // printing all nodes

    struct node *ptr = head; // collecting all nodes

    
    while( ptr !=NULL)
{
    printf("%d ->",ptr->data);
    ptr = ptr->link; // moving to next node until null
    
}  
    printf("NULL");
return 0;
 }
