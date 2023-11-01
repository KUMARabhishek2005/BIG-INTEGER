#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node* createNode(int data);
void insert(Node** head, int data) ;
Node* addTwoNumbers(Node* l1, Node* l2);
void printList(Node* head); 
