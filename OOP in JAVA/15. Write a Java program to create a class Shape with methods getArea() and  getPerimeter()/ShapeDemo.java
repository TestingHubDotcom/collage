// 15. Write a Java program to create a
// class Shape
// with methods

// getArea() and 
// getPerimeter(). Create three subclasses: Circle, Rectangle, and Triangle. Override the 
// getArea()

// and getPerimeter() methods in each subclass to calculate and return the 
// area and perimeter of the respective shapes.  


// Base class
abstract class Shape {
    abstract double getArea();

    abstract double getPerimeter();
}

// Circle subclass
class Circle extends Shape {
    double radius;

    Circle(double r) {
        radius = r;
    }

    double getArea() {
        return Math.PI * radius * radius;
    }

    double getPerimeter() {
        return 2 * Math.PI * radius;
    }
}

// Rectangle subclass
class Rectangle extends Shape {
    double length, width;

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }
}

// Triangle subclass
class Triangle extends Shape {
    double a, b, c; // sides

    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double getArea() {
        double s = (a + b + c) / 2; // semi-perimeter
        return Math.sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    }

    double getPerimeter() {
        return a + b + c;
    }
}

// Main class to test
public class ShapeDemo {
    public static void main(String[] args) {
        Shape circle = new Circle(5);
        Shape rectangle = new Rectangle(4, 6);
        Shape triangle = new Triangle(3, 4, 5);

        System.out.println("Circle Area: " + circle.getArea());
        System.out.println("Circle Perimeter: " + circle.getPerimeter());

        System.out.println("\nRectangle Area: " + rectangle.getArea());
        System.out.println("Rectangle Perimeter: " + rectangle.getPerimeter());

        System.out.println("\nTriangle Area: " + triangle.getArea());
        System.out.println("Triangle Perimeter: " + triangle.getPerimeter());
    }
}
