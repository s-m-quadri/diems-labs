// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 30th January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                              Perfect Numbers                                    ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	An integer number is said to be a perfect number if its factors,
	including 1 (but not the number itself), sum to the number. For example, 6 is a perfect number,
	because 6 = 1 + 2 + 3. Write a method isPerfect that determines if parameter number is a
	perfect number. Use this method in an application that displays all the perfect numbers
	between 1 and 1000. Display the factors of each perfect number to confirm that the number is
	indeed perfect. Challenge the computing power of your computer by testing numbers much
	larger than 1000. Display the results.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter the range among which are perfect numbers : ");
		long range = scan.nextLong();
		
		for(long i = 0 ; i < range ; i++){
			if(isPerfect(i) == true){
				System.out.printf("%7d  having factors ", i);
				printFactors(i);
				System.out.printf("\n");
				
			}
		}
	}
	
	private static boolean isPerfect(long input){
		if(input < 1) return false;
		long sum = 0;
		for(long i = 1 ; i < input ; i++){
			if (input % i == 0){
				sum = sum + i;
			}
		}
		if (sum == input) return true;
		else return false;
	}
	
	private static void printFactors(long input){
		if(input < 1) return;
		for(long i = 1 ; i < input ; i++){
			if (input % i == 0){
				System.out.printf("%d ", i);
			}
		}
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

