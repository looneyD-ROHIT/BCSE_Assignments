import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

class Department {
	int code;
	String name;
	String location;

	public int getCode() {
		return this.code;
	}

	public void setCode(int code) {
		this.code = code;
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getLocation() {
		return this.location;
	}

	public void setLocation(String location) {
		this.location = location;
	}

	public Department(int code, String name, String location) {
		this.code = code;
		this.name = name;
		this.location = location;
	}

	public Department() {

	}

	public void inputDepartment() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Code : ");
		this.code = sc.nextInt();
		System.out.println("Name : ");
		sc.nextLine();
		this.name = sc.nextLine();
		System.out.println("Location : ");
		this.location = sc.nextLine();
	}

	@Override
	public String toString() {
		return "{" + " code='" + code + "'" + ", name='" + name + "'" + ", location='" + location + "'" + "}";
	}

	double totalPay(EmployeeList e) {
		double sum = 0;
		for (int i = 0; i < e.list.size(); i++) {
			if (e.list.get(i).deptcode == code) {
				sum += e.list.get(i).basic;
			}
		}
		return sum;
	}

}

class DepartmentList {
	ArrayList<Department> list;

	DepartmentList() {
		list = new ArrayList<Department>();
	}

	DepartmentList(int x) {
		list = new ArrayList<Department>(x);
	}

	void addDepartment() {
		Department d = new Department();
		d.inputDepartment();
		if (ifExists(d.code) == -1)
			list.add(d);
		else {
			System.out.println("Department code already exists\n");
		}
	}

	int ifExists(int c) {
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).code == c) {
				return i;
			}
		}
		return -1;
	}
}

class Employee {
	int code;
	String name;
	double basic;
	int deptcode;

	Employee() {

	}

	public Employee(int code, String name, double basic, int deptcode) {
		this.code = code;
		this.name = name;
		this.basic = basic;
		this.deptcode = deptcode;
	}

	public int getCode() {
		return this.code;
	}

	public void setCode(int code) {
		this.code = code;
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public double getBasic() {
		return this.basic;
	}

	public void setBasic(double basic) {
		this.basic = basic;
	}

	public int getDeptcode() {
		return this.deptcode;
	}

	public void setDeptcode(int deptcode) {
		this.deptcode = deptcode;
	}

	@Override
	public String toString() {
		return "{" + " code='" + code + "'" + ", name='" + name + "'" + ", basic='" + basic + "'" + ", deptcode='"
				+ deptcode + "'" + "}";
	}

	public void inputEmployee() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Code : ");
		this.code = sc.nextInt();
		System.out.println("Name : ");
		sc.nextLine();
		this.name = sc.nextLine();
		System.out.println("Basic Pay : ");
		this.basic = sc.nextDouble();
		System.out.println("Department code : ");
		this.deptcode = sc.nextInt();
	}

}

class EmployeeList {
	ArrayList<Employee> list;

	public EmployeeList() {
		list = new ArrayList<Employee>();
	}

	public EmployeeList(int s) {
		list = new ArrayList<Employee>(s);
	}

	public void addEmployee(DepartmentList d) {
		Employee e = new Employee();
		e.inputEmployee();
		if (ifExists(e.code) == -1) {
			if (d.ifExists(e.deptcode) != -1)
				list.add(e);
			else {
				System.out.println("Department code is invalid");
			}
		} else {
			System.out.println("Employee code is not unique");
		}
	}

	int ifExists(int c) {
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).code == c) {
				return i;
			}
		}
		return -1;
	}

	void displayEmployee(int c, DepartmentList e) {
		int i;
		if ((i = ifExists(c)) != -1) {
			System.out.println("Employee : ");
			System.out.println(list.get(i).toString());
			System.out.println("Department : ");
			// dept_code = list.get(i).deptcode;
			// String dept = e.list.get(dept_code)
			// int x = e.ifExists(list.get(i).deptcode);
			System.out.println(e.list.get(e.ifExists(list.get(i).deptcode)));

		} else {
			System.out.println("Invalid Employee");
		}
	}

	void displayList() {
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));
		}
	}

	void removeEmployee(int c) {
		int i;
		if ((i = ifExists(c)) != -1) {
			list.remove(i);
		} else {
			System.out.println("Employee not found");
		}
	}

	void modifyBasic(int c, double newBasic) {
		int i = ifExists(c);
		if (i != -1) {
			list.get(i).setBasic(newBasic);
		} else {
			System.out.println("Employee not found");
		}
	}

	void sortBasic() {
		list.sort(new SortbyBasic());
		displayList();
	}

	void sortDept() {
		list.sort(new SortbyDept());
		displayList();
	}

	void sortEmployee() {
		list.sort(new SortbyEmp());
		displayList();
	}

}

class SortbyBasic implements Comparator<Employee> {
	// Used for sorting in descending order of
	// basic
	public int compare(Employee a, Employee b) {
		if (b.basic > a.basic) {
			return 1;
		} else if (b.basic < a.basic) {
			return -1;
		} else {
			return 0;
		}
	}
}

class SortbyDept implements Comparator<Employee> {
	// Used for sorting in ascending order of
	// department code
	public int compare(Employee a, Employee b) {
		return a.code - b.code;
	}
}

class SortbyEmp implements Comparator<Employee> {
	// Used for sorting in ascending order of
	// employee code
	public int compare(Employee a, Employee b) {
		return a.deptcode - b.deptcode;
	}
}

class Prog_1 {
	EmployeeList e;
	DepartmentList d;

	Prog_1() {
		e = new EmployeeList();
		d = new DepartmentList();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int k;
		int choice;
		do {
			System.out.println("Menu : ");
			System.out.println("1. Add employee ");
			System.out.println("2. Remove employee ");
			System.out.println("3. Add department ");
			System.out.println("4. Display an employee ");
			System.out.println("5. Display all employees ");
			System.out.println("6. Find total basic pay of a department ");
			System.out.println("7. Modify basic pay of an employee");
			System.out.println("8. Sort the employee list");
			choice = sc.nextInt();
			switch (choice) {
			case 1:
				e.addEmployee(d);
				break;
			case 2:
				System.out.println("Enter the employee code : ");
				int c = sc.nextInt();
				e.removeEmployee(c);
				break;
			case 3:
				d.addDepartment();
				break;
			case 4:
				System.out.println("Enter the employee code : ");
				k = sc.nextInt();
				e.displayEmployee(k, d);
				break;
			case 5:
				e.displayList();
				break;
			case 6:
				System.out.println("Enter the department code : ");
				k = sc.nextInt();
				Department d = new Department();
				d.setCode(k);
				System.out.println("Total Basic pay : " + d.totalPay(e));
				break;
			case 7:
				System.out.println("Enter employee code : ");
				k = sc.nextInt();
				System.out.println("Enter new basic pay  : ");
				double pay = sc.nextDouble();
				e.modifyBasic(k, pay);
				break;
			case 8:
				System.out.println("Sort according to \n1. Basic pay\n2. Employee code\n3. Department code\n");
				k = sc.nextInt();
				if (k == 1) {
					e.sortBasic();
				} else if (k == 2) {
					e.sortEmployee();
				} else if (k == 3) {
					e.sortDept();
				} else {
					System.out.println("Invalid code");
				}
				break;

			}
		} while (choice != -1);
	}

	public static void main(String args[]) {
		Prog_1 t = new Prog_1();
		t.run();
	}

}