class Complex {
    private int real;
    private int imag;

    // Constructor
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // Addition
    Complex add(Complex c) {
        return new Complex(this.real + c.real, this.imag + c.imag);
    }

    // Subtraction
    Complex subtract(Complex c) {
        return new Complex(this.real - c.real, this.imag - c.imag);
    }

    // Multiplication
    Complex multiply(Complex c) {
        int realPart = (this.real * c.real) - (this.imag * c.imag);
        int imagPart = (this.real * c.imag) + (this.imag * c.real);
        return new Complex(realPart, imagPart);
    }

    // Display
    void display() {
        System.out.println(real + " + " + imag + "i");
    }
}

public class ComplexDemo {
    public static void main(String[] args) {

        Complex c1 = new Complex(4, 5);
        Complex c2 = new Complex(2, 3);

        Complex sum = c1.add(c2);
        Complex diff = c1.subtract(c2);
        Complex prod = c1.multiply(c2);

        System.out.print("Addition: ");
        sum.display();

        System.out.print("Subtraction: ");
        diff.display();

        System.out.print("Multiplication: ");
        prod.display();
    }
}
