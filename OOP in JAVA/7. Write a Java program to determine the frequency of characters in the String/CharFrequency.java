import java.util.Scanner;

public class CharFrequency {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String s = sc.nextLine();

        int[] freq = new int[256]; // ASCII size

        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)]++;
        }

        System.out.println("\nCharacter Frequency:");
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                System.out.println((char) i + " = " + freq[i]);
            }
        }

        sc.close();
    }
}
