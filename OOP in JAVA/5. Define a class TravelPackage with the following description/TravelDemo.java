import java.util.Scanner;

class TravelPackage {
    String TCode;
    int NoOfAdults;
    int NoOfKids;
    int Kilometers;
    float TotalFare;

    // Constructor
    TravelPackage() {
        TCode = "NULL";
        NoOfAdults = 0;
        NoOfKids = 0;
        Kilometers = 0;
        TotalFare = 0;
    }

    // Assign Fare based on Km
    void AssignFare() {
        float adultFare;

        if (Kilometers >= 1000)
            adultFare = 500;
        else if (Kilometers >= 500)
            adultFare = 300;
        else
            adultFare = 200;

        float kidFare = adultFare / 2;

        TotalFare = (NoOfAdults * adultFare) + (NoOfKids * kidFare);
    }

    // Input tour details
    void EnterTour() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Travel Code: ");
        TCode = sc.nextLine();

        System.out.print("Enter Number of Adults: ");
        NoOfAdults = sc.nextInt();

        System.out.print("Enter Number of Kids: ");
        NoOfKids = sc.nextInt();

        System.out.print("Enter Kilometers: ");
        Kilometers = sc.nextInt();

        AssignFare();
        
        sc.close();
    }

    // Display tour details
    void ShowTour() {
        System.out.println("\n--- TOUR DETAILS ---");
        System.out.println("Travel Code: " + TCode);
        System.out.println("Adults: " + NoOfAdults);
        System.out.println("Kids: " + NoOfKids);
        System.out.println("Kilometers: " + Kilometers);
        System.out.println("Total Fare: Rs. " + TotalFare);
    }
}

public class TravelDemo {
    public static void main(String[] args) {
        TravelPackage tp = new TravelPackage();
        tp.EnterTour();
        tp.ShowTour();
    }
}
