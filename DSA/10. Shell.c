#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a big gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        for (i = gap; i < n; i++) {
            // add arr[i] to the elements that have been gap sorted
            temp = arr[i];

            // shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    shellSort(arr, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}