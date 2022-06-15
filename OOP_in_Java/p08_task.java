// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 14th January 2022

import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		
		Employee obj;
		obj = new Employee();
		obj.setName("XYZ");
		obj.setSalary(1200);
		obj.displayDetails();
	}
}

interface Salary{
	void setSalary(double input);
	double getSalary();
}

interface Person{
	void setName(String input);
	String getName();
}

class Employee implements Salary , Person{
	String Name;
	double Salary;
	
	public void setName(String input){this.Name = input; }
	public void setSalary(double input){this.Salary = input; }
	
	public String getName(){return this.Name; }
	public double getSalary(){return this.Salary; }
	
	void displayDetails(){
		System.out.println("  Name : " + getName());
		System.out.println("Salary : " + getSalary());
	}
}




