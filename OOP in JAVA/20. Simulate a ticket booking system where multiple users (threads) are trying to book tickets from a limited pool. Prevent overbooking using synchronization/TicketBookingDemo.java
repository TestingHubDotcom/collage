// Ticket Counter Class
class TicketCounter {
    private int availableTickets = 5; // Limited tickets

    // Synchronized method to prevent overbooking
    public synchronized void bookTicket(String user, int tickets) {
        System.out.println(user + " is trying to book " + tickets + " tickets...");

        if (tickets <= availableTickets) {
            System.out.println("Booking successful for " + user);
            availableTickets -= tickets;
            System.out.println("Tickets left: " + availableTickets);
        } else {
            System.out.println("Booking failed for " + user + ". Only " + availableTickets + " tickets left!");
        }

        System.out.println("-----------------------------------");
    }
}

// User Thread
class UserThread extends Thread {
    TicketCounter counter;
    String userName;
    int tickets;

    UserThread(TicketCounter counter, String userName, int tickets) {
        this.counter = counter;
        this.userName = userName;
        this.tickets = tickets;
    }

    public void run() {
        counter.bookTicket(userName, tickets);
    }
}

// Main Class
public class TicketBookingDemo {
    public static void main(String[] args) {
        TicketCounter counter = new TicketCounter();

        UserThread u1 = new UserThread(counter, "User 1", 2);
        UserThread u2 = new UserThread(counter, "User 2", 3);
        UserThread u3 = new UserThread(counter, "User 3", 2);

        u1.start();
        u2.start();
        u3.start();
    }
}
