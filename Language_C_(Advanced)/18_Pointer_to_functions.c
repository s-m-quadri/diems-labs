// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 3rd January 2021


// #########################
//     Header Section
// #########################
#include <stdio.h>
#include <stdlib.h>


// #########################
//   Definition Section
// #########################
int addition(){
	printf("Enter any two numbers : ");
	int a,b;
	scanf("%d %d" , &a , &b);
	return a+b;
}

int addition_2(int a , int b){
	return a + b;
}

int addition_3(int a , int b , int c){
	return a + b + c;
}

void update_salary(int *salary , int extra){
	*salary += extra;
}

int *get_max(int *a , int *b){
	return (*a > *b) ? (a) : (b);
}

void swap(int *a , int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

// #########################
//       Main Section
// #########################
int main(){	
	// 01. Pointer to the function
	printf("----------------------------------------------------------------\n");
	int (*ptr_to_addition)() = addition;
	printf("Addition is : %d\n",ptr_to_addition());
	int (*ptr_to_addition_of_two)(int , int)=addition_2;
	printf("Addition of 3 and 4 is : %d\n" , ptr_to_addition_of_two(3,4));
	int (*ptr_to_addition_of_three)(int , int , int) = addition_3;
	printf("Addition of 3,3 and 4 is : %d\n",ptr_to_addition_of_three(3,3,4));
	
	// 02. Pointer to function as an argument
	printf("----------------------------------------------------------------\n");
	int salary = 0 , bonus = 0;
	printf("Enter the salary and bonus respectively : ");
	scanf("%d %d" , &salary , &bonus);
	update_salary(&salary , bonus);
	printf("New salary will be Rs. %d /-\n" , salary);
	
	// 03. Returning pointer from the function
	printf("----------------------------------------------------------------\n");
	printf("Enter any two numbers : ");
	int a3 = 0 , b3 = 0;
	scanf("%d %d" , &a3 , &b3);
	printf("         You have entered : x = %d and y = %d\n" , a3 , b3);
	printf("      In which maximum is : %d \n" , *get_max(&a3 , &b3));
	swap(&a3 , &b3);
	printf("    They're swapped ! now : x = %d and y = %d\n" , a3 , b3);
	
	// 04. Simple Dynamic Memory allocation
	printf("----------------------------------------------------------------\n");
	char *name = (char*) malloc (10 * sizeof(int));
	name = "DIEMS_ACPL_LABS";
	printf("name = %s\n",name);
	
	// Done !
	printf("----------------------------------------------------------------\n");
	return 0;
}


