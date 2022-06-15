// By 5MQuadr! (s-m-quadri@github.com , 26107@diems2020-24)
// Last Updated on : 19th November 2021


// ################################
//           PRACTICAL 01
//  -----------------------------
//     Data type , operator and
//        Arithmetic program.
// ################################

class Main{
	public static void main(String arg[]){
		byte var1 = 7;
		int var2 = 8;
		boolean var3 = true;
		char var4 = 'D';
		// Since by default , rational number is treated as double
		float var5 = (float) 12.3; 
		
		System.out.printf(" ------------------------------------------- \n");
		System.out.printf(" Variable 1 = %d \t (as a byte)\n" , var1);
		System.out.printf(" Variable 2 = %d \t (as a integer)\n" , var2);
		System.out.printf(" Variable 3 = %b \t (as a Boolean)\n" , var3);
		System.out.printf(" Variable 4 = %c \t (as a character)\n" , var4);
		System.out.printf(" Variable 5 = %.2f \t (as a float)\n" , var5);
		System.out.printf(" ------------------------------------------- \n");
		
		// IMPLICIT TYPE CAST - ARITHMETIC PROMOTION - BY COMPILER
		// byte is treated as integer
		System.out.printf("Sum of first two as a integer is  : %d\n" , var1 + var2);
		
		// EXPLICIT TYPE CAST - BY USER
		// integer is treated as byte
		byte sum = (byte) (var1 + var2);
		System.out.printf("Now sum of first two as a byte is : %d\n" , sum);
		
		// USE OPERATORS
		for (int i = 0 ; i < 100 ; i++){
			if (i % 10 == 0) System.out.printf("\n🔸️ ");
			if ( (i+1) % 2 == 0 || (i+1) % 3 == 0 ) {
				System.out.printf("%2d ", i+1);
			}
		}
		System.out.printf("\n");
		
	}
}
