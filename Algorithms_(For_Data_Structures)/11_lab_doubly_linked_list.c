// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 13th January 2022


// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
} *start = NULL;


// ###########################
//     Definition Section
// ###########################
void insert(){
	// 1. Getting the input from the user
	printf("Enter the value to be inserted in the list : ");
	int input = 0;
	scanf("%d" , &input);
	
	// 2. Set the node
	struct node *temp = (struct node *) malloc (sizeof(struct node));
	temp -> data = input;
	temp -> next = NULL;
	temp -> prev = NULL; // addition
	
	// 3. Inserting the element at the specified position by user
	if (start == NULL) start = temp;
	else {
		printf("Enter the value after which node should be inserted : ");
		int info = 0;
		scanf("%d" , &info);
		
		struct node *ptr = start;
		while (ptr -> data != info) ptr = ptr -> next;
		
		temp -> next = ptr -> next;
		temp -> prev = ptr; // addition
		
		ptr -> next = temp;
		if(temp -> next != NULL) temp -> next -> prev = temp; // addition
	}
	
	// 4. Prompting for success
	printf("%d is inserted !\n" , temp -> data);
}

void del(){
	// 1. Error checking 
	if(start == NULL){
		printf("List is empty !\n");
		return;
	}
	
	// 2. Data from user
	printf("Enter the value you want to delete : ");
	int info = 0;
	scanf("%d" , &info);
	
	
	// 3. Specifying the deletion element as temp
	struct node *temp = start;
	while (temp -> data != info) temp = temp -> next;
	
	// 4. Updating nodes
	if (temp == start){
		printf("%d is deleted !\n" , temp -> data);
		start = start -> next;
		temp -> next = NULL;
		temp -> prev = NULL; // addition
	}
	
	else if (temp -> next  == NULL){
		printf("%d is deleted !\n" , temp -> data);
		struct node *r = start;
		while (r -> next != temp) r = r -> next;
		
		r -> next = NULL;
		temp -> next = NULL;
		temp -> prev = NULL; // addition
	}
	else {
		printf("%d is deleted !\n" , temp -> data);
		struct node *r = start;
		while (r -> next != temp) r = r -> next;
		
		r -> next = temp -> next;
		r -> next -> prev = r; // addition
		
		temp -> next = NULL;
		temp -> prev = NULL; // addition
	}
	
	// 5. Deallocating the element
	free(temp);
	temp = NULL;
	
}

void display(){
	// 1. Error checking
	if(start == NULL){
		printf("List is empty !\n");
		return;
	}
	
	// 2. Display elements
	printf("🔸️ status : ");
	for (struct node *ptr = start ; ptr != NULL ; ptr = ptr -> next)
		printf("%d " , ptr -> data);
	printf("\n");
}


// ###########################
//        Main Section
// ###########################
int main(){
	int ch;
	while (1) {
		printf("-------------------------------------------\n");
		printf("  1. Insert an element to the list.\n");
		printf("  2. Delete an element from the list.\n");
		printf("  3. Display elements of list.\n");
		printf("  4. Exit.\n");
		printf("-------------------------------------------\n  ");
		display();
		printf("-------------------------------------------\n");
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		switch (ch){
			case 1 : insert(); break;
			case 2 : del(); break;
			case 3 : display(); break;
			case 4 : return 0;
			default : printf("Enter valid choice. Try again.\n");
		}
	}
	return 0;
}







