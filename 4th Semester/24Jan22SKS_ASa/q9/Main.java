/*
Design a BankAcct class with account number, balance and interest rate as attribute.  
Interest rate is same for all account. Support must be there to initialize, change 
and display the interest rate.  Also supports are to be there to return balance and 
calculate interest.
*/
class BankAcct {
    private int acNo;
    private double balance;
    private float rate = 5.5f;

    // constructor - 1 (by default all accounts have same rate)
    BankAcct(int acNo, double balance){
        this.acNo = acNo;
        this.balance = balance;
    }

    // constructor - 2
    BankAcct(int acNo, double balance, float rate){
        this.acNo = acNo;
        this.balance = balance;
        this.rate = rate;
    }

    // getter
    float getRate(){
        return this.rate;
    }

    // setter
    void setRate(float rate){
        this.rate = rate;
    }

    // display
    void display(){
        System.out.println("----------------------------------");
        System.out.println("Account No: " + this.acNo);
        System.out.println("Balance: " + this.balance);
        System.out.println("Rate: " + this.rate);
        System.out.println("----------------------------------");
    }
    
    // calculate interest
    void displayInterest(){
        System.out.println("----------------------------------");
        System.out.println("Interest = " + this.balance*rate*1/100);
        System.out.println("----------------------------------");
    }
}

public class Main {
    public static void main(String[] args){
        BankAcct b1 = new BankAcct(1, 1000);
        BankAcct b2 = new BankAcct(2, 1000, 10f);

        // display
        System.out.println("Normal:");
        b1.display();
        b1.displayInterest();
        
        b2.display();
        b2.displayInterest();

        // change rate
        System.out.println("After rate change:");
        b1.setRate(6f);
        System.out.println("Rate = " + b1.getRate());
        b1.display();
        b1.displayInterest();
    }
}
