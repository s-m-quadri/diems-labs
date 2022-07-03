// By 5MQuadr! (s-m-quadri@github , 26107@diems2021)
// Last Updated On : 9th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>


// #########################
//       MAIN FUNCTION
// #########################
int main(){

	
	// Getting size of 2d array form user
	int rows=0, cols=0;
	printf("\n🔹️ Enter the number of rows : ");
	scanf("%d",&rows);
	printf("🔹️ Enter the number of cloumns : ");
	scanf("%d",&cols);
	printf("\n");
	
	// Getting array
	int array_2d[rows][cols];
	for (int i = 0 ; i < rows ; i++ ){
		for (int j = 0 ; j < cols ; j++){
			printf("Enter (%d,%d) element : ", i+1 , j+1);
			scanf("%d", &array_2d[i][j]);
		}
	}
	
	// Printing Array
	printf("\n\nNice ! You Have Entered \n\n");
	for (int i = 0 ; i < rows ; i++ ){
	printf("🔸️ ");
		for (int j = 0 ; j < cols ; j++){
			printf("%d", array_2d[i][j]);
			printf(" ");
		}
	printf("\n");
	}
	printf("\n");
}
