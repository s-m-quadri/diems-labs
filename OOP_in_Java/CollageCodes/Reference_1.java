import java.util.Scanner; 

class Main{ 
	public static void main(String[] args) { 
		Scanner sc=new Scanner(System.in); 
		int no; 

		// Use of Arithmetic operator and logical operator  to check divisibility  
		System.out.printf("Enter number to check divisibility : "); 
		no=sc.nextInt();
		if(no%3==0) System.out.printf("The no %d is divisible by 3\n",no);
		else System.out.printf("The no %d is  not divisible by 3\n11",no);

		// Code to check divisibility by 2 or 3 using logical or operator 
		System.out.println("Enter number to check divisibility : "); 
		no=sc.nextInt(); 
		if(no%3==0 || no%2==0) System.out.printf("The no %d is divisible by 3 or 2\n",no);
		else System.out.printf("The no %d is not divisible by 3 or 2\n",no);

		// Use of logical && 
		System.out.printf("Enter number to check divisibility : "); 
		no=sc.nextInt(); 
		if(no%3 == 0 && no%5 == 0) System.out.printf("The no %d is divisible by 3 and 5\n",no);
		else System.out.printf("The no %d is  not divisible by 3 or 2\n",no);

		// Use of Ternary operator 
		String s = (no%3 == 0) ? "No is divisible by 3" : "No is not divisible by 3"; 
	} 
} 
