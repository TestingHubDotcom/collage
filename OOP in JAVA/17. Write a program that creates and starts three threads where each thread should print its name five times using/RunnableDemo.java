// 17(a) Using Runnable Interface
// Using Runnable Interface
class MyRunnable implements Runnable {
    private String threadName;

    MyRunnable(String name) {
        threadName = name;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(threadName + " - " + i);
        }
    }
}

public class RunnableDemo {
    public static void main(String[] args) {

        Thread t1 = new Thread(new MyRunnable("Thread 1"));
        Thread t2 = new Thread(new MyRunnable("Thread 2"));
        Thread t3 = new Thread(new MyRunnable("Thread 3"));

        t1.start();
        t2.start();
        t3.start();
    }
}
