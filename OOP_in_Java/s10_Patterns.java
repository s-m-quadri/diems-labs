// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                                   Patterns                                      ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Write an application that displays the following patterns separately, one below the other. Use
	for loops to generate the patterns. All asterisks (*) should be printed by a single statement of
	the form System.out.print( '*' ); which causes the asterisks to print side by side. A statement of
	the form System.out.println(); can be used to move to the next line. A statement of the form
	System.out.print( ' ' ); can be used to display a space for the last two patterns. There should be
	no other output statements in the program. [Hint: The last two patterns require that each line
	begin with an appropriate number of blank spaces.]
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("Enter the height : ");
		int height = scan.nextInt();
		
		if(height > 20){
			System.out.printf("Sorry ! too big, so we've set it to 20.\n");
			height = 20;
		}
		
		if(height < 1){
			System.out.printf("Sorry ! too small, so we've set it to 1.\n");
			height = 1;
		}
		
		for(int i = 0 ; i < height ; i++){
			for(int j = 0 ; j < height ; j++){
				if(i+j >= height-1) System.out.printf("@");
				else System.out.printf(" ");
			}
			System.out.printf(" ");
			
			for(int j = 0 ; j < height ; j++){
				if(i >= j) System.out.printf("@");
				else System.out.printf(" ");
			}
			System.out.printf("\n");
		}
		System.out.printf("\n");
		
		for(int i = 0 ; i < height ; i++){
			for(int j = 0 ; j < height ; j++){
				if(i <= j) System.out.printf("@");
				else System.out.printf(" ");
			}
			System.out.printf(" ");
			
			for(int j = 0 ; j < height ; j++){
				if(i+j <= height-1) System.out.printf("@");
				else System.out.printf(" ");
			}
			System.out.printf("\n");
		}
	}
	
	private static long getFactorial(int input){
		long factorial = 1;
		for(int i = 1 ; i <= input ; i++){
			factorial *= i;
		}
		return factorial;
	}
	
	
	///////////////////////////////////////////////////////////////////////////////////////
	///                              DRIVER FUNCTION                                    ///
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

