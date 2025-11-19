// b. Palindrom or not. 
import java.util.Scanner;

public class PalindromeCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        int original = n;
        int rev = 0;

        while (n > 0) {
            int r = n % 10;
            rev = rev * 10 + r;
            n = n / 10;
        }

        if (original == rev)
            System.out.println(original + " is a Palindrome");
        else
            System.out.println(original + " is Not a Palindrome");
        sc.close();
    }
}
