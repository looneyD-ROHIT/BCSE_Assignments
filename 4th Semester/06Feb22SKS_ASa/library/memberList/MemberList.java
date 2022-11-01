package memberList;


public class MemberList {
	Member memberArr[];
	int noOfMembers;
	int maxAllowedMembers;
	
	public MemberList(){ // Default constructor . that will create 100 elements array
		maxAllowedMembers = 100;
		memberArr = new Member[maxAllowedMembers];
		noOfMembers = 0;
	}
	
	public MemberList(int member_arr_size){
		maxAllowedMembers = member_arr_size;
		memberArr = new Member[maxAllowedMembers];
		noOfMembers = 0;
	}
	
	
	// Add member 
	public MemberAddStatus addMember(Member member) {
		if(noOfMembers >= maxAllowedMembers) return MemberAddStatus.ARRAY_OVERFLOW;
		if(getMember(member.id) == null) {
			memberArr[noOfMembers++] = member;
			return MemberAddStatus.ADDED;
		}else {
			return MemberAddStatus.ID_EXISTS;
		}
	}	
	
	// Traverse through the array to get the member with specified id . If found will return member & if not found will return null
	public Member getMember(String id) {
		for(int i = 0; i < noOfMembers; i++) {
			if(memberArr[i].id.equals(id)){
				return memberArr[i];
			}
		}
		return null;
	}
	
	// Display a member by it's id
	public void display(String id) {
		Member member = getMember(id);
		if(member == null) System.out.println("No member found with id "+id);
		else member.display();
	}
	
	// Display all members	
	public void displayAll() {
		System.out.println("Total "+noOfMembers+" members found ! \n");
		for(int i = 0; i < noOfMembers; i++) {
			memberArr[i].display();
		}
	}
	
	
}
