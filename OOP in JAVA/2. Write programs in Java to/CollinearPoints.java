// b. Check whether three points are collinear or not. 
import java.util.Scanner;

public class CollinearPoints {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x1 and y1: ");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();

        System.out.print("Enter x2 and y2: ");
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();

        System.out.print("Enter x3 and y3: ");
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();

        int LHS = (x2 - x1) * (y3 - y1);
        int RHS = (y2 - y1) * (x3 - x1);

        if (LHS == RHS)
            System.out.println("The points are collinear");
        else
            System.out.println("The points are not collinear");

        sc.close();
    }
}
