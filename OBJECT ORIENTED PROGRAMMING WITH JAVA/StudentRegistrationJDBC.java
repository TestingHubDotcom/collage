import java.sql.*;
import java.util.Scanner;

public class StudentRegistrationJDBC {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/your_database"; // Change your_database to your DB name
        String user = "root"; // Change if your MySQL username is different
        String password = ""; // Enter your MySQL password

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter student name: ");
        String name = scanner.nextLine();
        System.out.print("Enter student roll number: ");
        int roll = scanner.nextInt();
        scanner.nextLine(); // consume newline
        System.out.print("Enter student email: ");
        String email = scanner.nextLine();

        String insertQuery = "INSERT INTO students (roll, name, email) VALUES (?, ?, ?)";

        try {
            // Load MySQL JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            // Connect to database
            Connection conn = DriverManager.getConnection(url, user, password);
            PreparedStatement pstmt = conn.prepareStatement(insertQuery);
            pstmt.setInt(1, roll);
            pstmt.setString(2, name);
            pstmt.setString(3, email);
            int rows = pstmt.executeUpdate();
            if (rows > 0) {
                System.out.println("Student registered successfully!");
            } else {
                System.out.println("Registration failed.");
            }
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
