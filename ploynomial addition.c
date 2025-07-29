#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the polynomial
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the end
struct Node* insertNode(struct Node* head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (head == NULL) {                                                       // 
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Create a polynomial from user input
struct Node* createPolynomial() {
    struct Node* poly = NULL;
    int coeff, pow;
    char choice;

    do {
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter power: ");
        scanf("%d", &pow);

        poly = insertNode(poly, coeff, pow);

        printf("Add another term? (y/n): ");
        scanf(" %c", &choice);  // Space before %c to handle newline
    } while (choice == 'y' || choice == 'Y');

    return poly;
}

// Add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            result = insertNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            result = insertNode(result, poly2->coeff, poly2->pow);https://chatgpt.com/c/6888ee1b-3174-8010-877f-00243a51b032
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                result = insertNode(result, sumCoeff, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        result = insertNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertNode(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Display the polynomial
void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL && poly->next->coeff >= 0)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Main function
int main() {
    printf("Enter the first polynomial:\n");
    struct Node* poly1 = createPolynomial();

    printf("\nEnter the second polynomial:\n");
    struct Node* poly2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    display(sum);

    return 0;
}