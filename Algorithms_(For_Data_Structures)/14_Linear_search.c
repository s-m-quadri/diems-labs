// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 3rd February 2022


// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#include <string.h>


// ###########################
//        Main Section
// ###########################
int main(void){
	// 1. Get the number of houses
	printf("Enter the number of houses : ");
	int count = 0;
	scanf("%d", &count);
	
	// 2. Get the addresses of all houses from planner
	//    maximum limit is of 50 charachter
	//    hence, we have used 2D arrays for this purpose
	char address[count][50];
	for(int i = 0 ; i < count ; i++){
		printf("House address (in lower case) improper order : ");
		scanf(" %[^\n]", &address[i]);
	}
	
	// 3. Prompt the postman to search it
	printf("Postman is searching for ? (give address) : ");
	char element[50];
	scanf(" %[^\n]", element);
	
	// 4. Linearly search for the element, if found prompt it!
	for(int i = 0 ; i < count ; i++){
		if(strcmp(element, address[i]) == 0) {
			printf("Found!\n");
			return 0;
		}
	}
	
	// 5. if not found, return error, some value other than 0
	return 1;
}
