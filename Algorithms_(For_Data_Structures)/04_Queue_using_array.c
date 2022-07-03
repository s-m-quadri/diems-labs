// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 09th December 2021


// ###########################
//  HEADERS AND GLOBAL DATA
// ###########################
#include <stdio.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1 , rear = -1;

void enqueue(){
	if (rear == MAX_SIZE-1) printf("Queue is Full\n");
	else{
		int input = 0;
		printf("Enter the value : ");
		scanf("%d" , &input);
		if (front == -1){
			front = 0;
			rear = 0;
			queue[rear] = input;
		}
		else {
			rear++;
			queue[rear] = input;
		}
		printf("%d is inserted.\n",input);
	}
}

void dequeue(){
	if (front == -1) printf("Queue is empty !\n");
	else if (front == rear) {
		int temp = queue[front];
		front = -1;
		rear = -1;
		printf("%d is deleted\n",temp);
	}else{
		int temp = queue[front];
		front++;
		printf("%d is deleted\n",temp);
	}
}

void display(){
	if (front == -1) printf("Queue is empty !\n");
	else {
		for (int i = front ; i <= rear ; i++) printf(" %d",queue[i]);
		printf("\n");
	}
}

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
