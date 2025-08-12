public class StringHandlingDemo {
    public static void main(String[] args) {
        String str = "Hello, Java World!";

        // Length of the string
        System.out.println("Length: " + str.length());

        // Convert to uppercase
        System.out.println("Uppercase: " + str.toUpperCase());

        // Convert to lowercase
        System.out.println("Lowercase: " + str.toLowerCase());

        // Substring
        System.out.println("Substring (7, 11): " + str.substring(7, 11));

        // Replace
        System.out.println("Replace 'Java' with 'Programming': " + str.replace("Java", "Programming"));

        // Check if contains
        System.out.println("Contains 'World': " + str.contains("World"));

        // Index of a character
        System.out.println("Index of 'J': " + str.indexOf('J'));

        // Split
        String[] words = str.split(" ");
        System.out.println("Words:");
        for (String word : words) {
            System.out.println(word);
        }
    }
}