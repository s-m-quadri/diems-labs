// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 13th December 2021


// #########################
//     Header Section
// #########################
#include <stdio.h>
enum {TRUE = 1 , FALSE = 0};

typedef struct{
	int center_x , center_y;
	float radius;
	double area;
} sphere ;

typedef union{
	int center_x , center_y;
	float radius;
	double area;
} ball ;

typedef short unsigned int tiny;



// #########################
//   Definition Section
// #########################

// 😥️ . . . ! ! !

// #########################
//       Main Section
// #########################
int main(){
	tiny size = (tiny) sizeof(ball);
	printf("Size of tiny is %d bytes only !\n" , (tiny) sizeof(tiny));
	printf(" -----------------------------------------------------  \n");
	printf("   Size of Circle (2 x int , 1 x float , 1 x double)\n");
	printf(" -----------------------------------------------------  \n");
	printf("      As an union is 🔸️ %02d bytes\n" , size);
	printf("   As a structure is 🔸️ %02d bytes\n" , (tiny) sizeof(sphere));
	printf(" -----------------------------------------------------  \n");
	
	printf("The value of TRUE is %d\n" , TRUE);
	printf("The value of FALSE is %d\n" , FALSE);
	return 0;
}
