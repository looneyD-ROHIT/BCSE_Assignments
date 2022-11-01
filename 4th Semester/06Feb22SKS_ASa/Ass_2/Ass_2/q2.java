
import java.util.Scanner;

class Metric {
    public static double convert_to_km(double miles){
        return 1.5*miles; // mile to km
    }
    public static double convert_to_miles(double km){
        return km/1.5; // km to mile
    }
}

public class q2 {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);

        System.out.print("Enter the distance in kilometers : ");
        double km = sc.nextDouble();
        System.out.println("Distance in Miles is "+Metric.convert_to_km(km));

        System.out.print("Enter distance in Miles: ");
        double mile = sc.nextDouble();
        System.out.println("Distance in kilometers is  "+Metric.convert_to_miles(mile));
        
        sc.close();
    }
}
