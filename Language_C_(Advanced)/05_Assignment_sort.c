// By 5MQuadr! (s-m-quadri@github , 26107@diems2021)
// Last Updated On : 14th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
int get_size();
void get_array(int *array, int size);
void sort_array(int *array, int size);
void print_array(int *array, int size);


// #########################
//       MAIN FUNCTION
// #########################
int main(){
	// Getting size
	int its_size = get_size();
	
	// Initializing array
	int array[its_size];
	get_array(array , its_size);
	
	// Sorting it
	sort_array(array , its_size);
	
	// And Finally Printing it
	print_array(array , its_size);
	
	// Successfully Done !!!
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
int get_size(){
	int size;
	printf("How many elements in the array : ");
	scanf("%d" , &size);
	return size;
}

void get_array(int *array, int its_size){
	printf("Enter the %d elements : \n", its_size);
	
	for (int i = 0 ; i < its_size ; i++) {
		printf("🔹️ Enter Element (%d) : ",i+1);
		scanf("%d" , &array[i]);
	}
}

void sort_array(int *array, int its_size){
	for (int right = 0 ; right < its_size ; right++){
		for (int left = 0 ; left < its_size ; left++){
			// ascending order is increasing order
			// like 1 2 3 4 5 (left < right)
			// but if it is out of order ...
			if (array[left] > array[right]){
				// then swap them !!!
				int temp = array[right];
				array[right] = array[left];
				array[left] = temp;
			} else continue;
		}
	}
}

void print_array(int *array, int its_size){
	printf("Now elements are ...");
	for (int i = 0 ; i < its_size ; i++){
	if (i%10 == 0) printf("\n🔸️ ");
	printf("%d " , array[i]);
	}
	printf("\n");
}
