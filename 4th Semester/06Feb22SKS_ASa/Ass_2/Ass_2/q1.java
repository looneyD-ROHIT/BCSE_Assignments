//package ass_2;

import java.util.Scanner;

class Bank_Account {
    private int account;
    private static int interest;
    private double balance;

    public Bank_Account(int account_no, double balance){
        account=account_no;
        this.balance = balance;
    }

    public static void init() {
    	interest = 0;
    }

    public static int getInterest() {
        return interest;
    }

    public static void setInterest(int interest_u) {
    	interest = interest_u;
    }

    public double getBalance() {
        return balance;
    }

    public int getAccountNo() {
    	return this.account;
    }

    double calculateInterest(int years){
        double totalInterest;
        totalInterest = (balance*years*interest)/100;
        return totalInterest;
    }
}

public class q1 {
    public static void main(String[] args) {
    	Bank_Account.init();

        Scanner sc = new Scanner(System.in);
        //Interest Rate
        System.out.print("Enter interest rate in per-cent: ");
        int interest = sc.nextInt();
        Bank_Account.setInterest(interest);

        System.out.println("Interest rate : "+Bank_Account.getInterest());

        System.out.print("Enter account number : ");
        int acc_num = sc.nextInt();

        System.out.print("Enter balance : ");
        double balance = sc.nextDouble();

        Bank_Account Bank_Account = new Bank_Account(acc_num, balance);

        System.out.println("Account no : " + Bank_Account.getAccountNo());
        System.out.println("Balance : " + Bank_Account.getBalance());

        System.out.print("Enter number of years for calulate interest : ");
        int years=sc.nextInt();

        double y = Bank_Account.calculateInterest(years);
        System.out.println("For "+years+" years total interest : "+y);

        sc.close();
    }
}
