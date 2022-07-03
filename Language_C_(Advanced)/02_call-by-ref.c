// By 5MQuadr! (s-m-quadri@github , 26107@diems2021)
// Last Updated On : 8th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
void swap(int *a, int *b);


// #########################
//       MAIN FUNCTION
// #########################
int main(){
	int x,y;
	printf("🙄️ Please enter the values two number : ");
	// actual arguments
	scanf("%d %d", &x,&y);
	swap(&x,&y);
	printf("😏️ Swapped values are : %d %d \n", x , y);
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}
