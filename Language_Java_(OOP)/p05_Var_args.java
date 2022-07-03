// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 17th December 2021

import p5.p05_Calci;

import java.util.Scanner;

class Main{
	public static void main(String args[]){
		// Command line variable arguments to calculate sum
		if (args.length != 0){
			int result = 0;
			int sum = 0;
			for(String i : args) {
				if (sum == 1) result = result + Integer.parseInt(i);
				if (i.matches("sum")) sum = 1;
			}
			if (result != 0) System.out.println("Result = " + result);
		}
		
		// Variable arguments to calculate product
		System.out.println("\n#1. Variable arguments to calculate product");
		System.out.printf(" 3 x 4 = %d \n",p05_Calci.product(3,4));
		System.out.printf(" 3 x 4 x 5 = %d \n",p05_Calci.product(3,4,5));
		System.out.printf(" 3 x 4 x 5 x 6 = %d \n",p05_Calci.product(3,4,5,6));
		System.out.printf(" 3 x 4 x 5 x 6 x 7 = %d \n",p05_Calci.product(3,4,5,6,7)); 
		
		// Variable arguments to calculate percentage
		System.out.println("\n#2. Variable arguments to calculate percentage");
		percentMarks(15 , 15);
		percentMarks(15 , 15 , 12 , 20);
		percentMarks(15 , 15 , 12 , 20 , 12 , 0);
		
		// Variable arguments to calculate avg3x
		System.out.println("\n#3. Variable arguments to calculate avg3x");
		avg3x(2 , 4 , 6 , 8);
		avg3x(2 , 4 , 6 , 8 , 6 , 3 , 6 , 7);
		avg3x(2 , 4 , 6 , 8 , 3 , 8 , 2 , 6 , 9 , 2 , 8);
		
		// Variable arguments to display status
		System.out.println("\n#4. Variable arguments to display status");
		status(true, true, false);
		status(true, false);
		status(false);
		

		

	}
	
	public static void percentMarks(double ... args){
		if (args.length == 0) System.out.println(" Please pass some values.");
		else {
			double result = 0;
			for (double i : args){
				result += i;
			}
			result = result / (20 * args.length) * 100;
			System.out.printf(" Percentage marks (each out of 20) = %02.02f%%\n" , result);
		}
	}
	
	public static void avg3x(int ... args){
		if (args.length == 0) System.out.println(" Please pass some values.");
		else {
			int result = 0;
			for (int i : args){
				System.out.print(" " + i);
				result += i;
			}
			result = result / args.length * 3;
			System.out.println("  ==> Average_value x 3 = " + result);
		}
	}
	
	public static void status(boolean ... sts){
		if (sts.length == 0) System.out.println(" Please pass some values.");
		else {
			for (boolean i : sts){
				if (i == true) System.out.println(" You are trustworthy");
				if (i == false) System.out.println(" You are false");
			}
		}
	}
	
}
