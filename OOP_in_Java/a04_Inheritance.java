// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 29th December 2021

import java.util.Scanner;

class Main{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        Manager obj = new Manager();
        
        // Get details
        System.out.printf("Enter the id : ");
        obj.set_empId(scan.nextInt());
        System.out.printf("Enter the name : ");
        scan.nextLine(); // clear buffer
        obj.set_empName(scan.nextLine());
        System.out.printf("Enter the role : ");
        obj.set_role(scan.nextLine());
        System.out.printf("Enter the basic salary : Rs. ");
        obj.set_basicSalary(scan.nextInt());
        
        // Display details
        System.out.println("Name : " + obj.get_empName());
        System.out.println("Role : " + obj.get_role());
        System.out.println("Id : " + obj.get_empId());
        System.out.println("Salary : " + obj.get_Salary());
        System.out.println("Gross : " + obj.get_Gross());
    }
}

class Employee{
    private int empId;
    private String empName;
    
    // Setter Methods
    void set_empId(int input){empId = input;}
    void set_empName(String input){empName = input;}
    
    // Getter Methods
    int get_empId(){return empId;}
    String get_empName(){return empName;}
}

class Manager extends Employee{
    private String role;
    private int basicSalary;
    
    // Setter Methods
    void set_role(String input){role = input;}
    void set_basicSalary(int input){basicSalary = input;}
    
    // Getter Methods
    String get_role(){return role;}
    int get_Salary(){return basicSalary;}
    int get_Gross(){return basicSalary*12;}
    
    
}
