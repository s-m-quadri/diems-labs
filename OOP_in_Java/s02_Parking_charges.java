// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 31st January 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                              Parking Charges                                    ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	A parking garage charges a $2.00 minimum fee to park for up to three hours. The garage
	charges an additional $0.50 per hour for each hour or part thereof in excess of three hours. The
	maximum charge for any given 24-hour period is $10.00. Assume that no car parks for longer
	than 24 hours at a time. Write an application that calculates and displays the parking charges
	for each customer who parked in the garage yesterday. You should enter the hours parked for
	each customer. The program should display the charge for the current customer and should
	calculate and display the running total of yesterday’s receipts. It should use the method
	calculateCharges to determine the charge for each customer.
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter the parking hours : ");
		System.out.printf("Tota charges : $%02.2f /- only\n", calculateCharges(scan.nextInt()));
	}
	private static double calculateCharges(int hours){
		if(hours <= 3) return 2.00;
		else if(hours < 24) return 2.00 + hours * 0.50;
		else return 10.00;
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

