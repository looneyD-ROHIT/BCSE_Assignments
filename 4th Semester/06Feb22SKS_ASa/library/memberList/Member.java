package memberList;

public class Member {
	String id;
	String name;
	DOB dob;
	int noOfBooksIsssued;
	public static int bookIssueLimit = 5;
	
	public Member(){
		id = "";
		dob = new DOB(0, 0, 0);
		noOfBooksIsssued = 0;
	}
	
	public Member(String id){
		this.id = id;
		dob = new DOB(0, 0, 0);
		noOfBooksIsssued = 0;
	}
	
	public Member(String id, String name, DOB dob){
		this.id = id;
		this.name = name;
		this.dob = dob;
	}
	
	public String getId() {	return id; }
	public void setId(String id) {this.id = id;}
	public String getName() {return name;}
	public void setName(String name) {this.name = name;}
	public DOB getDob() {return dob;}
	public void setDob(DOB dob) {this.dob = dob;}
	public int getNoOfBooksIsssued() {return noOfBooksIsssued;}
	
	public void display() {
		System.out.println("==================================");
		System.out.println("ID : "+id);
		System.out.println("Name : "+name);
		System.out.println("DOB : "+dob.toDOBString());
		System.out.println("No of books issued : "+noOfBooksIsssued);
		System.out.println("================================\n");
	}
	
	public boolean validForNewIssue() {
		if(noOfBooksIsssued >= bookIssueLimit) return false;
		return true;
	}
	
	public boolean issueBook() {
		if(validForNewIssue()) {
			noOfBooksIsssued++;
			return true;
		}
		return false;
	}
	
	public boolean returnBook() {
		if(noOfBooksIsssued > 0) {
			noOfBooksIsssued--;
			return true;
		};
		return false;
	}

}
