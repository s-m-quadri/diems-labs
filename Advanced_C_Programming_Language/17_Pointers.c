// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 14th December 2021


// #########################
//     Header Section
// #########################
#include <stdio.h>
typedef struct{
	int *ptr; // 8 blo
	int  x; // 4
	char a; // 1
	char d; // 1
	double e; // 8
} structure ;


// #########################
//   Definition Section
// #########################

// 😥️ . . . ! ! !

// #########################
//       Main Section
// #########################
int main(){
	/* TASK 01 : print the pointer and structure size by variation in the order of structure */
	int a =3;
	int *ptr = &a;
	printf(" ------------------------------------------------------------------------------------- \n");
	printf("                  Size of pointer ptr is 🔹️ %ld bytes\n" , sizeof(int*));
	printf("                   Pointer ptr points to 🔸️ %p in memory\n" , ptr);
	printf("           Value where the ptr points is 🔸️ %d (a = %d @ %p)\n" , *ptr , a , &a);
	printf("                    Size of structure is 🔹️ %ld bytes\n" , sizeof(structure));
	printf(" ------------------------------------------------------------------------------------- \n");
	
	/* TASK 02 : declare pointer, initialize (to avoid dangling). Print the value and address along with
	referencing operator (&) and de-referencing operator (*) by changing the value of variable directly 
	or through reference. */
	int *pc , c;
	pc = &c;
	printf("🔹️ Substitute c =  22 ...\n");
	c = 22;
	printf("           Value of pc is 🔸️ %p \t@ %p in memory\n" , pc , &pc);
	printf("            Value of c is 🔸️ %d \t\t@ %p in memory\n" , c , &c);
	printf("          Value of *pc is 🔸️ %d \t\t@ %p in memory\n" , *pc , &*pc);
	printf("🔹️ Substitute *pc =  11 ...\n");
	*pc = 11;
	printf("           Value of pc is 🔸️ %p \t@ %p in memory\n" , pc , &pc);
	printf("            Value of c is 🔸️ %d \t\t@ %p in memory\n" , c , &c);
	printf("          Value of *pc is 🔸️ %d \t\t@ %p in memory\n" , *pc , &*pc);
	
	/* TASK 03 : declare array, access by pointer and also construct array of pointer. Further, declare 
	array of string and display. By default initialize and do the appropriate operation as per the need. */
	const int MAX = 4;
	int array[] = {1 , 3 , 6 , 5 , 0};
	int *array_ptr[MAX]; // array of pointer
	// 03.1. Display through pointer.
	for (int *tpr = array , index = 0 ; *tpr != 0 ; tpr++ , index++){ 
		printf("         >> array[%d] = %d  << value is accessed through pointer . . . ! ! ! \n"
			, index , *tpr);
		array_ptr[index] = tpr;
	}
	// 03.2. Display through array of pointers to array.s
	printf(" ------------------------------------------------------------------------------------- \n");
	printf("         --------------------------------------------------------- \n");
	printf("                🔹️  Through array of pointers to array  🔹️ \n");
	printf("         --------------------------------------------------------- \n");
	for (int i = 0 ; i < MAX ; i++)
		printf("              Value @ %p corresponds to array[%d] = %d\n" , array_ptr[i] , i+1 , *array_ptr[i]);
	// 03.3. Construct and display array of strings.
	printf("         --------------------------------------------------------- \n");
	printf("                    🔹️  ! . Array of string  . !  🔹️ \n");
	printf("         --------------------------------------------------------- \n");
	char *students[] = {"Waseb Ikramoddin","Siddesh Kumar","Vinayak","Sajid Shaikh"};
	for (int i = 0 ; i < MAX ; i++) 
		printf("                   >>  student[%d] = %s\n" , i+1 , students[i]);
	printf(" ------------------------------------------------------------------------------------- \n");
	
	// 04. Done successfully . . . ! ! !
	return 0;
}
