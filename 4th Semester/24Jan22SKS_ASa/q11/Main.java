/*
Each Instructor has name and phone number. One can view instructor information and 
set the information. Textbook has a title, author name and publisher. One can set 
the data for a textbook and view the same. Each course has a course name, instructor 
and text book. One can set the course data and view the same.  Design and implement 
the classes .
*/
class Instructor {
    String name;
    long phNo;

    // constructor
    Instructor(String name, long phNo) {
        this.name = name;
        this.phNo = phNo;
    }

    // copy constructor
    Instructor(Instructor i) {
        this.name = i.name;
        this.phNo = i.phNo;
    }

    // display
    public void display(){
        System.out.println("----------------------------------");
        System.out.println("Instructor:");
        System.out.println("Name: " + this.name);
        System.out.println("Phone: " + this.phNo);
        // System.out.println("----------------------------------");
    }

    // setter
    public void setter(String name, long phNo){
        this.name = name;
        this.phNo = phNo;
    }
}

class TextBook {
    String title;
    String authorName;
    String publisher;

    // constructor
    TextBook(String title, String authorName, String publisher) {
        this.title = title;
        this.authorName = authorName;
        this.publisher = publisher;
    }

    // copy constructor
    TextBook(TextBook t) {
        this.title = t.title;
        this.authorName = t.authorName;
        this.publisher = t.publisher;
    }

    // display
    public void display(){
        System.out.println("----------------------------------");
        System.out.println("TextBook:");
        System.out.println("Title: " + this.title);
        System.out.println("Author Name: " + this.authorName);
        System.out.println("Publisher: " + this.publisher);
        // System.out.println("----------------------------------");
    }

    // setter
    public void setter(String title, String authorName, String publisher){
        this.title = title;
        this.authorName = authorName;
        this.publisher = publisher;
    }
}

class Course {
    private String course;
    private Instructor instructor;
    private TextBook textbook;

    // constructor
    Course(String course, Instructor instructor, TextBook textbook) {
        this.instructor = new Instructor(instructor);
        this.textbook = new TextBook(textbook);
        this.course = course;
    }

    // copy constructor
    Course(Course c) {
        this.instructor = new Instructor(c.instructor);
        this.textbook = new TextBook(c.textbook);
        this.course = c.course;
    }

    // display
    public void display(){
        System.out.println("<<---------------------------------->>");
        System.out.println("Course:");
        System.out.println("Course: " + this.course);
        // instructor display call
        this.instructor.display();
        // textbook display call
        this.textbook.display();
        // System.out.println("----------------------------------");
    }

    public void setter(String course, Instructor instructor, TextBook textbook) {
        this.instructor = new Instructor(instructor);
        this.textbook = new TextBook(textbook);
        this.course = course;
    }

}
public class Main {
    public static void main(String[] args){
        // Instructor:
        // System.out.println("Instructor:");
        Instructor i1 = new Instructor("Rohit", 1234567890L);
        i1.display();
        i1.setter("abcd", 9999999999L);
        i1.display();
        // copy constructor
        Instructor i2 = new Instructor(i1);
        i2.display();
        
        // TextBook:
        // System.out.println("TextBook:");
        TextBook t1 = new TextBook("aaaa","bbbb","cccc");
        t1.display();
        t1.setter("abcd", "efgh", "ijkl");
        t1.display();
        // copy constructor
        TextBook t2 = new TextBook(t1);
        t2.display();
        
        // Course:
        // System.out.println("Course:");
        Course c1 = new Course("courseName_1",i1,t1);
        c1.display();
        c1.setter("courseName_2", i2, t2);
        c1.display();
        // copy constructor
        Course c2 = new Course(c1);
        c2.display();


    }
}
