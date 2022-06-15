// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 29th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
long int factorial();

// #########################
//       MAIN FUNCTION
// #########################

// TASK - Write a program 
// To calculate factorial of given number
// By Recursion

int main(){
	int no = 0;
	printf("🔹️ Factorial of which number : ");
	scanf("%d" , &no);
	
	long int fac = factorial(no);
	if (fac != 0) printf("🔸️ Factorial of %d is given by: %d! = %ld\n" , no , no , fac);
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
long int factorial(int input){
	// Error checking
	if (input < 0) {
		printf("  Can't find, Negative number .. !!\n");
		return 0;
	}
	if (input > 20) {
		printf("  Out of range, Too big ... !!\n");
		return 0;
	}
	// Base condition
	if (input == 0) return 1;
	// Recursion
	if (input >= 0 && input <= 20) {
	return (input * factorial(input-1));
	}
}






