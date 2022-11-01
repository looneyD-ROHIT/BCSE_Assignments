import java.util.Scanner;

import memberList.Member;

public class LibraryTest {
	public static void main(String[] args) {
		int choice;

		Scanner sc = new Scanner(System.in);
		
		Member.bookIssueLimit = 2; // Set book limit per member
		LibrarySystem librarySystem = new LibrarySystem();
		
		do {
			System.out.println("\nLibrary system \nPick options from below list\n");
			System.out.println("1. Add Book");
			System.out.println("2. Search Book");
			System.out.println("3. Display all books");
			System.out.println("4. Add Member");
			System.out.println("5. Search Member");
			System.out.println("6. View All Members");
			System.out.println("7. Issue Book");
			System.out.println("8. Return Book");
			System.out.println("9. Display all transactions");
			System.out.println("10. Exit");
			System.out.print("Enter your choice : ");
			choice = sc.nextInt();
			sc.nextLine();
			System.out.print("\n\n");
			switch (choice) {
			case 1:
				librarySystem.addBook();
				break;
			case 2:
				librarySystem.searchBook();
				break;
			case 3:
				librarySystem.displayAllBooks();
				break;
			case 4:
				librarySystem.addMember();
				break;
			case 5:
				librarySystem.searchMember();
				break;
			case 6:
				librarySystem.viewAllMembers();
				break;
			case 7:
				librarySystem.issueBook();
				break;
			case 8:
				librarySystem.returnBook();
				break;
			case 9:
				librarySystem.displayAllTransactions();
				break;
			case 10:
				System.out.println("Programme exiting ....");
				System.exit(0);
			default:
				break;
			}
		} while (true);
		
		
	}

}
