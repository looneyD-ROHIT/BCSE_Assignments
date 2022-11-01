/*
Write a program where class contains void show(int) to display the argument passed. 
Call the function once with short as actual parameter and again double as actual 
parameter. Add another function as void show(double) . Repeat the calls. Observe the 
outcomes in each case.
*/
// package q6;

public class Main {
    static void show(int i) {
        System.out.println("output = " + i);
    }
    static void show(double d) {
        System.out.println("output = " + d);
    }
    public static void main(String [] args){
        // using short
        short s = 10;
        show(s);

        // using double
        double d = 11.69;
        show(d);
    }
}
