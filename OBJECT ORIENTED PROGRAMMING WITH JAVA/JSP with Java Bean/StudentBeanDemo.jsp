<%@ page import="beans.StudentBean" %>
<jsp:useBean id="student" class="beans.StudentBean" scope="session" />
<jsp:setProperty name="student" property="*" />
<html>
<head>
    <title>Student Registration with JavaBean</title>
</head>
<body>
    <h2>Student Registration Form (JavaBean Example)</h2>
    <form method="post">
        Roll: <input type="number" name="roll" required><br>
        Name: <input type="text" name="name" required><br>
        Email: <input type="email" name="email" required><br>
        <input type="submit" value="Register">
    </form>
    <hr>
    <% if (request.getMethod().equalsIgnoreCase("POST")) { %>
        <h3>Student Registered!</h3>
        <p>Roll: <jsp:getProperty name="student" property="roll" /></p>
        <p>Name: <jsp:getProperty name="student" property="name" /></p>
        <p>Email: <jsp:getProperty name="student" property="email" /></p>
    <% } %>
</body>
</html>
