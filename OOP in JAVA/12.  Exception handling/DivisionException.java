import java.util.Scanner;

public class DivisionException {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter value of a: ");
            int a = sc.nextInt();

            System.out.print("Enter value of b: ");
            int b = sc.nextInt();

            int result = a / b; // may throw ArithmeticException

            System.out.println("Quotient = " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed!");
        } finally {
            System.out.println("Inside finally block");
        }
        
        sc.close();
    }
}
