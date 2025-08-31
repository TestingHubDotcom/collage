import java.util.Scanner;

class ArrayHandler {
    private int[] arr;

    // Constructor for creating array with user input
    public ArrayHandler(int size, Scanner sc) {
        arr = new int[size];
        System.out.println("Enter " + size + " elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
    }

    // Method to get element at a particular index
    public void getElementAtIndex(int index) {
        if (index >= 0 && index < arr.length) {
            System.out.println("Element at index " + index + " is: " + arr[index]);
        } else {
            System.out.println("Invalid index!");
        }
    }
}

public class Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input size of array
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        // Create object of ArrayHandler
        ArrayHandler obj = new ArrayHandler(n, sc);

        // Ask for index
        System.out.print("Enter index to fetch element: ");
        int index = sc.nextInt();

        obj.getElementAtIndex(index);

        sc.close();
    }
}