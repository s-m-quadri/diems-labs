// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                                  Factorials                                     ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Factorials are used frequently in probability problems. The factorial of a positive integer n
	(written n! and pronounced “n factorial”) is equal to the product of the positive integers from 1
	to n. Write an application that calculates the factorials of 1 through 20. Use type long. Display
	the results in tabular format. What difficulty might prevent you from calculating the factorial of
	100?
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("Enter the range : ");
		int range = scan.nextInt();
		
		for(int i = 1 ; i <= range ; i++){
			System.out.printf("== %02d! == %d\n", i, getFactorial(i));
			if(i >= 20) {
				System.out.printf("And even beyond the range of long ...\n");
				break;
			}
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

