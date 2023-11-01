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

// Function to multiply two linked lists representing integers
Node* multiplyTwoNumbers(Node* l1, Node* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node* result = NULL;
    Node* current = NULL;
    Node* temp = l2;
    int position = 0;

    while (temp) {
        int carry = 0;
        Node* l1_temp = l1;
        Node* intermediate_result = NULL;
        Node* intermediate_current = NULL;

        for (int i = 0; i < position; i++) {
            insert(&intermediate_result, 0);
        }

        while (l1_temp) {
            int product = (l1_temp->data * temp->data) + carry;
            carry = product / 10;
            insert(&intermediate_result, product % 10);
            l1_temp = l1_temp->next;
        }

        if (carry > 0) {
            insert(&intermediate_result, carry);
        }

        current = result;
        intermediate_result = reverseList(intermediate_result);

        while (intermediate_result) {
            if (current) {
                current->data += intermediate_result->data;
            } else {
                insert(&result, intermediate_result->data);
                current = result;
            }

            if (current->data >= 10) {
                if (current->next) {
                    current->next->data += current->data / 10;
                } else {
                    insert(&result, current->data / 10);
                }

                current->data %= 10;
            }

            current = current->next;
            intermediate_result = intermediate_result->next;
        }

        position++;
        temp = temp->next;
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
