#include <stdio.h>
int findLargest(int arr[][10], int m, int n) {
    int max = arr[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
void printArray(int arr[][10], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int arr[m][10];
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Original 2D array:\n");
    printArray(arr, m, n);

    int largest = findLargest(arr, m, n);
    printf("Largest number in the 2D array: %d\n", largest);

    return 0;
}