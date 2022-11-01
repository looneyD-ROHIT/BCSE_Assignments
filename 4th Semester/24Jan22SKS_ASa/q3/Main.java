/*
Write a program that accepts height in cm as int and displays the height in feet 
and inches. Assume, 1 inch equals to 2.54 cm and 1 foot equals to 30.5 cm.
*/
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        System.out.print("Enter height in cm = ");
        int height;
        Scanner in = new Scanner(System.in);
        height = in.nextInt();
        int feet = (int)((float)(height)/30.5);
        float inches = (height - feet*30.5f)/2.54f;
        System.out.println("Height in feet = " + feet + " and inch = " + inches + ".");
    }

}
