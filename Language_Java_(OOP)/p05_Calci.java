// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 17th December 2021

// Compile this file as
// IMPORTANT :
// 	....$:	javac -d . filename.java

package p5;

public class p05_Calci{
	public static int add(int a , int b) {return a+b;}
	public static int sub(int a , int b) {return a-b;}
	public static long mul(int a , int b) {return a*b;}
	public static double div(int a , int b) {return a/b;}
	public static boolean isEqual(int a , int b) {return a==b;}
	public static boolean isOdd(int a) {return a%2!=0;}
	public static boolean isEven(int a) {return a%2==0;}
	public static long product(int ... arg) {
		int result = 1;
		for(int i : arg) result = result * i;
		return result;
		}
	public static long sum(int ... arg) {
		int result = 1;
		for(int i : arg) result = result + i;
		return result;
		}
}