// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                                Basic Tasks                                      ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	(Write a Statement) Write a Java statement or a set of Java statements to accomplish each of
	the following tasks: 
	(a) Sum the odd integers between 1 and 99, using a for statement. Assume
	    that the integer variables sum and count have been declared. 
	(b) Calculate the value of 2.5 raised to the power of 3, using the pow method.
	(c) Print the integers from 1 to 20, using a while loop and the counter variable i. Assume 
	    that the variable i has been declared, but not initialized. Print only five integers per line.
		[Hint: Use the calculation i%5. When the value of this expression is 0, print a newline character;
		 otherwise, print a tab character. Assume that this code is an application. Use the 
		 System.out.println() method to output the newline character, and use the 
		 System.out.print( '\t' ) method to output the tab character.]
	(d) Repeat part (c), using a for statement.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		
		// Task A
		System.out.printf("Enter the range : ");
		long range = scan.nextLong(), sum = 0;
		for (long i = 0 ; i < range ; i++)
			if(i % 2 == 1)
				sum += i;
		System.out.printf("Sum of all odd numbers among given range is %d !\n", sum);
		
		// Task B
		System.out.printf("Enter the number with power as pair : ");
		double number = scan.nextDouble(), power = scan.nextDouble();
		System.out.printf("Hmmm! %02.2f wil be the result !\n", Math.pow(number, power));
		
		// Task C
		System.out.printf("Enter the range : ");
		range = scan.nextLong();
		for (long i = 1 ; i < range ; i++){
			if((i-1) % 5 == 0) System.out.printf("\n");
			System.out.printf("\t%d", i);
		}
		System.out.printf("\n");
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

