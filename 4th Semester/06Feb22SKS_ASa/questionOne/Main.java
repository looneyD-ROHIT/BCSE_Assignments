// /*
// Each customer of a bank has customer id, name, and current loan amount and phone number. One
// can change the attributes like name, phone number. A customer may ask for loan of certain 
// amount. It is granted provided the sum of current loan amount and asked amount does not 
// exceed credit limit (fixed amount for all customer). A customer may be a privileged amount. 
// For such customers credit limit is higher. Once a loan is sanctioned necessary updates 
// should be made. Any type of customer should be able to find his credit limit, current loan 
// amount and amount of loan he can seek. 
// Design and implement the classes.
// */

// import java.util.*;

// class BankAcc {
//     // data members
//     String customerId;
//     String name;
//     double loanAmount;
//     long phoneNo;
//     String isPriviledged;
//     static double creditLimit = 100000;

//     // methods
//     double getCreditLimit(){
//         return creditLimit;
//     }
//     double getLoanAmount(){
//         return loanAmount;
//     }
//     double allowedLoanAmout(){
//         return (creditLimit-loanAmount)>0?(creditLimit-loanAmount):-1;
//     }
//     // set new credit limit
//     void setCreditLimit(){
//         if(isPriviledged.equals("yes")){
//             Scanner in = new Scanner(System.in);
//             System.out.println("Enter the new credit limit");
//             double newCreditLimit = in.nextDouble();
//             if(newCreditLimit>creditLimit){
//                 creditLimit = newCreditLimit;
//             }
//         }else{
//             System.out.println("You are not a priviledged customer");
//         }
//     }


// }

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


public class Main {


	public static void main(String[] args) {
		Customer.creditLimit = 100000;

		Customer cust1 = new Customer("Rohit", "99999XXXXX");
		Customer cust2 = new Customer("Rohan", "88888XXXXX");

		cust2.upgradeToPriviliged(200000);

		cust1.showDetails();
		cust2.showDetails();

		if(cust1.askAmount(19000)) {
			System.out.println("Loan credited !");
		}
		else{
			System.out.println("Loan credit failed !");
		};

		if(cust2.askAmount(300000)) {
			System.out.println("Loan credited !");
		}
		else{
			System.out.println("Loan credit failed !");
		};

		cust1.showDetails();
		cust2.showDetails();
	}

}
