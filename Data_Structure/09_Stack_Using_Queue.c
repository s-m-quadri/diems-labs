// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 30th December 2021


// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
} *f1 = NULL , *f2 = NULL , *r1 = NULL , *r2 = NULL;


// ###########################
//     Definition Section
// ###########################
void enqueue1(int input){
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr -> data = input;
	ptr -> next = NULL;
	if (f1 == NULL) f1 = ptr;
	else r1 -> next = ptr;
	r1 = ptr;
}

void enqueue2(int input){
	struct node *ptr = (struct node *) malloc(sizeof(struct node));
	ptr -> data = input;
	ptr -> next = NULL;
	if (f2 == NULL) f2 = ptr;
	else r2 -> next = ptr;
	r2 = ptr;
}

int dequeue1(){
	// Error Check
	if (f1 == NULL) {
		printf("Queue is Empty ! \n");
		return 0;
	}
	
	// Update front
	int data = f1->data;
	struct node *temp = f1;
	f1 = f1 -> next;
	
	// Delete
	free(temp);
	temp = NULL;
	
	// Return Deleted
	return data;
}

int dequeue2(){
	// Error Check
	if (f2 == NULL) {
		printf("Queue is Empty ! \n");
		return 0;
	}
	
	// Update front
	int data = f2->data;
	struct node *temp = f2;
	f2 = f2 -> next;
	
	// Delete
	free(temp);
	temp = NULL;
	
	// Return Deleted
	return data;
}


// ###########################
//        Main Section
// ###########################
int main(){
	// Getting the number of inputs from user
	printf("🔹️ Enter the number of elements : ");
	int count = 0;
	scanf("%d" , &count);
	
	// Getting inputs
	for (int i = 0 ; i < count ; i++){
		printf("\t Enter the %d element : " , i+1);
		int input = 0;
		scanf("%d" , &input);
		enqueue1(input);
	}
	
	// Display element as if it is stack
	printf("🔸️ All Popped : ");
	while( (f1 != NULL) || (f2 != NULL) ){
		if(f2 == NULL) {
			while (f1->next != NULL) enqueue2(dequeue1());
			printf("%d " , dequeue1());
		} else {
			while (f2->next != NULL) enqueue1(dequeue2());
			printf("%d " , dequeue2());
		}
	}
	printf("\n");
	
	// Done !
	return 0;
}







