// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                         Temperature Conversions                                 ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	Questions: Temperature Conversions
	Implement the following integer methods:
	a) Method celsius returns the Celsius equivalent of a Fahrenheit temperature, using the
	calculation
	celsius = 5.0 / 9.0 * ( fahrenheit - 32 );
	
	b) Method fahrenheit returns the Fahrenheit equivalent of a Celsius temperature, using the
	calculation
	fahrenheit = 9.0 / 5.0 * celsius + 32;
	
	c) Use the methods from parts (a) and (b) to write an application that enables the user either to
	enter a Fahrenheit temperature and display the Celsius equivalent or to enter a Celsius
	temperature and display the Fahrenheit equivalent.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter the temperature : ");
		int input = scan.nextInt();
		System.out.printf("If the you entered temperature in Celsius units,\n");
		System.out.printf(" = Then equivalent is %d Fahrenheit !\n", fahrenheit(input));
		System.out.printf("If the you entered temperature in Fahrenheit units,\n");
		System.out.printf(" = Then equivalent is %d degree Celsius !\n", celsius(input));
	}
	
	private static int celsius(int fahrenheit){
		return Math.round((float)(5.0 / 9.0 * (fahrenheit - 32)));
	}
	
	private static int fahrenheit(int celsius){
		return Math.round((float)(9.0 / 5.0 * (celsius + 32)));
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

