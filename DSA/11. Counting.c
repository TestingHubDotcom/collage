#include <stdio.h>

void countingSort(int arr[], int n) {
    int i;
    int max = arr[0];

    // Find the maximum element in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create count array with size of (max + 1)
    int count[max + 1];
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store the count of each element
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify count array such that each element at each index
    // stores the sum of previous counts
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    int output[n];
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted elements
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    countingSort(arr, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}