package transactionList;


import bookList.Book;
import bookList.BookList;
import memberList.Member;
import memberList.MemberList;

public class TransactionList {
	Transaction transactionArr[];
	int noOfTransactions;
	int maxAllowedTransactions;
	
	public TransactionList(){
		maxAllowedTransactions = 100;
		transactionArr = new Transaction[maxAllowedTransactions];
		noOfTransactions = 0;
	}
	
	public TransactionList(int transaction_arr_size){
		maxAllowedTransactions = transaction_arr_size;
		transactionArr = new Transaction[maxAllowedTransactions];
		noOfTransactions = 0;
	}
	
	// display and display all
	public void display(String memberId, String bookId) {
		Transaction transaction = getTransaction(memberId, bookId);
		if(transaction == null) {
			System.out.println("Transaction doesn't exists");
		}else {
			transaction.display();
		}
	}
	
	public void displayAll() {
		System.out.println("Total "+noOfTransactions+" transactions found !");
		for(int i = 0 ; i < noOfTransactions ; i++) {
			transactionArr[i].display();
		}
	}
	
	public Transaction getTransaction(String memberId, String bookId) {
		for(int i = 0 ; i < noOfTransactions; i++) {
			if(transactionArr[i].bookId.equals(bookId) && transactionArr[i].memberId.equals(memberId)) {
				return transactionArr[i];
			}
		}
		return null;
	}

	boolean addTransaction(Transaction transaction) {
		if(noOfTransactions >= maxAllowedTransactions) return false;
		transactionArr[noOfTransactions++] = transaction;
		return true;
	}
	
	public void issueBook(String memberId, String bookId, BookList bookList, MemberList memberList) {
		// Verify book details
		Book book = bookList.getBook(bookId);
		if(book == null) {
			System.out.println("Book not found !");
			return;
		}else if(!book.bookAvailable()) {
			System.out.println("No copies of book available");
			return;
		}
		
		// Verify member details
		Member member = memberList.getMember(memberId);
		if(member == null) {
			System.out.println("Member not found !");
			return;
		}else if (!member.validForNewIssue()) {
			System.out.println("Member has already reached his book issue limit . Can't issue more books.");
			return;
		}
		
		// Add in transaction
		Transaction transaction = new Transaction(memberId, bookId);
		if(addTransaction(transaction)) {
			// Issue copy of book from book list
			book.issue();
			// update in member
			member.issueBook();
			
			System.out.println("Book issued successfully !");
			System.out.println("Transaction details -- ");
			transaction.display();
		}else {
			System.out.println("More transactions can't be added");
		}
	}
	
	public void returnBook(String memberId, String bookId, BookList bookList, MemberList memberList) {
		// Check transaction details
		Transaction transaction = getTransaction(memberId, bookId);
		if(transaction == null) {
			System.out.println("Sorry transaction not found !");
		}else {
			Book book = bookList.getBook(transaction.bookId);
			if(book == null){
				System.out.println("Invalid book id in transaction record !");
				return;
			}
			Member member = memberList.getMember(transaction.memberId);
			if(member == null) {
				System.out.println("Invalid member id in member record !");
				return;
			}
			
			
			if(transaction.returnBook()) {
				if(member.returnBook() && book.returnB()) {
					System.out.println("Book returned successfully !");
				}else {
					System.out.println("Book return failed !");
				}
			}else {
				System.out.println("Book return failed ! Maybe");
			}
		}
	}
}
