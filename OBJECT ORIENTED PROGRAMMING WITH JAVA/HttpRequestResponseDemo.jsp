<%@ page import="java.io.*" %>
<%@ page import="javax.servlet.*" %>
<%@ page import="javax.servlet.http.*" %>
<html>
<head>
    <title>JSP HTTP Request and Response Demo</title>
</head>
<body>
    <h2>JSP HTTP Request and Response Demo</h2>
    <form method="post">
        Enter your name: <input type="text" name="username" required>
        <input type="submit" value="Submit">
    </form>
    <hr>
    <% 
        String method = request.getMethod();
        String user = request.getParameter("username");
        out.println("<p>HTTP Method: " + method + "</p>");
        if (user != null && !user.isEmpty()) {
            out.println("<p>Hello, " + user + "!</p>");
            out.println("<p>Your IP Address: " + request.getRemoteAddr() + "</p>");
            response.setHeader("Custom-Header", "JSP-Demo");
        }
    %>
</body>
</html>
