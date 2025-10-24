#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
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

// Function to traverse forward
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

// Function to traverse backward
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

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    printf("Inserted %d at the beginning.\n", data);
    return head;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    if (head == NULL)
        return newNode;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Inserted %d at the end.\n", data);
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    struct Node* temp = head;
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        return NULL;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted %d from end.\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Function to reverse the doubly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    printf("\nList reversed successfully!\n");
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, choice, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Traverse Forward\n");
        printf("2. Traverse Backward\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Reverse the List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseForward(head);
                break;
            case 2:
                traverseBackward(head);
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                head = reverseList(head);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
