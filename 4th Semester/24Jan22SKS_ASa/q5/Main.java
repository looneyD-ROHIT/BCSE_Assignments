/*
Write a program that accepts a String and assigns it to another. Check the outcome 
of comparison with == and equals() method. Take two Strings and put same input for 
them. Repeat the equality checking. Observe the outcome.
*/
// package q5;
import java.util.*;

// == operator => checking is of : ref type (it checks whether one is reference of another)
// equals() method => checking is of : value type (it checks whether one is equal to another)
public class Main {
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        String newStr = str;
        System.out.println("By == operator: " + (newStr == str));
        System.out.println("By equals method: " + (newStr.equals(str)));
        // taking different strings
        String str1, str2;
        str1 = in.nextLine();
        str2 = in.nextLine();
        System.out.println("By == operator: " + (str1 == str2));
        System.out.println("By equals method: " + (str1.equals(str2)));
    }
}
