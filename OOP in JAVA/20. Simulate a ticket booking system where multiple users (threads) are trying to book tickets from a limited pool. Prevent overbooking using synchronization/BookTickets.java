class sm {
	int n;

	sm(int Tno) {
		n = Tno;
	}

	synchronized void book(Thread t) {
		if (n > 0) {
			System.out.println(t.getName() + " booked a ticket");
			n = n - 1;
		}
	}
}

class MyThread implements Runnable {
	Thread t;
	sm Tickets;

	MyThread(sm sv, String tname) {
		Tickets = sv;
		t = new Thread(this, tname);
		t.start();
	}

	public void run() {
		Tickets.book(t);
	}
}

class BookTickets {
	public static void main(String args[]) {
		sm tic = new sm(5);
		
		MyThread T1 = new MyThread(tic, "RAM");
		MyThread T2 = new MyThread(tic, "SAM");
		MyThread T3 = new MyThread(tic, "Rahul");
		MyThread T4 = new MyThread(tic, "amit");
		MyThread T5 = new MyThread(tic, "sumit");
		MyThread T6 = new MyThread(tic, "Raj");
		MyThread T7 = new MyThread(tic, "Rohit");
		MyThread T8 = new MyThread(tic, "virat");
	}
}