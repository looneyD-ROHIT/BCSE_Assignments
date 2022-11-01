package bookList;

public class Book {
	String id;
	String title;
	int total_copies; // Total no of copies purchased
	int available_copies; // Total no of copies available in library
	
	public Book(){
		this.id = "";
		this.title = "";
		this.total_copies = 0;
	}
	
	public Book(String id, String title, int copies){
		this.id = id;
		this.title = title;
		this.total_copies = copies;
		this.available_copies = copies;
	}
	
	
	public void setId( String id ){ this.id = id; }
	public void setTitle( String title ){ this.title = title; }
	public void addCopies(int newCopiesCount) {
		total_copies = total_copies + newCopiesCount;
		available_copies = available_copies + newCopiesCount;
	}
	
	public void setTotalCopies(int total_book_copies) {
		int count_difference = total_copies - total_book_copies; // Calulate difference between already available copies' count and the new one
		total_copies = total_copies + count_difference;
		available_copies = available_copies + count_difference;
	}
	
	public String getId(){ return id; }
	public String getTitle(){ return title; }
	public int getTotalCopies(){ return total_copies;	}
	public int getAvailableCopies() { return available_copies; }
	
	public void display(){
		System.out.println("==================================");
		System.out.println("Id : " + id ); 
		System.out.println("Title : " + title );
		System.out.println("Total purchased copies : " + total_copies );  
		System.out.println("No of available copies : " + available_copies );  
		System.out.println("================================\n");
	}

	public boolean bookAvailable() {
		if(available_copies <= 0 ) return false;
		return true;
	}
	
	public boolean issue(){
		if(!bookAvailable()) return false;
		this.available_copies--;
		return true;
	}
	
	public boolean returnB() {
		if(available_copies >= total_copies) return false;
		this.available_copies++;
		return true;
	}
	
}
