#include <stdio.h>

int reverseNumber(int num) 
{
    int reverse = 0;
    while (num != 0) {
        int remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    return reverse;
}

void checkPalindrome(int num) {
    if (num < 0) {
        printf("%d is not a palindrome\n", num);
    } else {
        int reversedNum = reverseNumber(num);
        if (num == reversedNum) {
            printf("%d is a palindrome\n", num);
        } else {
            printf("%d is not a palindrome\n", num);
        }
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Reversed number: %d\n", reverseNumber(num));
    checkPalindrome(num);
    
    return 0;
}