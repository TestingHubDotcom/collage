// c. find the final velocity of a moving car when the initial velocity, acceleration 
// and time are given by the user. [Hint. v=u+at]
import java.util.Scanner;

public class FinalVelocity {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter initial velocity (u): ");
        float u = sc.nextFloat();

        System.out.print("Enter acceleration (a): ");
        float a = sc.nextFloat();

        System.out.print("Enter time (t): ");
        float t = sc.nextFloat();

        float v = u + (a * t);

        System.out.println("Final Velocity (v) = " + v);

        sc.close();
    }
}