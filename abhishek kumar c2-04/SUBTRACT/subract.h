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

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to subtract two linked lists representing integers
Node* subtractTwoNumbers(Node* l1, Node* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node* result = NULL;
    Node* current = NULL;
    int borrow = 0;

    while (l1 || l2) {
        int x = (l1 != NULL) ? l1->data : 0;
        int y = (l2 != NULL) ? l2->data : 0;
        int diff = x - y - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        Node* newNode = createNode(diff);
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

    return reverseList(result);
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
