// 10. Write a Java program to perform the following operation on a 2D array.
// a.Take user inputs of the number of rows,columns,and elements for two matrices.
// b.Matrix subtraction 
// c.Matrix multiplication

import java.util.Scanner;

public class MatrixOperations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input rows and columns
        System.out.print("Enter number of rows: ");
        int r = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int c = sc.nextInt();

        int A[][] = new int[r][c];
        int B[][] = new int[r][c];

        // Input matrix A
        System.out.println("Enter elements of Matrix A:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                A[i][j] = sc.nextInt();
            }
        }

        // Input matrix B
        System.out.println("Enter elements of Matrix B:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                B[i][j] = sc.nextInt();
            }
        }

        // Subtraction
        int sub[][] = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                sub[i][j] = A[i][j] - B[i][j];
            }
        }

        System.out.println("Matrix Subtraction (A - B):");
        for (int[] row : sub) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }

        // Multiplication
        int mul[][] = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < c; k++) {
                    mul[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        System.out.println("Matrix Multiplication (A × B):");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(mul[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
