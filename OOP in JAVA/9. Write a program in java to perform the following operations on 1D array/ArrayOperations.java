// 9. Write a program in java to perform the following operations on 1D array: 
// a. User input 
// b. Traversing the array 
// c. Sorting the array 
// d. Deleting the smallest element 
// e. Searching 
import java.util.Scanner;

public class ArrayOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 1. Input
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // 2. Traversing
        System.out.print("Array elements: ");
        for (int x : arr) {
            System.out.print(x + " ");
        }
        System.out.println();

        // 3. Sorting (Ascending)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        System.out.print("Sorted array: ");
        for (int x : arr) {
            System.out.print(x + " ");
        }
        System.out.println();

        // 4. Delete smallest element (first element after sorting)
        int smallest = arr[0];
        int newArr[] = new int[n - 1];
        for (int i = 1; i < n; i++) {
            newArr[i - 1] = arr[i];
        }

        System.out.println("Smallest element deleted: " + smallest);
        System.out.print("Array after deletion: ");
        for (int x : newArr) {
            System.out.print(x + " ");
        }
        System.out.println();

        // 5. Searching an element
        System.out.print("Enter element to search: ");
        int key = sc.nextInt();

        boolean found = false;
        for (int x : newArr) {
            if (x == key) {
                found = true;
                break;
            }
        }

        if (found)
            System.out.println(key + " found in array.");
        else
            System.out.println(key + " not found.");

        sc.close();
    }
}
