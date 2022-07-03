// By 5MQuadr! (s-m-quadri@github.com , 26107@diems2020-24)
// Last Updated on : 26th November 2021


/*
===================
   PRACTICAL 02
===================

	Write a program to implement class, object and constructor overloading.

Instructions
~~~~~~~~~~~~
	1. Create a class called Employee that includes three instance variables
	 - a first name (type String), a last name (type String) and a monthly salary (double).
	2. Implement constructor overloading and initialize variables. 
	3. Provide a set and get method for each instance variable.
	4. If the monthly salary is not positive, do not set its value. 
	5. Write a test application named EmployeeTest that demonstrate class Employee’s capabilities. 
	6. Create two Employee objects and display each object’s yearly salary. 
	7. Then give each Employee a 10% raise and display each Employee’s salary again. 
	
Journal write up 
~~~~~~~~~~~~~~~~
	1. class definition and syntax.
	2. object definition and object instantiation.
	3. constructor and types of constructor.
	4. constructor overloading.
*/


import java.util.Scanner;
class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		
		// Getting Details - Employee 1 ...
		Employee emp_1 = new Employee();
		System.out.printf("Enter employee-1 name : ");
		emp_1.setName(scan.nextLine());
		System.out.printf("Enter employee-1 salary : ");
		while(emp_1.getSalary() == 0) emp_1.setSalary(scan.nextDouble());
		
		// Getting Details - Employee 2 ...
		Employee emp_2 = new Employee("Employee_two" , 10000);
		
		// Displaying - Employee 1 ...
		System.out.println("\nName of 1st employee : \t" + emp_1.getName());
		System.out.println("\t🔹️ Salary : " + emp_1.getSalary());
		System.out.println("\t🔸️ Salary : " + emp_1.getSalary() * 12 + " (Yearly)");
		System.out.println("\t🔹️ Salary : " + (emp_1.getSalary() + emp_1.getSalary() / 10) + " (Raised 10%) monthly");
		
		// Displaying - Employee 2 ...
		System.out.println("\nName of 2nd employee : \t" + emp_2.getName());
		System.out.println("\t🔹️ Salary : " + emp_2.getSalary());
		System.out.println("\t🔸️ Salary : " + emp_2.getSalary() * 12 + " (Yearly)");
		System.out.println("\t🔹️ Salary : " + (emp_2.getSalary() + emp_2.getSalary() / 10) + " (Raised 10%) monthly");
		
	}
}

class Employee{
	// Instance variables ...
	String Name;
	double Salary;
	
	// Constructor - non parameterized ...
	Employee(){
		Name = "unknown";
		Salary = 0;
	}
	
	// Constructor - parameterized ...
	Employee(String input_name, double input_salary){
		Name = input_name;
		Salary = input_salary;
	}
	
	// Setter Methods ...
	void setName(String input){Name = input;}
	void setSalary(double input){ 
		if(input < 0) return; 
		else Salary = input;
	}
	
	// Getter Methods ...
	String getName(){return Name;}
	double getSalary(){return Salary;}
}


