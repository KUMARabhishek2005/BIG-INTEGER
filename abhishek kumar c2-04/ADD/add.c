#include"final.h"
int main() {
    Node* l1 = NULL;
    Node* l2 = NULL;

    printf("Enter the first integer as a linked list (digits reversed, -1 to end input):\n");
    int digit;
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) break;
        insert(&l1, digit);
    }

    printf("Enter the second integer as a linked list (digits reversed, -1 to end input):\n");
    while (1) {
        scanf("%d", &digit);
        if (digit == -1) break;
        insert(&l2, digit);
    }

    Node* result = addTwoNumbers(l1, l2);

    printf("Result of addition: ");
    printList(result);

    return 0;
}
