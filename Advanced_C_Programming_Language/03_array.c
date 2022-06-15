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
	int no_of_students;
	printf("👨️ Enter the number of students : ");
	scanf("%d",&no_of_students);
	int marks[no_of_students] , sum;
	for(int i = 0 ; i < no_of_students ; i++){
		printf("Enter the Marks of student number %d : ", (i+1));
		scanf("%d", &marks[i]);
		sum += marks[i];
	}
	printf("The avarage is %d \n", (sum/no_of_students));
}
