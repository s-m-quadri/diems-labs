
import java.util.Scanner;

class Main{
	public static void main(String args[]){
		// Get inputs from user
		Scanner scan = new Scanner(System.in);
		System.out.printf("\n-----------------------------------------\n");
		System.out.printf(" * Enter the length : ");
		int length = scan.nextInt();
		System.out.printf(" * Enter the width  : ");
		int width = scan.nextInt();
		System.out.printf(" * Enter the height : ");
		int height = scan.nextInt();
		
		// Get volume using the inherited class
		Box obj = new Box(length , width , height);
		System.out.printf("-----------------------------------------\n");
		System.out.printf("   %.2f cubic units\n" , obj.getVolume());
		System.out.printf("   Is the volume of rectangle.\n");
		System.out.printf("-----------------------------------------\n");
	}
};

class Rectangle{
	double length;
	double width;
	
	Rectangle(double input_length, double input_width){
		this.length = input_length;
		this.width = input_width;
	}
	
	void setRectangle(double input_length, double input_width){
		this.length = input_length;
		this.width = input_width;
	}
	
	double getArea(){
		return length*width;
	}
};

class Box extends Rectangle{
	double height;
	
	Box(double input_length , double input_width , double input_height){
		super(input_length , input_height);
		this.height = input_height;
	}
	
	void setBox(double input_length , double input_width , double input_height){
		setRectangle(input_length , input_height);
		this.height = input_height;
	}
	
	double getVolume(){
		return getArea()*height;
	}
}

// class Member{
	// String name;
	// int age;
	// long phoneNo;
	// String address;
	
	
// }