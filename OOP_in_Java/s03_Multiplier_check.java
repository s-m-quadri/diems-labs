// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                             Multiplier Check                                    ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Write a method isMultiple that determines, for a pair of integers, whether the second integer is
	a multiple of the first. The method should take two integer arguments and return true if the
	second is a multiple of the first and false otherwise. [Hint: Use the remainder operator.]
	Incorporate this method into an application that inputs a series of pairs of integers (one pair at
	a time) and determines whether the second value in each pair is a multiple of the first.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter the number of test cases : ");
		int test_case = scan.nextInt();
		while(test_case-- != 0){
			int first = scan.nextInt();
			int second = scan.nextInt();
			
			if(isMultiple(first,second))
				System.out.printf("YES ! %d is a multiple of %d\n", second, first);
			else
				System.out.printf("NO ! %d is not a multiple of %d\n", second, first);
		}
	}
	
	private static boolean isMultiple(int a, int b){
		if(b % a == 0) return true;
		else return false;
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

