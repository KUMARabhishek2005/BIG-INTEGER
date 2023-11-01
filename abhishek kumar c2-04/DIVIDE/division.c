#include <stdio.h>
#include <stdlib.h>
#include"division.h"
int main() {
    // Create the first linked list
    struct Node* num1 = NULL;
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);
    insertAtBeginning(&num1, 9);

    // Create the second linked list
    struct Node* num2 = NULL;
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);
    insertAtBeginning(&num2, 9);

    // Divide the linked lists
    struct Node* result = divideLinkedLists(num1, num2);

    // Print the result
    printList(result);

    return 0;
}
