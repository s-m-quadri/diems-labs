// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 21st January 2022

import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		  
		try{
			// Get number of elements and form array
			System.out.print("How many element should be there in array : ");
			int n = scan.nextInt();
			int array[] = new int[n];
			
			// Get the elements
			for(int i = 0 ; i < n ; i++){
				System.out.printf("\t Element %02d : " , i+1);
				array[i] = scan.nextInt();
			}
			
			// Display elements
			System.out.print("Element you entered are : ");
			for(int i : array){
				System.out.print( i + " ");
			}
			System.out.print("\n");
		}
		
		catch(InputMismatchException e){
			System.out.println("Sorry! Input is not correct.");
		}
		catch(ArithmeticException e){
			System.out.println("Sorry! Can't divide by zero.");
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
