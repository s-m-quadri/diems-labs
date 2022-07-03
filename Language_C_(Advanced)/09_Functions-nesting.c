// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 23rd November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
void Function_A1();
void Function_B2();
void Function_C3();
void Function_D4();
void Function_E5();


// #########################
//       MAIN FUNCTION
// #########################
int main(){
	printf("Starting from main - going to A1\n");
	Function_A1();
	printf("Again, at main ! - Ending . . .\n");
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
void Function_A1(){
	printf("🔸️ You are in A1 - going to B2\n");
	Function_B2();
	printf("🔹️ Again, You are in A1 - returning\n");
	return;
}

void Function_B2(){
	printf("🔸️ You are in B2 - going to C3\n");
	Function_C3();
	printf("🔹️ Again, You are in B2 - returning\n");
	return;
}

void Function_C3(){
	printf("🔸️ You are in C3 - going to D4\n");
	Function_D4();
	printf("🔹️ Again, You are in C3 - returning\n");
	return;
}

void Function_D4(){
	printf("🔸️ You are in D4 - going to E5\n");
	Function_E5();
	printf("🔹️ Again, You are in D4 - returning\n");
	return;
}

void Function_E5(){
	printf("You are in E5 - going no where - just returning\n");
	return;
}
