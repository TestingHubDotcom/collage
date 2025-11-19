class FactorialThread extends Thread {
    int num;

    FactorialThread(int num) {
        this.num = num;
    }

    public void run() {
        long fact = 1;

        for (int i = 1; i <= num; i++) {
            fact *= i;
        }

        System.out.println("Thread: " + Thread.currentThread().getName() +
                " | Number: " + num +
                " | Factorial: " + fact);
    }
}

public class FactorialDemo {
    public static void main(String[] args) {
        // numbers for which factorial will be calculated
        int numbers[] = { 5, 7, 10 };

        // create and start one thread per number
        for (int n : numbers) {
            FactorialThread ft = new FactorialThread(n);
            ft.start();
        }
    }
}
