/*
Design a Metric class that supports Kilometre to Mile conversion with distance in 
Kilometre as argument and Mile to Kilometre conversion with distance in mile as 
argument. Assume, one Mile equals 1.5 Kilometre.
*/
// package q10

import java.util.*;

class Metric {
    private double distance;
    Metric(){
        this.distance = 0.0;
    }
    Metric(double distance){
        this.distance = distance;
    }
    public static void kmToMile(double distance){
        System.out.println("----------------------------------");
        System.out.println("Distance in miles: " + distance/1.5);
        System.out.println("----------------------------------");
    }
    public static void mileToKm(double distance){
        System.out.println("----------------------------------");
        System.out.println("Distance in kms: " + distance*1.5);
        System.out.println("----------------------------------");
    }
}

public class Main {
    public static void main(String[] args){
        // km to mile conversion
        System.out.println("Enter the distance in kms:");
        Scanner in = new Scanner(System.in);
        double distance = in.nextDouble();
        Metric.kmToMile(distance);
        
        // mile to km conversion
        System.out.println("Enter the distance in miles:");
        distance = in.nextDouble();
        Metric.mileToKm(distance);

    }
}
