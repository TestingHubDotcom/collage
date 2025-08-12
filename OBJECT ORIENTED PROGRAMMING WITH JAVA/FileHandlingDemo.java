import java.io.*;

public class FileHandlingDemo {
    public static void main(String[] args) {
        String filename = "sample.txt";
        String content = "Hello, this is a file handling demo in Java!";

        // Write to a file
        try (FileWriter writer = new FileWriter(filename)) {
            writer.write(content);
            System.out.println("File written successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file: " + e.getMessage());
        }

        // Read from a file
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            System.out.println("Reading from file:");
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file: " + e.getMessage());
        }

        // Delete the file
        File file = new File(filename);
        if (file.delete()) {
            System.out.println("File deleted successfully.");
        } else {
            System.out.println("Failed to delete the file.");
        }
    }
}
