package bookList;




public class BookList {
	Book bookArr[];
	int noOfBooks;
	int maxAllowedBooks;
	
	public BookList(){ // By default create array of 100 books
		maxAllowedBooks = 100;
		bookArr = new Book[maxAllowedBooks];
		noOfBooks = 0;
	}
	
	public BookList(int book_arr_size){
		bookArr = new Book[book_arr_size];
		maxAllowedBooks = book_arr_size;
		noOfBooks = 0;
	}
	
	// Add book
	public BookAddStatus addBook(Book book) {
		if(noOfBooks >= maxAllowedBooks) return BookAddStatus.ARRAY_OVERFLOW;
		if(getBook(book.id) == null) {
			bookArr[noOfBooks++] = book;
			return BookAddStatus.ADDED;
		}else {
			return BookAddStatus.ID_EXISTS;
		}
	}

	// Traverse through the array to get the book with specified id . If found will return book & if not found will return null
	public Book getBook(String id) {
		for(int i = 0; i < noOfBooks; i++) {
			if(bookArr[i].id.equals(id)){
				return bookArr[i];
			}
		}
		return null;
	}
	
	// Display a book by it's id
	public void display(String id) {
		Book book = getBook(id);
		if(book == null) System.out.println("No book found with id "+id);
		else book.display();
	}
	
	// Display all books	
	public void displayAll() {
		System.out.println("Total "+noOfBooks+" books found ! \n");
		for(int i = 0; i < noOfBooks; i++) {
			bookArr[i].display();
		}
	}
	
}
