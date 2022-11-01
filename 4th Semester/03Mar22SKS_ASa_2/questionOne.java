package q1;

import java.util.*;

class variable{
    static int var;
    int amt;
    variable(int v, int amt){
        var = v;
        this.amt = amt;
    }
    void increment(){
        var += amt;
        System.out.println("The value after increment is " + var);
    }
    void decrement(){
        var -= amt;
        System.out.println("The value after decrement is " + var);
    }
}
class inr extends Thread{
    variable v;
    inr(String name, variable v){
        super(name);
        this.v = v;
    }
    @Override
    public void run(){
        // System.out.println(this.getName() + " is running");
        v.increment();
    }
}

class dcr extends Thread{
    variable v;
    dcr(String name, variable v){
        super(name);
        this.v = v;
    }
    @Override
    public void run(){
        // System.out.println(this.getName() + " is running");
        v.decrement();
    }
}

public class questionOne {
    public static void main(String[] args){
        int var = 30;
        int amt;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a number");
        amt = in.nextInt();
        for(; var<=50; var++){
            variable v = new variable(var, amt);
            inr i1 = new inr("Inr1", v);
            dcr d1 = new dcr("Dcr1", v);
            inr i2 = new inr("Inr2", v);
            dcr d2 = new dcr("Dcr2", v);
            i1.start();
            i2.start();
            d1.start();
            d2.start();
            try{
                i1.join();
                i2.join();
                d1.join();
                d2.join();
            }catch(InterruptedException e){
                System.out.println("Interrupted");
            }
            System.out.println("The value of the variable after all these operations is " + variable.var);
        }

    }
}
