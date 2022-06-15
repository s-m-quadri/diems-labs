// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                                Smallest One                                       ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Write an application that finds the smallest of several integers. Assume 
	that the first value read specifies the number of values to input from the user.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("Enter the number of elements : ");
		int size = scan.nextInt();
		
		int inputs[] = new int[size];
		for(int i = 0 ; i < size ; i++){
			System.out.printf("\t Element %d? ", i+1);
			inputs[i] = scan.nextInt();
		}
		
		int min = inputs[0];
		for(int i = 0 ; i < size ; i++){
			if(min > inputs[i]) min = inputs[i];
		}
		
		System.out.printf("Well ! I guess %d is the minimum, isn't it?\n", min);
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

