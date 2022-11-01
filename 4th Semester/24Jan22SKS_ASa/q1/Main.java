/*
Write a program to accept two short integers from user and display the sum.
*/
import java.util.Scanner;

public class Main{
    public static void main(String [] args){
        // System.out.println("Hello World!");
        Scanner in = new Scanner(System.in);
        System.out.println("Enter two short integers:");
        short a = in.nextShort();
        short b = in.nextShort();
        System.out.println("Result: " + (a+b));
    }
}