#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int findNode(Node* head, int key) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; 
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    Node* head = NULL;
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    printf("Linked list: ");
    printList(head);

    int key;
    printf("Enter a value to search for: ");
    scanf("%d", &key);

    int position = findNode(head, key);

    if (position != -1) {
        printf("Found %d at position %d\n", key, position);
    } else {
        printf("%d not found in the list\n", key);
    }

    return 0;
}