// By 5MQuadr! (s-m-quadri@github , 26107@diems2021-22)
// Last Updated on : 25th November 2021


// ########################
//  HEADERS AND PROTOTYPES
// ########################
#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();


// ########################
//      GLOBAL DATA
// ########################
struct node{
	int data;
	struct node *next;
};
struct node *top = NULL;


// ########################
//     MAIN FUNCTION
// ########################
int main(){
	int ch;
	while (1) {
		printf("-----------------------------------\n");
		printf("1. Push an element to the stack.\n");
		printf("2. Pop an element from the stack.\n");
		printf("3. Display elements of stack.\n");
		printf("4. Exit.\n");
		printf("-----------------------------------\n");
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		switch (ch){
			case 1 : push(); break;
			case 2 : pop(); break;
			case 3 : display(); break;
			case 4 : return 0;
			default : printf("Enter valid choice. Try again.\n");
		}
	}
	return 0;
}


// ########################
//  FUNCTIONS DEFINITIONS
// ########################
void push(){
	// Declare and allocate (Dynamically)
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	// Get data - setting node through pointer
	printf("Enter the new value : ");
	scanf("%d" , &temp->data);
	temp->next = top;
	// Set data - to stack by updating pointer
	printf("🔸️ Now %d is added to the stack.\n" , temp->data);
	top = temp;
}

void pop(){
	// Check for underflow condition - is stack empty
	if (top == NULL) printf("🔺️ Nothing to display, stack is empty !\n");
	else{
		// Duplicate top pointer to temp
		struct node *temp = top;
		// Delete
		printf("🔸️ Now %d is being deleted from the stack.\n" , temp->data);
		top = temp->next; 	// 1. Update top
		free(temp); 		// 2. Free space
		temp = NULL; 		// 3. Avoid it to be dangling pointer
	}
}

void display(){
	printf("🔹️ ");
	for(struct node *temp = top ; temp != NULL ; temp = temp->next)
		printf("%d ", temp->data);
	printf("\n");
}









