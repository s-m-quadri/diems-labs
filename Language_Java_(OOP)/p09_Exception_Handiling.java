// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 21st January 2022

import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		
		try{
			System.out.println("Division is : " + (scan.nextInt() / scan.nextInt()));
		}
		// Expected exception
		catch(InputMismatchException | ArithmeticException e){
			System.out.println(e);
		}
		// Unexpected exception
		catch(Exception e){
			System.out.println("Something went wrong ! ");
		}
	}
}


/*
try{
	System.out.println("Division is : " + (scan.nextInt() / scan.nextInt()));
}
catch(InputMismatchException e){
	System.out.println("Input is not correct ! ");
}
catch(ArithmeticException e){
	System.out.println("Can't divide by zero ! ");
}
catch(ArrayIndexOutOfBoundsException e){
	System.out.println("You have reached where you shouldn't ! ");
}
catch(Exception e){
	System.out.println("Something went wrong ! ");
}
*/
