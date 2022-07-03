// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 28th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
int get_size();
void get_array(int *array, int size);
int get_sum(int *array, int size);


// #########################
//       MAIN FUNCTION
// #########################

// TASK - Write a program 
// To calculate sum of array 
// By passing "an array" to "the function"

int main(){
// 1. Declare and initialize array size ... (through function by user)
	int size = get_size();
// 2. And declare array ...
	int array[size];
// 3. Then Initialize array ... (By passing array to function)
	get_array(array , size);
// 4. Finally Printing sum of array ... (By passing array to function)
	printf("🔸️ Sum of elements is %d \n" , get_sum(array , size));
// 5. Done successfully !!!
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
int get_size(){
	int input;
	printf("🔹️ Enter the size of array : ");
	scanf("%d" , &input);
	return input;
}

void get_array(int *array, int size){
	for (int i = 0 ; i < size ; i++){
		printf("Enter the %dth element : " , i+1);
		scanf("%d" , &array[i]);
	}
}

int get_sum(int *array, int size){
	int sum=0;
	for (int i = 0 ; i < size ; i++) sum += array[i];
	return sum;
}
