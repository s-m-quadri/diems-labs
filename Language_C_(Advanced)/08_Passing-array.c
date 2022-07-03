// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 23rd November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
// Display Function
void display_char(char ch);
void display_char_array(char *array, int count);
void display_int_array(int *array, int count);
// Other Functions
int get_min(int *array, int count);


// #########################
//       MAIN FUNCTION
// #########################
int main(){
    // Initialize array
	char array[10] = {'A' ,'C' ,'P' ,'L' ,'@' ,'D' ,'I' ,'E' ,'M' ,'S'};
	
	// Display character-wise
	for (int i = 0 ; i < 10 ; i++) display_char(array[i]);
	printf("\n");
	
	// Display whole array
	display_char_array(array , 10);
	
    // Initialize , display and find minimum in "Number Array"
	int num[10] = { 18 , 24 , 78 , 10 , 34 , 81 , 65 , 62 , 77 , 11};
	display_int_array(num , 10);
	printf("The minimum in number array is %d\n" , get_min(num , 10));
	
	// Done !!!
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
void display_char(char ch){
	printf("%c " , ch);
}

void display_char_array(char *array, int count){
	for (int i = 0 ; i < count ; i++) printf("%c " , array[i]);
	printf("\n");
}

void display_int_array(int *array, int count){
	printf("🔹️ ");
	for (int i = 0 ; i < count ; i++) printf("%d " , array[i]);
	printf("\n");
}

int get_min(int *array, int count){
	// Consider first element as minimum.
    int min = array[0];
    for (int i = 0 ; i < count ; i++){
    	// But what if >>>> upcoming "is less than" minimum
    	// In such case, correct them...
        if (array[i] < min) min = array[i];
        // Else continue...
        else continue;
    }
    return min;
}
