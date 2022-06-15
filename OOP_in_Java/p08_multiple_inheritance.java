// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 14th January 2022

import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		
		Result obj;
		obj = new Result();
		obj.setName("XYZ");
		obj.setRoll(26000);
		obj.setTest1(80.01f);
		obj.setTest2(76.99f);
		obj.displayRecord();
	}
}

class Student{
	// Instance variable - Roll Number
	int roll;
	void setRoll(int input){this.roll = input;}
	int getRoll(){return this.roll;}
	
	// Instance variable - Name Number
	String name;
	void setName(String input){this.name = input; }
	String getName(){return this.name; }
}

class Test extends Student{
	// Instance variable - Test1
	float test1;
	void setTest1(float input){this.test1 = input; }
	float getTest1(){return this.test1; }
	
	// Instance variable - Test2
	float test2;
	void setTest2(float input){this.test2 = input; }
	float getTest2(){return this.test2; }
}

interface Sports{
	// Interface has (by default)
	// "final static variables" and "abstract methods"
	float sports = 6.0f;
	float getSportsMarks();
}

class Result extends Test implements Sports{
	public float getSportsMarks(){return sports; }
	float calResult(){ return getTest1()+getTest2()+getSportsMarks(); }
	
	void displayRecord(){
		System.out.println("           Name : " + getName());
		System.out.println("           Roll : " + getRoll());
		System.out.println(" Marks of test1 : " + getTest1());
		System.out.println(" Marks of test2 : " + getTest2());
		System.out.println(" Marks of sport : " + getSportsMarks());
		System.out.println("         Result : " + calResult());
	}
}

