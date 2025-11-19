class Buffer {
    private int data;
    private boolean available = false; // buffer empty initially

    // Producer puts data
    synchronized void produce(int value) {
        while (available) {
            try {
                wait(); // wait if buffer is full
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
        data = value;
        available = true;
        System.out.println("Produced: " + value);
        notify(); // wake up consumer
    }

    // Consumer takes data
    synchronized int consume() {
        while (!available) {
            try {
                wait(); // wait if buffer is empty
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
        System.out.println("Consumed: " + data);
        available = false;
        notify(); // wake up producer
        return data;
    }
}

// Producer Thread
class Producer extends Thread {
    Buffer b;

    Producer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            b.produce(i);
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }
        }
    }
}

// Consumer Thread
class Consumer extends Thread {
    Buffer b;

    Consumer(Buffer b) {
        this.b = b;
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            b.consume();
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }
        }
    }
}

// Main class
public class ProducerConsumerDemo {
    public static void main(String[] args) {
        Buffer b = new Buffer();

        Producer p = new Producer(b);
        Consumer c = new Consumer(b);

        p.start();
        c.start();
    }
}
