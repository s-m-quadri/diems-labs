/*
===============
 PRACTICAL 03
===============
	Monday, November 29, 2021 3:00 PM
	
AIM
~~~
	Write A Program To Find Length And Reverse Given String.

THEORY
~~~~~~
	Strings in Java are Objects that are backed internally by a char array.
	Since arrays are immutable(cannot grow), Strings are immutable as well.
	Whenever a change to a String is made, an entirely new String is created.
	Memory allotment of String, whenever a String Object is created as a literal, 
	the object will be created in String constant pool.
	This allows JVM to optimize the initialization of String literal.
	For example:
		String str = "DIEMS";
		
	The string can also be declared using new operator i.e. dynamically allocated.
	In case of String are dynamically allocated they are assigned a new memory location in heap.
	This string will not be added to String constant pool.
	For example:
		String str = new String("DIEMS");
		
	Creating a String
	There are two ways to create a string in Java:
	• String literal
		String s = “DIEMS”;
	• Using new keyword
		String s = new String (“DIEMS”);
*/


import java.util.Scanner;
class Main{
	public static void main(String ar[]){
		System.out.println("Enter the string to find length and reverse the string");
		Scanner scan=new Scanner(System.in);
		String s=scan.nextLine();

		int len = s.length();
		System.out.printf("Length of the string %s is %d\n",s,len);
		
		// Reverse the string
		// But, first convert to array << optional (it makes it simpler to understand)
		char ch[]=s.toCharArray();
		String rev="";

		for(int i = ch.length -1 ;i >= 0 ;i--) rev+=ch[i];
		System.out.printf("\nReverse string of the string %s is %s",s,rev);
	}
}

/*
1. Task to be performed
	A1 A3 A5 : Study charAt(),concat()
	A2 A4 	 : Study Ignore-case And Equals Method
2. Programs to study
	How to check if two strings are anagrams of each other?
	How to count the occurrence of the given character in a string?
	How to check if a string is a palindrome?
	How to swap two strings without using the third variable?
*/
