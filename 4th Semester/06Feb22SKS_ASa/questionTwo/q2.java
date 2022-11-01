class Student{
    String name ;
    int ph;
    String email;
    String [] address;
    int roll;
    String course;
    Student(String n, int num, String e, String[] a, int r, String c){
        name = n;
        ph = num;
        email = e;
        address = a;
        roll = r;
        course = c;
    }
    void display(){
        System.out.println("Name: " + name);
        System.out.println("Phone Number: " + ph);
        System.out.println("Email: " + email);
        System.out.println("Address: " + address[0] + " " + address[1] + " " + address[2]+ " " + address[3] + " " + address[4]);
        System.out.println("Roll Number: " + roll);
        System.out.println("Course: " + course);
    }
    void chng_name(String n){
        name = n;
    }
    void chng_ph(int num){
        ph = num;
    }
    void chng_email(String e){
        email = e;
    }
    
    void chng_roll(int r){
        roll = r;
    }
    void chng_course(String c){
        course = c;
    }
    void chng_premisses(String a){
        address[0] = a;
    }
    void chng_street(String a){
        address[1] = a;
    }
    void chng_city(String a){
        address[2] = a;
    }
    void chng_pin(String a){
        address[3] = a;
    }
    void chng_state(String a){
        address[4] = a;
    }
}
class Faculty{
    String name ;
    int ph;
    String email;
    String [] address;
    String dept;
    int emp_id;
    String specialisation;
    Faculty(String n, int num, String e, String[] a, String d, int id, String s){
        name = n;
        ph = num;
        email = e;
        address = a;
        dept = d;
        emp_id = id;
        specialisation = s;
    }
    void display(){
        System.out.println("Name: " + name);
        System.out.println("Phone Number: " + ph);
        System.out.println("Email: " + email);
        System.out.println("Address: " + address[0] + " " + address[1] + " " + address[2]+ " " + address[3] + " " + address[4]);
        System.out.println("Department: " + dept);
        System.out.println("Employee ID: " + emp_id);
        System.out.println("Specialisation: " + specialisation);
    }
    void chng_name(String n){
        name = n;
    }
    void chng_ph(int num){
        ph = num;
    }
    void chng_email(String e){
        email = e;
    }
    void chng_dept(String d){
        dept = d;
    }
    void chng_emp_id(int id){
        emp_id = id;
    }
    void chng_specialisation(String s){
        specialisation = s;
    }
    void chng_premisses(String a){
        address[0] = a;
    }
    void chng_street(String a){
        address[1] = a;
    }
    void chng_city(String a){
        address[2] = a;
    }
    void chng_pin(String a){
        address[3] = a;
    }
    void chng_state(String a){
        address[4] = a;
    }

}

public class q2 {
    public static void main(String[] args) {
      String [] address = new String[5];
        address[0] = "Premisses1";
        address[1] = "Street1";
        address[2] = "City1";
        address[3] = "Pin1";
        address[4] = "State1";

     Student std = new Student( "A" , 1234567890 , "asdad", address, 123, "CSE");
     System.out.println("Student Details intially");
        std.display();
        std.chng_name("B");
        std.chng_ph(1234567891);
        std.chng_email("asdad");
        std.chng_roll(1234);
        std.chng_course("ECE");
        std.chng_premisses("Premisses2");
        std.chng_street("Street2");
        std.chng_city("City2");
        std.chng_pin("Pin2");
        std.chng_state("State2");
        System.out.println(" ");
        System.out.println(" ");
        System.out.println("Student Details finally");
        std.display();
        System.out.println("\n\n ");
        // System.out.println(" ");
    Faculty fac = new Faculty("C", 1234567890, "asdad", address, "CSE", 123, "ECE");
    System.out.println("Faculty Details intially");
        fac.display();
        fac.chng_name("D");
        fac.chng_ph(1234567891);
        fac.chng_email("asdab");
        fac.chng_dept("ETCE");
        fac.chng_emp_id(1234);
        fac.chng_specialisation("TEXAS");
        fac.chng_premisses("Premisses2");
        fac.chng_street("Street2");
        fac.chng_city("City2");
        fac.chng_pin("Pin2");
        fac.chng_state("State2");
        System.out.println("\n\n");
        // System.out.println(" ");
        System.out.println("Faculty Details finally");
        fac.display();
        System.out.println("\n\n ");
        // System.out.println(" ");

    }
}
