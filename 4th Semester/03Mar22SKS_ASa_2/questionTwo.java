package q2;

import java.util.*;

class variable{
    int var;
    int amt;
    variable(int v, int amt){
        var = v;
        this.amt = amt;
    }
    public synchronized void increment(){
        var += amt;
        System.out.println("The value after increment is " + var);

    }
    public synchronized void decrement(){
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

public class questionTwo {
    public static void main(String[] args){
        int var = 0;
        int amt;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a number");
        amt = in.nextInt();
        for(; var<100; var++){
            variable v = new variable(var, amt);
            inr i = new inr("Inr", v);
            dcr d = new dcr("Dcr", v);
            i.start();
            try{
                i.join();
            }catch(InterruptedException e){
                System.out.println("Interrupted");
            }
            d.start();
            try{
                d.join();
            }catch(InterruptedException e){
                System.out.println("Interrupted");
            }
            System.out.println("The value of the variable after all these operations is " + v.var);
        }

    }
}
