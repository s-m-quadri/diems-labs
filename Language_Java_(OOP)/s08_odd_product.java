// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                            Odd number product                                   ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Write an application that calculates the product of the odd integers from 1 to 15.
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
			System.out.printf("== range %02d == product of odd integers %d\n", i, getProduct(i));
			if(i >= 30) {
				System.out.printf("And even beyond the range of long ...\n");
				break;
			}
		}
	}
	
	private static long getProduct(int input){
		long product = 1;
		for(int i = 1 ; i <= input ; i++){
			if(i%2 == 1) product *= i;
		}
		return product;
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

