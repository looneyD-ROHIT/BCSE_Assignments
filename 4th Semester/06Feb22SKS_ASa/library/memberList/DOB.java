package memberList;

public class DOB{
	int day;
	int month;
	int year;
	
	public DOB(int day, int month,int  year){
		this.day = day;
		this.month = month;
		this.year = year;
	}

	public void setDay(int day) {this.day = day;}
	public void setMonth(int month) {this.month = month;}
	public void setYear(int year) {	this.year = year;}
	
	public String toDOBString() {
		return day+"-"+month+"-"+year;
	}
}