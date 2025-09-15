// Base class Vehicle
class Vehicle {
    protected String make;
    protected String model;
    protected int year;
    protected String fuelType;

    public Vehicle(String make, String model, int year, String fuelType) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.fuelType = fuelType;
    }

    public void displayInfo() {
        System.out.println("Make: " + make);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
        System.out.println("Fuel Type: " + fuelType);
    }

    // Methods for calculations (to be overridden in subclasses if needed)
    public double calculateFuelEfficiency(double distance, double fuelUsed) {
        return distance / fuelUsed; // km per liter
    }

    public double calculateDistanceTraveled(double speed, double time) {
        return speed * time; // distance = speed × time
    }

    public void displayMaxSpeed(double maxSpeed) {
        System.out.println("Maximum Speed: " + maxSpeed + " km/h");
    }
}

// Subclass Truck
class Truck extends Vehicle {
    public Truck(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }
}

// Subclass Car
class Car extends Vehicle {
    public Car(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }
}

// Subclass Motorcycle
class Motorcycle extends Vehicle {
    public Motorcycle(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }
}

// Main class to test
public class Main {
    public static void main(String[] args) {
        Truck truck = new Truck("Volvo", "FH16", 2022, "Diesel");
        Car car = new Car("Toyota", "Camry", 2023, "Petrol");
        Motorcycle bike = new Motorcycle("Yamaha", "R15", 2024, "Petrol");

        System.out.println("=== Truck Details ===");
        truck.displayInfo();
        System.out.println("Fuel Efficiency: " + truck.calculateFuelEfficiency(400, 50) + " km/l");
        System.out.println("Distance Traveled: " + truck.calculateDistanceTraveled(80, 5) + " km");
        truck.displayMaxSpeed(120);

        System.out.println("\n=== Car Details ===");
        car.displayInfo();
        System.out.println("Fuel Efficiency: " + car.calculateFuelEfficiency(600, 40) + " km/l");
        System.out.println("Distance Traveled: " + car.calculateDistanceTraveled(100, 3) + " km");
        car.displayMaxSpeed(180);

        System.out.println("\n=== Motorcycle Details ===");
        bike.displayInfo();
        System.out.println("Fuel Efficiency: " + bike.calculateFuelEfficiency(300, 10) + " km/l");
        System.out.println("Distance Traveled: " + bike.calculateDistanceTraveled(60, 2) + " km");
        bike.displayMaxSpeed(150);
    }
}