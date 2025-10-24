#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return NULL;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    temp = head;

    for (i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    printf("\nDoubly Linked List created successfully!\n");
    return head;
}

// Function to traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("\nTraversal in Forward Direction:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to traverse the list backward
void traverseBackward(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Move to the last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("\nTraversal in Backward Direction:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    traverseForward(head);
    traverseBackward(head);

    return 0;
}
