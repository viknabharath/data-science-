#include <stdio.h>

// Function to display the array
void display(int arr[], int size) {
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform linear search
int search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

// Main function
int main() {
    int arr[] = {10, 25, 30, 45, 60, 75};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, found;

    display(arr, size);

    printf("Enter the number to search: ");
    scanf("%d", &target);

    found = search(arr, size, target);

    if (found) {
        printf("Element %d found in the array.\n", target);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
