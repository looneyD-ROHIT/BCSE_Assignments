

import java.util.Scanner;

class StudentNew{
    String roll;
    String name;
    int score;


    public StudentNew(){
        roll = ""; // Default
        name = ""; // Default
        score = 0; // Default
    }
    
    public StudentNew(String name, String roll) {
    	this.roll = roll;
    	this.name = name;
    	this.score = 0;
    }

    public String getRoll() { return roll;  }
    public void setRoll(String roll) {  this.roll = roll; }
    
    public String getName() {  return name;  }
    public void setName(String name) { this.name = name;  }
    
    public int getScore() { return score;   }
    public void setScore(int score) throws Exception {
    	if(score > 100 ) { // If score is greater than 100 raise Exception
    		throw new Exception("Score can't be greater than 100");
    	}else if(score < 0) {// If score is a negative number  raise Exception
    		throw new Exception("Score can't be negative number");
    	}
        this.score = score;
    }

    public void display(){
        System.out.println("Student name : "+name);
        System.out.println("Roll no : "+roll);
        System.out.println("Socre : "+score);
    }
}

public class q5 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name : ");
        String name = sc.nextLine();
        System.out.print("Enter roll no : ");
        String roll = sc.nextLine();

        
        StudentNew s1 = new StudentNew(name , roll);
        // s1.display();
        
		try {
	        System.out.print("Enter score : ");
	        int score = sc.nextInt();
	        s1.setScore(score);
            s1.display();		
	        
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		
        
        sc.close();
    }
}
