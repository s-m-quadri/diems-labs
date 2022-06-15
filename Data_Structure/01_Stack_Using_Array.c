// By 5MQuadr! (s-m-quadri@github , 26107@diems2021-22)
// Last Updated on : 18th November 2021


// ########################
//  HEADERS AND PROTOTYPES
// ########################
#include <stdio.h>
void push();
void pop();
void display();

// ########################
//      GLOBAL DATA
// ########################
#define MAX_SIZE 5
int top=-1; // Empty
int Stack[MAX_SIZE];


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
	int x;
	if (top == MAX_SIZE -1) printf("Sorry, Stack is full !\n");
	else{
		printf("Enter new value : ");
		scanf("%d" , &x);
		top++;
		Stack[top] = x;
		printf("Now %d is added to the stack.\n" , x);
	}
}

void pop(){
	int x;
	if (top == -1) printf("Nothing to display, stack is empty !\n");
	else {
		x = Stack[top];
		top--;
		printf("Now %d is deleted from the stack.\n" , x);
	}
}

void display(){
	if (top == -1) printf("Nothing to display, stack is empty !\n");
	else {
		for (int i = 0 ; i <= top ; i++) printf("%d\n" , Stack[i]);
	}
}
