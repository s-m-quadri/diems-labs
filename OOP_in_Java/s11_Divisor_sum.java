// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                                   Divisor sum                                      ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	A Java interface can only contain method signatures and fields. The interface can be used to
	achieve polymorphism. In this problem, you will practice your knowledge on interfaces.
	You are given an interface AdvancedArithmetic which contains a method signature int
	divisor_sum(int n). You need to write a class called MyCalculator which implements the
	divisorSum function just takes an integer as input and return the sum of all its divisors. For
	example divisors of 6 are 1, 2, 3 and 6, so divisor_sum should return 12. The value of n will be
	at most 1000.
	Sample Input
	 6
	Sample Output
	 12
	Explanation
	 Divisors of 6 are 1,2,3 and 6. 1+2+3+6=12.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter the number : ");
		System.out.printf("> Divisor sum is : %d\n", getDivisorSum(scan.nextInt()));
	}
	
	private static long getDivisorSum(int input){
		if(input < 1) return 0;
		long sum = 0;
		for(int i = 1 ; i <= input ; i++)
			if (input % i == 0)
				sum = sum + i;
		return sum;
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

