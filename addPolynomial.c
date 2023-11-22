#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} node;

// Function to add a new node to the linked list
node* addNode(node* head, int coeff, int pow) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = head;
    return newNode;
}

// Function to display the linked list
void display(node* ptr) {
    while (ptr != NULL) {
        printf("%dx^%d ", ptr->coeff, ptr->pow);
        if (ptr->next != NULL) {
            printf("+ ");
        }
        ptr = ptr->next;
    }
    printf("\n");
}

void addPoly(node* ptr1, node* ptr2, node** resultPoly) {
    node* resultHead = NULL;
    node* resultTail = NULL;

    int power, coeff;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->pow > ptr2->pow) {
            power = ptr1->pow;
            coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        } else if (ptr2->pow > ptr1->pow) {
            power = ptr2->pow;
            coeff = ptr2->coeff;
            ptr2 = ptr2->next;
        } else {
            coeff = ptr1->coeff + ptr2->coeff;
            power = ptr1->pow;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (coeff != 0) {
            if (resultHead == NULL) {
                resultHead = addNode(NULL, coeff, power);
                resultTail = resultHead;
            } else {
                resultTail->next = addNode(NULL, coeff, power);
                resultTail = resultTail->next;
            }
        }
    }

    while (ptr1 != NULL) {
        resultTail->next = addNode(NULL, ptr1->coeff, ptr1->pow);
        resultTail = resultTail->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        resultTail->next = addNode(NULL, ptr2->coeff, ptr2->pow);
        resultTail = resultTail->next;
        ptr2 = ptr2->next;
    }

    *resultPoly = resultHead;
}

// Function to free the memory allocated for the linked list
void freeList(node* head) {
    node* current = head;
    node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Example usage
    node* poly1 = NULL;
    node* poly2 = NULL;
    node* resultPoly = NULL;

    // Add some nodes to poly1 and poly2
    poly1 = addNode(poly1, 3, 2);
    poly1 = addNode(poly1, 5, 1);
    poly1 = addNode(poly1, 2, 0);

    poly2 = addNode(poly2, 4, 3);
    poly2 = addNode(poly2, 2, 1);
    poly2 = addNode(poly2, 1, 0);

    // Call the addPoly function to add poly1 and poly2
    addPoly(poly1, poly2, &resultPoly);

    // Display the resultPoly
    display(resultPoly);

    // Free the memory
    freeList(poly1);
    freeList(poly2);
    freeList(resultPoly);

    return 0;
}
