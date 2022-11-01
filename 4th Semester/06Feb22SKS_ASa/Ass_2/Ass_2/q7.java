import java.util.LinkedList;

public class q7 {
	public static void main(String[] args) throws InterruptedException
	{
		final Process x = new Process();

		// producer thread
		Thread t_1 = new Thread(new Runnable() {
			@Override
			public void run()
			{
				try {
					x.produce();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});

		// consumer thread
		Thread t_2 = new Thread(new Runnable() {
			@Override
			public void run()
			{
				try {
					x.consume();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});

		t_1.start();
		t_2.start();
		t_1.join();
		t_2.join();
	}

	public static class Process {
		LinkedList<Integer> list = new LinkedList<>();
		int capacity = 5;

		public void produce() throws InterruptedException
		{
			int value = 0;
			while (true) {
				synchronized (this)
				{
					while (list.size() == capacity)
						wait();
					System.out.println("Producer working at " + value);
					list.add(value++);
					notify();
					Thread.sleep(100);
				}
			}
		}

		public void consume() throws InterruptedException
		{
			while (true) {
				synchronized (this)
				{
					while (list.size() == 0)
						wait();
					int val = list.removeFirst();
					System.out.println("Consumer working at " + val);
					notify();
					Thread.sleep(100);
				}
			}
		}
	}
}
