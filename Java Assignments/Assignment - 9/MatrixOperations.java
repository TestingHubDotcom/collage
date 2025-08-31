import java.util.Arrays;
import java.util.Scanner;

class Matrix {
    private int[][] matrix;

    // Constructor
    public Matrix(int rows, int cols, Scanner sc) {
        matrix = new int[rows][cols];
        System.out.println("Enter elements for a " + rows + "x" + cols + " matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
    }

    // Traversing
    public void traverse() {
        System.out.println("Matrix elements are:");
        for (int i = 0; i < matrix.length; i++) {
            System.out.println(Arrays.toString(matrix[i]));
        }
    }

    // Searching
    public void search(int key) {
        boolean found = false;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == key) {
                    System.out.println("Element " + key + " found at position (" + i + ", " + j + ")");
                    found = true;
                }
            }
        }
        if (!found) {
            System.out.println("Element " + key + " not found.");
        }
    }
}

public class MatrixOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input
        System.out.print("Enter number of rows: ");
        int rows = sc.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = sc.nextInt();

        // Create object
        Matrix obj = new Matrix(rows, cols, sc);

        // Perform operations
        obj.traverse();

        System.out.print("Enter element to search: ");
        int key = sc.nextInt();
        obj.search(key);

        sc.close();
    }
}
