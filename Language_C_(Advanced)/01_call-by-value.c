// By 5MQuadr! (s-m-quadri@github , 26107@diems2021)
// Last Updated On : 8th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
void avarage(int a, int b);


// #########################
//       MAIN FUNCTION
// #########################
int main(){
	int x,y;
	printf("😐️ Please enter the values two number : ");
	scanf("%d %d", &x,&y);
	avarage(x,y);
	
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
void avarage(int a, int b){
	printf("😕️ Average is : %d \n", (a+b)/2);
}
