package transactionList;

import java.time.LocalDate;

public class Transaction {
	String memberId;
	String bookId;
	String issuedDate;
	boolean isReturned;
	
	public Transaction() {
		memberId = "";
		bookId = "";
		issuedDate = "";
		isReturned = false;
	}
	
	Transaction(String memberId, String bookId) {
		this.memberId = memberId;
		this.bookId = bookId;
		this.isReturned = false;
		issuedDate = LocalDate.now().toString();
	}
	
	public String getMemberId() {return memberId;}
	public void setMemberId(String memberId) {this.memberId = memberId;}
	public String getBookId() {return bookId;}
	public void setBookId(String bookId) {this.bookId = bookId;}
	public boolean getReturnStatus() {return isReturned;}

	void display() {
		System.out.println("==================================");
		System.out.println("Member ID : "+memberId);
		System.out.println("Book ID : "+bookId);
		System.out.println("Issued Date : "+issuedDate);
		System.out.println("==================================\n");

	}
	
	boolean returnBook() {
		if(isReturned) return false;
		isReturned = true;
		return true;
	}	
}
