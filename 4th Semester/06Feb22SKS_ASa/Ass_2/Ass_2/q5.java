class Customer{
	int id;
	String name;
	String phone_number;
	int loanAmount;

	public static int lastId;
	public static int creditLimit;

	boolean isPriviliged = false;
	int priviligedCreditLimit = 0;

	Customer(String name, String phone_number){
		lastId++;
		this.id = lastId;
		this.name = name;
		this.phone_number = phone_number;
		this.loanAmount = 0;
	}

	String getName() {
		return this.name;
	}

	String getphone_number() {
		return this.phone_number;
	}

	void setName(String name) {
		this.name = name;
	}

	void setphone_number(String phone_number) {
		this.phone_number = phone_number;
	}

	boolean askAmount(int amount) {
		if((loanAmount + amount) > getCreditLimit()) {
			return false;
		}

		loanAmount = loanAmount + amount;
		return true;

	}

	boolean upgradeToPriviliged(int amount) {
		if(isPriviliged) return false;
		isPriviliged = true;
		priviligedCreditLimit = amount;
		return true;
	}

	int getCreditLimit() {
		if(isPriviliged) {
			return priviligedCreditLimit;
		}
		return creditLimit;
	}

	int getLoanAmount() {
		return loanAmount;
	}

	int getAvailableLoanAmount() {
		return getCreditLimit() - loanAmount;
	}

	void showDetails() {
		System.out.println("==================================");
		System.out.println("Id : "+id);
		System.out.println("Type : " + (!isPriviliged ? "Normal" : "Priviliged"));
		System.out.println("Name : "+name);
		System.out.println("Phone No : "+ phone_number);
		System.out.println("Credit limit : "+getCreditLimit());
		System.out.println("Loan amount : "+getLoanAmount());
		System.out.println("Available for loan : "+getAvailableLoanAmount());
		System.out.println("==================================");
	}

}


public class q5 {


	public static void main(String[] args) {
		Customer.creditLimit = 100000;

		Customer c1 = new Customer("Rishav Pramanik", "12345XXXXX");
		Customer c2 = new Customer("Jadavpur University", "85479XXXXX");

		c2.upgradeToPriviliged(300000);

		c1.showDetails();
		c2.showDetails();

		if(c1.askAmount(25000)) {
			System.out.println("Loan credited !");
		}
		else{
			System.out.println("Loan credit failed !");
		};

		if(c2.askAmount(250000)) {
			System.out.println("Loan credited !");
		}
		else{
			System.out.println("Loan credit failed !");
		};

		c1.showDetails();
		c2.showDetails();
	}

}
