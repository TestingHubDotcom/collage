// 14. Write a Java program to create a vehicle
// class hierarchy.
// The base

// class should
// be Vehicle, with
// subclasses Truck, Car
// and Motorcycle.
// Each subclass
// should have
// properties such
// as make, model, year, and
// fuel type.
// Implement methods for
// calculating fuel efficiency,
// distance traveled, and
// maximum speed.

// Base Class
class Vehicle {
    String make, model, fuelType;
    int year;

    Vehicle(String make, String model, int year, String fuelType) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.fuelType = fuelType;
    }

    double calculateFuelEfficiency() {
        return 0; // To be overridden
    }

    double calculateDistanceTraveled(double fuelUsed) {
        return fuelUsed * calculateFuelEfficiency();
    }

    int getMaxSpeed() {
        return 0; // To be overridden
    }

    void display() {
        System.out.println("\nMake: " + make);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
        System.out.println("Fuel Type: " + fuelType);
    }
}

// Truck Subclass
class Truck extends Vehicle {
    Truck(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    double calculateFuelEfficiency() {
        return 5.0; // example value
    }

    int getMaxSpeed() {
        return 120;
    }
}

// Car Subclass
class Car extends Vehicle {
    Car(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    double calculateFuelEfficiency() {
        return 15.0; // example value
    }

    int getMaxSpeed() {
        return 180;
    }
}

// Motorcycle Subclass
class Motorcycle extends Vehicle {
    Motorcycle(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    double calculateFuelEfficiency() {
        return 35.0; // example value
    }

    int getMaxSpeed() {
        return 150;
    }
}

// Test Class
public class VehicleDemo {
    public static void main(String[] args) {
        Truck t = new Truck("Tata", "HCV", 2021, "Diesel");
        Car c = new Car("Honda", "City", 2022, "Petrol");
        Motorcycle m = new Motorcycle("Yamaha", "R15", 2023, "Petrol");

        t.display();
        System.out.println("Fuel Efficiency: " + t.calculateFuelEfficiency());
        System.out.println("Max Speed: " + t.getMaxSpeed());

        c.display();
        System.out.println("Fuel Efficiency: " + c.calculateFuelEfficiency());
        System.out.println("Max Speed: " + c.getMaxSpeed());

        m.display();
        System.out.println("Fuel Efficiency: " + m.calculateFuelEfficiency());
        System.out.println("Max Speed: " + m.getMaxSpeed());
    }
}
