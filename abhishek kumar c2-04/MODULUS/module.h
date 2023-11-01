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

// Function to compare two linked lists l1 and l2 (l1 > l2: return 1, l1 < l2: return -1, l1 == l2: return 0)
int compareLists(Node* l1, Node* l2) {
    while (l1 && l2) {
        if (l1->data > l2->data) return 1;
        else if (l1->data < l2->data) return -1;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        if (l1->data > 0) return 1;
        l1 = l1->next;
    }

    while (l2) {
        if (l2->data > 0) return -1;
        l2 = l2->next;
    }

    return 0;
}

// Function to subtract two linked lists l1 and l2 (l1 - l2)
Node* subtractLists(Node* l1, Node* l2) {
    Node* result = NULL;
    Node* current = NULL;
    int borrow = 0;

    while (l1) {
        int x = l1->data - borrow;
        int y = (l2) ? l2->data : 0;

        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        insert(&result, x - y);
        l1 = l1->next;

        if (l2) l2 = l2->next;
    }

    return reverseList(result);
}

// Function to compute the modulus of two linked lists l1 and l2 (l1 % l2)
Node* modulusLists(Node* l1, Node* l2) {
    while (compareLists(l1, l2) >= 0) {
        l1 = subtractLists(l1, l2);
    }

    return l1;
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
