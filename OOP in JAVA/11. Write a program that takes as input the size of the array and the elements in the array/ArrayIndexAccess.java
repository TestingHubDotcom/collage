// 11. Write a program that takes as input the size of the array and the elements in the array.
// The program then asks the user to enter a particular index and prints the element at that index
import java.util.Scanner;

public class ArrayIndexAccess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter index to access: ");
        int index = sc.nextInt();

        if (index >= 0 && index < n)
            System.out.println("Element at index " + index + " = " + arr[index]);
        else
            System.out.println("Invalid index!");

        sc.close();
    }
}
