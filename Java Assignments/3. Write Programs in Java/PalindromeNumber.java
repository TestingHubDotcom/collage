import java.util.Scanner;

public class PalindromeNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number
        System.out.print("Enter a number: ");
        int number = sc.nextInt();

        int originalNumber = number;
        int reversedNumber = 0;

        // Reverse the number
        while (number != 0) {
            int digit = number % 10;         // Get last digit
            reversedNumber = reversedNumber * 10 + digit;
            number = number / 10;            // Remove last digit
        }

        // Check palindrome
        if (originalNumber == reversedNumber) {
            System.out.println(originalNumber + " is a Palindrome number.");
        } else {
            System.out.println(originalNumber + " is NOT a Palindrome number.");
        }

        sc.close();
    }
}