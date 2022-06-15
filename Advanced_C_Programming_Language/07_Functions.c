// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 23rd November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
int add(int a , int b);
void add_direct();
void add_print(int a , int b);
int add_return();

// #########################
//       MAIN FUNCTION
// #########################
int main(){

	// Get two number from user
	printf("Enter any two numbers : ");
	int n1 = 0 , n2 = 0;
	scanf("%d %d" , &n1 , &n2);
	printf("Calling other functions . . .");
	
	// Use of void add_print(n1 , n2) function
	add_print(n1 , n2);
	
	// Use of void add_direct() function
	add_direct();
	
	// use of int add() function
	printf("🔸️ Sum of two number is %d : \n", add_return());
	
	
	return 0;
}

// #########################
//   FUNCTIONS DEFINITIONS
// #########################
void add_direct(){
	// No argument and no-return type functions
	printf("\n\n🔹️ Now, you are @ 'add_direct()' function ... !!!\n");
	printf("Enter any two numbers : ");
	int n1 = 0 , n2 = 0;
	scanf("%d %d" , &n1 , &n2);
	printf("🔸️ Addition of %d and %d by add function is : %d \n" , n1 , n2 , add(n1 , n2));
}

int add_return(){
	// No argument and with-return type functions
	printf("\n\n🔹️ Now, you are @ 'add_return()' function ... !!!\n");
	printf("Enter any two numbers : ");
	int n1 = 0 , n2 = 0;
	scanf("%d %d" , &n1 , &n2);
	return n1 + n2;
}

void add_print(int a , int b){
	// With argument and no-return type functions
	printf("\n\n🔹️ Now, you are @ 'add_print()' function ... !!!\n");
	printf("🔸️ Addition of %d and %d by add function is : %d \n" , a , b , add(a , b));
}

int add(int a , int b){
	// With argument and with-return type functions
	return a+b;
}






