<%@ page import="java.sql.*" %>
<%@ page import="java.util.*" %>
<html>
<head>
    <title>User Registration with JDBC</title>
</head>
<body>
    <h2>User Registration Form</h2>
    <form method="post">
        Name: <input type="text" name="name" required><br>
        Email: <input type="email" name="email" required><br>
        <input type="submit" value="Register">
    </form>
    <hr>
    <% 
        String name = request.getParameter("name");
        String email = request.getParameter("email");
        if (name != null && email != null) {
            Connection conn = null;
            PreparedStatement pstmt = null;
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                String url = "jdbc:mysql://localhost:3306/your_database"; // Change to your DB
                String user = "root"; // Change if needed
                String password = ""; // Change if needed
                conn = DriverManager.getConnection(url, user, password);
                String sql = "INSERT INTO users (name, email) VALUES (?, ?)";
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, name);
                pstmt.setString(2, email);
                int rows = pstmt.executeUpdate();
                if (rows > 0) {
                    out.println("<p>User registered successfully!</p>");
                } else {
                    out.println("<p>Registration failed.</p>");
                }
            } catch (Exception e) {
                out.println("<p>Error: " + e.getMessage() + "</p>");
            } finally {
                try { if (pstmt != null) pstmt.close(); } catch (Exception e) {}
                try { if (conn != null) conn.close(); } catch (Exception e) {}
            }
        }
    %>
</body>
</html>
