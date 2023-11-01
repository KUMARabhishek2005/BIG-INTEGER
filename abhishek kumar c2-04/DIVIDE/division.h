#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

// Function to divide two linked lists
struct Node* divideLinkedLists(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    struct Node* temp1 = num1;
    while (temp1 != NULL) {
        struct Node* temp2 = num2;
        struct Node* carry = NULL;
        struct Node* prev = NULL;
        while (temp2 != NULL) {
            int quotient = temp1->data / temp2->data;
            int remainder = temp1->data % temp2->data;
         
            struct Node* node = newNode(quotient);
            if (carry != NULL) {
                carry->data += remainder * 10;
            }
            node->next = carry;
            carry = node;
            temp2 = temp2->next;
        }
        if (carry != NULL) {
            if (prev != NULL) {
                prev->next = carry;
            } else {
                result = carry;
            }
        }
        prev = temp1;
        temp1 = temp1->next;
    }
    return result;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
}