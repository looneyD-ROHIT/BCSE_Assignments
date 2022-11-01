import java.io.*;
import java.util.*;

class Student implements Serializable {
	private static final long serialVersionUID = 1L;
	String name, roll;
	double score;

	Student() {
	};

	Student(String n, String r, double s) {
		name = n;
		score = s;
		roll = r;
	}

	public Student input() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Name: ");
		this.name = sc.next();
		System.out.print("Roll: ");
		this.roll = sc.next();
		System.out.print("Score: ");
		this.score = sc.nextDouble();
		return this;
	}

	@Override
	public String toString() {
		return "Name: " + name + "\nRoll: " + roll + "\nScore: " + score;
	}
}

class Prog_5 {
	public static void main(String[] args) {
		Student[] s = new Student[3];
		for (int i = 0; i < 3; i++) {
			s[i] = new Student().input();
		}
		try {
			System.out.println("\nwriting to file");
			FileOutputStream f = new FileOutputStream(new File("records.dat"));
			ObjectOutputStream o = new ObjectOutputStream(f);
			for (int i = 0; i < 3; i++) {
				o.writeObject(s[i]);
			}
			// o.writeObject(s1);
			// o.writeObject(s2);
			o.close();
			f.close();
			System.out.println("\nwriting Done");

			System.out.println("\nReading from file");
			FileInputStream ff = new FileInputStream(new File("records.dat"));
			ObjectInputStream i = new ObjectInputStream(ff);
			for (int j = 0; j < 3; j++) {
				Student temp = (Student) i.readObject();
				System.out.println(temp);
				System.out.println("\n");
			}
			i.close();
			ff.close();

			System.out.println("\nReading Done\n");

		} catch (IOException ee) {
			System.out.println("Error Occured");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

	}
}