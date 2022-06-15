//import java.util.*;
class ExStatic1 
 {  /*final is the non access modifier
    used with variable,method and class 
	if the variable declared as final then value of 
	the variable cant be changed.*/
	static final int total=100;
	final int t=22;
    static public int x;
	/*static block.It is used to initialize static
	variale.Any logic which you want to load before 
	main method.*/
	
	public static void main(String ar[])
	{  java.util.Scanner sc=new java.util.Scanner(System.in);
		// Date d=new Date();
		System.out.print("HI,I AM main method BLOCK");
	}
	static{
	    x=34;
		System.out.print("HI,I AM STATIC BLOCK");
	}
 }