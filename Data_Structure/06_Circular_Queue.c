// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 11th December 2021


// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1, rear = -1;
void enqueue();
void dequeue();
void display();

// ###########################
//     Definition Section
// ###########################
void enqueue(){
	if ((front == 0 && rear==MAX_SIZE-1) || (front == rear + 1)) printf("Queue is full !\n");
	else{
		// Get input
		int input = 0;
		printf("Enter the value : ");
		scanf("%d" , &input);
		// Insert
		if (front == -1) front++;	// if empty
		rear = (rear + 1) % MAX_SIZE;
		queue[rear] = input;
		printf("%d is inserted.\n" , input);	
	}
}

void dequeue(){
	if (front == -1) printf("Queue is Empty ! \n");
	else{
		// Delete
		printf("%d is being deleted.\n" , queue[front]);
		if(front == rear) front = rear = -1; // if last
		else front = (front + 1) % MAX_SIZE; // if not last

	}
}

void display(){
	if (front == -1) printf("Queue is Empty ! \n");
	else{
		printf("Queue status 🔸️ ");
		if (front > rear) {
			for (int i = front ; i <=  MAX_SIZE-1 ; i++) printf("%d " , queue[i]);
			for (int i = 0 ; i <=  rear ; i++) printf("%d " , queue[i]);
		}
		else for (int i = front ; i <=  rear ; i++) printf("%d " , queue[i]);
		printf("\n");
	}
}


// ###########################
//        Main Section
// ###########################
int main(){
	int ch;
	while (1) {
		printf("-------------------------------------------\n");
		printf("  1. Enqueue an element to the queue.\n");
		printf("  2. Dequeue an element from the queue.\n");
		printf("  3. Display elements of queue.\n");
		printf("  4. Exit.\n");
		printf("-------------------------------------------\n  ");
		display();
		printf("-------------------------------------------\n");
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
