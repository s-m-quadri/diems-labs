import java.util.Scanner;

class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int res = 0;
		
		try{
			int i = scan.nextInt() , j = scan.nextInt() ;
			res = i/j;
		}
		//catch(ArithmeticException e){
		//	System.out.println("Cannot divide it");
		//}
		finally{
			System.out.println("completed till 1 ");
		}
		System.out.println(res);
	}

}
