// Quick Sort
#include <stdio.h>
#define MAX 100
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = low-1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }
        }
        int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;
        int pi = i+1;
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int main() {
    int arr[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
