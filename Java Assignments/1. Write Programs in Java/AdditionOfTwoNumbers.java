import java.util.Scanner;

public class AdditionOfTwoNumbers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Get user input
        System.out.print("Enter 1st Number : ");
        int num1 = input.nextInt();

        System.out.print("Enter 2nd Number : ");
        int num2 = input.nextInt();

        System.out.println("The sum is: " + (num1 + num2));

        input.close();
    }
}
