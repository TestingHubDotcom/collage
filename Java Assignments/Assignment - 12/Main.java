// Parent class Person
class Person {
    private String firstName;
    private String lastName;

    // Constructor
    public Person(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    // Method to get first name
    public String getFirstName() {
        return firstName;
    }

    // Method to get last name
    public String getLastName() {
        return lastName;
    }
}

// Subclass Employee
class Employee extends Person {
    private int employeeId;
    private String jobTitle;

    // Constructor
    public Employee(String firstName, String lastName, int employeeId, String jobTitle) {
        super(firstName, lastName);
        this.employeeId = employeeId;
        this.jobTitle = jobTitle;
    }

    // New method to get employee ID
    public int getEmployeeId() {
        return employeeId;
    }

    // Overriding getLastName() to include job title
    @Override
    public String getLastName() {
        return super.getLastName() + " (" + jobTitle + ")";
    }
}

// Main class to test
public class Main {
    public static void main(String[] args) {
        Person p = new Person("John", "Doe");
        System.out.println("Person Name: " + p.getFirstName() + " " + p.getLastName());

        Employee e = new Employee("Alice", "Smith", 101, "Software Engineer");
        System.out.println("Employee Name: " + e.getFirstName() + " " + e.getLastName());
        System.out.println("Employee ID: " + e.getEmployeeId());
    }
}