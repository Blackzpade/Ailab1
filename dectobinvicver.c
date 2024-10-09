#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int choice;
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char binary[32];
        printf("Enter a binary number: ");
        scanf("%s", binary);
        printf("Decimal equivalent: %d\n", binaryToDecimal(binary));
    } else if (choice == 2) {
        int decimal;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        printf("Binary equivalent: ");
        decimalToBinary(decimal);
        printf("\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}