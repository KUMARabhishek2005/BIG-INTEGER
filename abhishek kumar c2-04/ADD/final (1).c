#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two linked lists representing integers
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* result = NULL;
    Node* current = NULL;
    int carry = 0;

    while (l1 || l2) {
        int x = (l1 != NULL) ? l1->data : 0;
        int y = (l2 != NULL) ? l2->data : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;

        Node* newNode = createNode(sum);
        if (result == NULL) {
            result = newNode;
            current = result;
        } else {
            current->next = newNode;
            current = newNode;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = createNode(carry);
    }

    return result;
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

