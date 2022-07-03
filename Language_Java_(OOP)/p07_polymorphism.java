// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 7th January 2022

import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		Figure obj;
		System.out.printf("-----------------------------------------\n");

		// Get inputs from user
		System.out.printf(" * Enter the length : ");
		int dim1 = scan.nextInt();
		System.out.printf(" * Enter the width  : ");
		int dim2 = scan.nextInt();
		System.out.printf("-----------------------------------------\n");
		
		// Get Area using the inherited class
		obj = new Rectangle(dim1 , dim2);
		obj.showDimension();
		System.out.printf("   %.2f sqaure units\n" , obj.getArea());
		System.out.printf("   Is the area of rectangle.\n");
		System.out.printf("-----------------------------------------\n");
		
		// Get inputs from user
		System.out.printf(" * Enter the radius  : ");
		int dim3 = scan.nextInt();
		System.out.printf("-----------------------------------------\n");
		
		// Get Area using the inherited class
		obj = new Circle(dim3 , 0);
		obj.showDimension();
		System.out.printf("   %.2f sqaure units\n" , obj.getArea());
		System.out.printf("   Is the area of circle.\n");
		System.out.printf("-----------------------------------------\n");
		
	}
};

abstract class Figure{
	double dim1 , dim2;
	Figure(double in1 , double in2){
		dim1 = in1;
		dim2 = in2;
	}
	
	abstract double getArea();
	
	final void showDimension(){
		System.out.printf("1st Dimension : %.2f units\n" , dim1);
		System.out.printf("2nd Dimension : %.2f units\n" , dim2);
	}
};

class Rectangle extends Figure{
	Rectangle(double input_1 , double input_2){
		super(input_1 , input_2);
	}
	
	double getArea(){
		return dim1 * dim2;
	}
}

class Circle extends Figure{
	Circle(double input_1 , double input_2){
		super(input_1 , 0);
	}
	
	double getArea(){
		return Math.PI * dim1 * dim1;
	}
}







