// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 11th December 2021


// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int turn = 0 , upcoming = 0;


// ###########################
//     Definition Section
// ###########################
void enqueue(){
	if (upcoming == MAX_SIZE) printf("Sorry ! Queue is full.\n");
	else {
		int input = 0;
		printf("Enter the value : ");
		scanf("%d",&input);
		// 1. 	Let's Get into queue !
		// 	Insert upcoming person at ...
		// 	"who's turn" + "how many remain" within "limit of MAX_SIZE"
		// 	... index calculations (important)
		queue[(turn + upcoming) % MAX_SIZE] = input;
		// 2. 	How many waiting ?
		// 	Number of person(s) increased in the waiting
		upcoming++;
		printf("%d is inserted.\n",input);
	}
}

void dequeue(){
	if (upcoming == 0) printf("Queue is Empty !\n");
	else {
		printf("%d is being deleted.\n",queue[turn]);
		// 1. 	Who's next ?
		// 	Insert upcoming person at  ...
		// 	"next turn" within "limit of MAX_SIZE"
		// 	Important !!!
		turn = (turn + 1) % MAX_SIZE;
		// 2. 	How many waiting ?
		// 	Number of person(s) decreased in the waiting
		upcoming--;
	}
}

void display(){
	if (upcoming == 0) printf("Queue is Empty ! Nothing to display.\n");
	else {
		for (int i = 0 ; i < upcoming ; i++)
			printf("%d " , queue[(turn + i) % MAX_SIZE]);
		printf("\n");
	}
}


// ###########################
//        Main Section
// ###########################
int main(){
	int ch;
	while (1) {
		printf("-----------------------------------\n");
		printf("1. Enqueue an element to the queue.\n");
		printf("2. Dequeue an element from the queue.\n");
		printf("3. Display elements of queue.\n");
		printf("4. Exit.\n");
		printf("-----------------------------------\n");
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		switch (ch){
			case 1 : enqueue(); break;
			case 2 : dequeue(); break;
			case 3 : display(); break;
			case 4 : return 0;
			default : printf("Enter valid choice. Try again.\n");
		}
	}
	return 0;
}
