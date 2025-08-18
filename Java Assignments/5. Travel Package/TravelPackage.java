import java.util.Scanner;

public class TravelPackage {
    // Data Members
    String TravelCode;
    int NoofAdults;
    int NoofKids;
    int Kilometers;
    float TotalFare;

    // Constructor to initialize default values
    TravelPackage() {
        TravelCode = "NULL";
        NoofAdults = 0;
        NoofKids = 0;
        Kilometers = 0;
        TotalFare = 0.0f;
    }

    // Function to assign fare based on distance
    void AssignFare() {
        int farePerAdult;

        if (Kilometers >= 1000) {
            farePerAdult = 500;
        } else if (Kilometers >= 500) {
            farePerAdult = 300;
        } else {
            farePerAdult = 200;
        }

        float farePerKid = farePerAdult / 2.0f;
        TotalFare = (NoofAdults * farePerAdult) + (NoofKids * farePerKid);
    }

    // Function to input values
    void EnterTour() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Travel Code: ");
        TravelCode = sc.nextLine();

        System.out.print("Enter number of adults: ");
        NoofAdults = sc.nextInt();

        System.out.print("Enter number of kids: ");
        NoofKids = sc.nextInt();

        System.out.print("Enter kilometers: ");
        Kilometers = sc.nextInt();

        AssignFare(); // Calculate fare
        sc.close();
    }

    // Function to display all data
    void ShowTour() {
        System.out.println("\n--- Tour Details ---");
        System.out.println("Travel Code: " + TravelCode);
        System.out.println("Number of Adults: " + NoofAdults);
        System.out.println("Number of Kids: " + NoofKids);
        System.out.println("Kilometers: " + Kilometers);
        System.out.println("Total Fare: Rs. " + TotalFare);
        System.out.println("---------------------\n");
    }

    // Main method with menu
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TravelPackage tp = new TravelPackage();
        int choice;

        do {
            System.out.println("\n===== Travel Package Menu =====");
            System.out.println("1. Enter Tour");
            System.out.println("2. Show Tour");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    tp.EnterTour();
                    break;
                case 2:
                    tp.ShowTour();
                    break;
                case 3:
                    System.out.println("Exiting program. Thank you!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        } while (choice != 3);
        sc.close();
    }
}
