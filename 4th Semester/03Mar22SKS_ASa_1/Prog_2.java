import java.util.*;

class Account {
	String name;
	String acc_no;
	double balance;

	Account() {
		name = null;
		acc_no = null;
		balance = -1.0;
	}

	public String getAccNo() {
		return acc_no;
	}

	public void input() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter name: ");
		name = sc.nextLine();
		System.out.print("Enter account number: ");
		acc_no = sc.next();
		System.out.print("Enter balance: ");
		balance = sc.nextDouble();
	}
}

class Query {
	HashMap<String, Double> h = new HashMap<String, Double>();

	public boolean exists(String acc_no) {
		if (h.containsKey(acc_no)) {
			// System.out.println("Account already exists.");
			return true;
		}
		return false;
	}

	public void push(Account a) {
		if (!exists(a.acc_no)) {
			h.put(a.acc_no, a.balance);
			System.out.println("Account added.");
		} else {
			System.out.println("Failed to add new account.");
		}
	}

	public double fetch(String acc) {
		if (exists(acc)) {
			return h.get(acc);
		}
		return -1.0;
	}

	public void displayAll() {
		for (String key : h.keySet()) {
			System.out.println("Account number: " + key);
			System.out.println("Balance: " + h.get(key));
			System.out.println();
		}
	}
}

public class Prog_2 {
	Query q;

	Prog_2() {
		q = new Query();
	}

	public void addAccount() {
		Account a = new Account();
		a.input();
		q.push(a);
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		System.out.println(
				"1. Add an account.\n2. Check balance of an account.\n3. Check if the account exists.\n4. Display all accounts.");
		int choice = -1;
		while (choice != 0) {
			System.out.println("Enter your choice: ");
			choice = sc.nextInt();
			switch (choice) {
			case 1:
				addAccount();
				break;
			case 2: {
				System.out.println("Enter account number: ");
				String temp_acc_no = sc.next();
				if (q.exists(temp_acc_no))
					System.out.println("The balance in the given account is : " + q.fetch(temp_acc_no));
				else
					System.out.println("Account does not exist.");
				break;
			}
			case 3: {
				System.out.println("Enter account number: ");
				if (q.exists(sc.next()))
					System.out.println("Account exists.");
				else
					System.out.println("Account does not exist.");
				break;
			}
			case 4:
				q.displayAll();
				break;
			}

		}
	}

	public static void main(String[] args) {
		Prog_2 obj = new Prog_2();
		obj.run();
	}
}
