// 13. Write a Java program to create a
// class known
// as Person
// with methods

// called 
// getFirstName()

// and getLastName(). Create a subclass called Employee that adds a 
// new method named getEmployeeId() and overrides

// the getLastName() method to 
// include the employee's job title.  
class Person {
    private String firstName;
    private String lastName;

    Person(String fn, String ln) {
        this.firstName = fn;
        this.lastName = ln;
    }

    String getFirstName() {
        return firstName;
    }

    String getLastName() {
        return lastName;
    }
}

class Employee extends Person {
    private String employeeId;
    private String jobTitle;

    Employee(String fn, String ln, String empId, String job) {
        super(fn, ln);
        this.employeeId = empId;
        this.jobTitle = job;
    }

    String getEmployeeId() {
        return employeeId;
    }

    // Overriding getLastName()
    @Override
    String getLastName() {
        return super.getLastName() + " (" + jobTitle + ")";
    }
}

public class EmployeeDemo {
    public static void main(String[] args) {
        Employee emp = new Employee("Rahul", "Sharma", "E102", "Software Engineer");

        System.out.println("First Name: " + emp.getFirstName());
        System.out.println("Last Name: " + emp.getLastName());
        System.out.println("Employee ID: " + emp.getEmployeeId());
    }
}
