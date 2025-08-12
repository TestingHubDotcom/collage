// Linear and Binary Search
#include <stdio.h>
#define MAX 100
void linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found\n");
}
void binarySearch(int arr[], int n, int key) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (arr[m] == key) {
            printf("Found at index %d\n", m);
            return;
        } else if (arr[m] < key) l = m+1;
        else r = m-1;
    }
    printf("Not found\n");
}
int main() {
    int arr[MAX], n, key, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);
    printf("1. Linear Search\n2. Binary Search\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1) linearSearch(arr, n, key);
    else if (choice == 2) binarySearch(arr, n, key);
    else printf("Invalid choice\n");
    return 0;
}
