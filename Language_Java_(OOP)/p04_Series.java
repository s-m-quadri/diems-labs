// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 11th December 2021

// Compile this file as
// IMPORTANT :
// 	....$:	javac -d . filename.java

package a5; // user defined package << must be on first statement

import java.util.Scanner;

public class p04_Series{
	public static void get_table(int x){
		for (int i = 0 ; i < 10 ; i++)
			System.out.printf("🔸️ %02d x %02d = %d\n", x , i+1 , x*(i+1));
	}
	
	public static void fibonaci(){
		// Get info
		System.out.printf("\n🔹️ Please enter the number of Fibonacci elements : ");
		Scanner obj = new Scanner(System.in);
		int n = obj.nextInt();
		
		// Display
		int n1 = 0 , n2 = 0, next = 0;
		for(int i = 0 ; i < n ; i++){
			// Pre Display
			System.out.printf("\n%02d 🔸️ ", i+1);
			if (i>45) {
				System.out.printf("And even beyond the range ... !!!");
				break;
				}
			// Display
			System.out.printf("%d",n1+n2);
			// Post Display
			if (i == 0) n2=1;
			else {
				next = n1 + n2;
				n1 = n2;
				n2 = next;
				}
		}
		System.out.printf("\n");
		
	}
	
}
