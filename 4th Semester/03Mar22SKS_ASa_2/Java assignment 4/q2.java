class operation{
    int n;
    static int num;
    operation(int x, int amt){
        n = x;
        num = amt;
    }
    void add(){
        num += n;
        System.out.println("Value after increment is "+ num);
    }
    void subs(){
        num-=n;
        System.out.println("Value after decrement is "+ num);
    }
}
class adding extends Thread{
    operation x;
    adding(operation a){
        x = a;
    }

    @Override
    public void run(){
        synchronized(x){
        x.add();
        }
    }
}

class subs extends Thread{
    operation x;
    subs(operation a){
        x = a;
    }

    @Override
    public void run(){
        synchronized(x){
            x.subs();
            }
        
    }
}

public class q2 {
    public static void main(String args[]){
        for(int i=10; i<=100; ++i){
            operation a = new operation(5, i);
            adding A1 = new adding(a);
            adding A2 = new adding(a);
            subs S1 = new subs(a);
            subs S2 = new subs(a);
            A1.start();
            A2.start();
            S1.start();
            S2.start();
            try{
            A1.join();
            A2.join();
            S1.join();
            S2.join();
            }
            catch(Exception e){
                System.out.println("Blocked");
            }
            System.out.println("The final result for i= "+i+" is "+a.num);
        }
    }
}
