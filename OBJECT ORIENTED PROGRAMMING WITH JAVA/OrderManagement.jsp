<%@ page import="java.util.*" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Order Management System</title>
</head>
<body>
    <h2>Order Management System</h2>
    <form method="post">
        Product Name: <input type="text" name="product" required><br>
        Quantity: <input type="number" name="quantity" min="1" required><br>
        <input type="submit" value="Place Order">
    </form>
    <hr>
    <% 
        String product = request.getParameter("product");
        String quantityStr = request.getParameter("quantity");
        if (product != null && quantityStr != null) {
            int quantity = Integer.parseInt(quantityStr);
            out.println("<h3>Order Placed Successfully!</h3>");
            out.println("<p>Product: " + product + "</p>");
            out.println("<p>Quantity: " + quantity + "</p>");
            out.println("<p>Order Date: " + new java.util.Date() + "</p>");
        }
    %>
</body>
</html>
