import java.util.Scanner;

import bookList.Book;
import bookList.BookAddStatus;
import bookList.BookList;
import memberList.DOB;
import memberList.Member;
import memberList.MemberAddStatus;
import memberList.MemberList;
import transactionList.TransactionList;

public class LibrarySystem implements library{
	BookList bookList ;
	TransactionList transactionList;
	MemberList memberList ;
	
	public LibrarySystem() {
		bookList = new BookList();
		transactionList = new TransactionList();
		memberList = new MemberList();
	}

	@Override
	public void addBook() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Book ID : ");
		String id = sc.nextLine();
		System.out.print("Book Title : ");
		String title = sc.nextLine();
		System.out.print("No of copies purchased : ");
		int noOfCopiesPurchased = sc.nextInt();
		sc.nextLine();
		BookAddStatus status = bookList.addBook(new Book(id, title, noOfCopiesPurchased));
		if(status == BookAddStatus.ADDED) {
			System.out.println("\nBook added successfully !\n");
		}else if(status == BookAddStatus.ID_EXISTS) {
			System.out.println("\nBook with same ID already exists !\n");
		}else if(status == BookAddStatus.ARRAY_OVERFLOW){
			System.out.println("\nArray of booklist has been reached its max level. Book add failed !\n");
		}else {
			System.out.println("\nAdding book -- Failed due to unexpected reason !\n");
		}		
	}

	@Override
	public void searchBook() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter book id : ");
		String id = sc.nextLine();
		Book book = bookList.getBook(id);
		if(book == null) {
			System.out.println("Book bearing id "+id+" doesn't exists !");
		}else {
			book.display();
		}
	}

	@Override
	public void displayAllBooks() {
		bookList.displayAll();
	}

	@Override
	public void addMember() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Member ID : ");
		String id = sc.nextLine();
		System.out.print("Member Name : ");
		String name = sc.nextLine();
		System.out.print("Member DOB day : ");
		int day = sc.nextInt();
		sc.nextLine();
		System.out.print("Member DOB month : ");
		int month = sc.nextInt();
		sc.nextLine();
		System.out.print("Member DOB year : ");
		int year = sc.nextInt();
		sc.nextLine();
		DOB dob = new DOB(day, month, year);
		MemberAddStatus status = memberList.addMember(new Member(id, name, dob));
		if(status == MemberAddStatus.ADDED) {
			System.out.println("Member added successfully !\n");
		}else if(status == MemberAddStatus.ID_EXISTS) {
			System.out.println("Member bearing id "+id+" already exists !\n");
		}else if(status == MemberAddStatus.ARRAY_OVERFLOW) {
			System.out.println("Array of memberlist has been reached its max limit, Member add failed !\n");
		}else {
			System.out.println("\nAdding member -- Failed due to unexpected reason !\n");
		}
	}

	@Override
	public void searchMember() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter member id : ");
		String id = sc.nextLine();
		Member member = memberList.getMember(id);
		if(member == null) {
			System.out.println("Member bearing id "+id+" doesn't exists !");
		}else {
			member.display();
		}		
	}

	@Override
	public void viewAllMembers() {
		memberList.displayAll();
	}

	@Override
	public void issueBook() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter member id : ");
		String memberId = sc.nextLine();
		System.out.print("Enter book id : ");
		String bookId = sc.nextLine();
		transactionList.issueBook(memberId, bookId, bookList, memberList);
	}

	@Override
	public void returnBook() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter member id : ");
		String memberId = sc.nextLine();
		System.out.print("Enter book id : ");
		String bookId = sc.nextLine();
		transactionList.returnBook(memberId, bookId, bookList, memberList);
	}

	@Override
	public void displayAllTransactions() {
		transactionList.displayAll();
	}

	
	
}
