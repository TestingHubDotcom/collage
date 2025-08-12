// Selection Sort
#include <stdio.h>
#define MAX 100
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        int t = arr[i]; arr[i] = arr[min]; arr[min] = t;
    }
}
int main() {
    int arr[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    selectionSort(arr, n);
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
