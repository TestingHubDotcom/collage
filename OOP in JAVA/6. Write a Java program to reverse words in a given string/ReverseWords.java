// Input:He is nice 
// Output:eH si ecin
import java.util.Scanner;

public class ReverseWords {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String[] words = input.split(" ");
        String result = "";

        for (String w : words) {
            String rev = "";
            for (int i = w.length() - 1; i >= 0; i--) {
                rev += w.charAt(i);
            }
            result += rev + " ";
        }

        System.out.println("Output: " + result.trim());

        sc.close();
    }
}
