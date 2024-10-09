#include <stdio.h>
#include <math.h>
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
int armstrongNumber(int num) {
    int digits = countDigits(num);
    int armstrong = 0;
    int temp = num;
    while (temp != 0) 
    {
        int digit = temp % 10;
        armstrong += pow(digit, digits);
        temp /= 10;
    }
    return armstrong;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int armstrong = armstrongNumber(num);
    if (num == armstrong) {
        printf("%d is an Armstrong number. Its Armstrong value is %d.\n", num, armstrong);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
   

    return 0;
}