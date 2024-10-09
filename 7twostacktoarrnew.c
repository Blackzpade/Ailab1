#include <stdio.h>

#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top1;
    int top2;
} TwoStacks;

TwoStacks* createTwoStacks() {
    TwoStacks* twoStacks = (TwoStacks*) malloc(sizeof(TwoStacks));
    twoStacks->top1 = -1;
    twoStacks->top2 = MAX_SIZE;
    return twoStacks;
}

int isEmptyStack1(TwoStacks* twoStacks) {
    return twoStacks->top1 == -1;
}

int isEmptyStack2(TwoStacks* twoStacks) {
    return twoStacks->top2 == MAX_SIZE;
}

int isFull(TwoStacks* twoStacks) {
    return twoStacks->top1 + 1 == twoStacks->top2;
}

void pushStack1(TwoStacks* twoStacks, int value) {
    if (isFull(twoStacks)) {
        printf("Stack overflow\n");
        return;
    }
    twoStacks->data[++twoStacks->top1] = value;
}

void pushStack2(TwoStacks* twoStacks, int value) {
    if (isFull(twoStacks)) {
        printf("Stack overflow\n");
        return;
    }
    twoStacks->data[--twoStacks->top2] = value;
}

int popStack1(TwoStacks* twoStacks) {
    if (isEmptyStack1(twoStacks)) {
        printf("Stack underflow\n");
        return -1;
    }
    return twoStacks->data[twoStacks->top1--];
}

int popStack2(TwoStacks* twoStacks) {
    if (isEmptyStack2(twoStacks)) {
        printf("Stack underflow\n");
        return -1;
    }
    return twoStacks->data[twoStacks->top2++];
}

void displayStacks(TwoStacks* twoStacks) {
    int i;
    printf("Stack 1: ");
    for (i = 0; i <= twoStacks->top1; i++) {
        printf("%d ", twoStacks->data[i]);
    }
    printf("\n");

    printf("Stack 2: ");
    for (i = twoStacks->top2; i < MAX_SIZE; i++) {
        printf("%d ", twoStacks->data[i]);
    }
    printf("\n");
}

int main() {

    TwoStacks* twoStacks = createTwoStacks();

    int choice, value;

    while (1) {
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stacks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push to Stack 1: ");
                scanf("%d", &value);
                pushStack1(twoStacks, value);
                break;
            case 2:
                printf("Enter element to push to Stack 2: ");
                scanf("%d", &value);
                pushStack2(twoStacks, value);
                break;
            case 3:
                value = popStack1(twoStacks);
                if (value != -1) {
                    printf("Popped element from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = popStack2(twoStacks);
                if (value != -1) {
                    printf("Popped element from Stack 2: %d\n", value);
                }
                break;
            case 5:
                displayStacks(twoStacks);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}