#include <stdio.h>
void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;  
    printf("%d, %d, ", t1, t2);
for (int i = 3; i <= n; i++)
 {
        nextTerm = t1 + t2;
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
}

int main()
 {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series up to %d terms: ", n);
    printFibonacci(n);

    return 0;
}