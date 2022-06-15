// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 1st February 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                           Multiple Inheritance                                  ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Multiple inheritance can not be supported by java using classes but through 
	interface it is possible. Applying concept of interface and multiple inheritance. 
	Write an application to display percentage of students, Obtained Marks in 5 subject, 
	Personal information like roll number, name of student. Where a class Student 
	have roll_Number : int , stud_Name:String, m1,m2,m3,m4,m5 : float 
	(stores 5 subject marks /you can use array if you want).
	Interface Exam has method cal_percentage() and Result class is a subclass 
	which inherit property from Student and Exam.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		Result obj = new Result();
		
		System.out.printf("Please Enter the details of Student\n");
		System.out.printf("\tFull name          :  ");
		obj.setName(scan.nextLine());
		System.out.printf("\troll number        :  ");
		obj.setRoll(scan.nextInt());
		System.out.printf("\tNumber of subjects :  ");
		int count = scan.nextInt();
		float mark_set[] = new float[count];
			for(int i = 0 ; i < count ; i++){
				System.out.printf("\t\tMarks in subject %02d :  ", i+1);
				mark_set[i] = scan .nextFloat();
			}
		obj.setMarks(mark_set);
		obj.cal_percentage();
	
	}
	
	///////////////////////////////////////////////////////////////////////////////////////
	///                              Driver Function                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	public static void main(String args[]){
		try {
			solve();
		}
		catch(InputMismatchException e){
			System.out.println("Sorry! Input is not correct.");
		}
		catch(ArithmeticException e){
			System.out.println("Sorry! Something wrong with calculations.");
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Sorry! You have reached where you shouldn't.");
		}
		catch(Exception e){
			System.out.println("Sorry! Something went wrong.");
		}
		finally{
			System.out.println("The program is about to exit ! ");
		}
	}
}

class Student{
	int roll_Number;
	String stud_Name;
	float marks[];
	
	void setRoll(int input){
		roll_Number = input;
	}
	
	void setName(String input){
		stud_Name = input;
	}
	
	void setMarks(float...input){
		marks = input;
	}
}

interface Exam{
	void cal_percentage();
}

class Result extends Student implements Exam{
	
	public void cal_percentage(){
		float sum = 0f;
		for (float i : marks){
			sum += i;
		}
		System.out.println("\t >> Total is : " + (sum / marks.length) + "% only !");
	}
}

