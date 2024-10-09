#include <stdio.h>

#define MAX_NUMBERS 100

int main() {
    int arr[MAX_NUMBERS]; 
    int i = 0; 

    printf("Enter numbers (press enter after each number, and a blank line to finish input):\n");

    while (i < MAX_NUMBERS) {
        char line[1024];
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; 
        }

        if (line[0] == '\n') {
            break; 
        }

        int num;
        if (sscanf(line, "%d", &num) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        arr[i++] = num;
    }

    printf("Arranged numbers: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}