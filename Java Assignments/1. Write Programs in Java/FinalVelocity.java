import java.util.Scanner;

public class FinalVelocity {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Get user input
        System.out.print("Enter initial velocity (u) in m/s: ");
        double u = input.nextDouble();

        System.out.print("Enter acceleration (a) in m/s²: ");
        double a = input.nextDouble();

        System.out.print("Enter time (t) in seconds: ");
        double t = input.nextDouble();

        // Calculate final velocity
        double v = u + (a * t);

        // Output the result
        System.out.printf("Final velocity (v) = %.2f m/s\n", v);

        input.close();
    }
}
