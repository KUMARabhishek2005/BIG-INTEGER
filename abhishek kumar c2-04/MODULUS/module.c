#include"module.h"
int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    printf("Enter the dividend as a linked list (digits reversed):\n");
    int digit;
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) break;
        insert(&l1, digit);
    }

    printf("Enter the divisor as a linked list (digits reversed):\n");
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) break;
        insert(&l2, digit);
    }

    Node* result = modulusLists(l1, l2);

    printf("Result of modulus: ");
    printList(result);

    return 0;
}
