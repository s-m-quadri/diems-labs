// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 23rd December 2021


// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {true = 1 , false = 0};
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *start = NULL;


// ###########################
//     Definition Section
// ###########################
void insert(){
	int input = 0 , count = 1;
	scanf("%d@%d" , &input , &count);
	
	
	// 1. Error check related to user input
	if(count <= 0 || (start == NULL && count != 1)){
		printf("sorry ! can't find desire location\n");
		return;
	}
	
	// 2. Insertion at starting
	if (count == 1){
		struct node *temp = (struct node*) malloc(sizeof(struct node));
		temp -> data = input;
		temp -> prev = NULL; // addition
		if(start != NULL) start -> prev = temp; // addition
		temp -> next = start;
		start = temp;
		return;
	}
	
	// 3. Insertion at middle or at end
	for (struct node *ptr = start ; ptr != NULL ; ptr = ptr -> next){
		if (--count == 1) {
			struct node *temp = (struct node*) malloc(sizeof(struct node));
			temp -> data = input;
			temp -> prev = ptr; // addition
			temp -> next = ptr -> next;
			ptr -> next -> prev = temp;
			ptr -> next = temp;
			return;
		}
	}
	
	// 4. Failure	
	printf("sorry ! can't find desire location\n");
	return;
}

void delete(){
	int count = 1;
	scanf("%d" , &count);
	
	// 1. Error check related to user input
	if(count <= 0){
		printf("sorry ! can't find desire location\n");
		return;
	}
	
	// 2. Error check related to list
	if (start == NULL) {
		printf("List is empty ! can't remove.\n");
		return;
	}
	
	
	// 3. First element is present only.
	if ((count == 1) && (start -> next == NULL)){
		free(start);
		start = NULL;
		return;
	} 
	
	// 4. First element to be removed.
	if ((count == 1) && (start -> next != NULL)){ 
		struct node *temp = start;
		start = start -> next;
		start -> prev = NULL; // addition
		temp -> prev = NULL;
		temp -> next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
	
	// 5. Otherwise
	for(struct node *ptr = start ; ptr -> next != NULL ; ptr = ptr -> next){
		if (--count == 1){
			struct node *temp = ptr -> next;
			ptr -> next = temp -> next;
			temp -> next -> prev = ptr; // addition
			temp -> prev = NULL; // addition
			temp -> next = NULL;
			free(temp);
			temp = NULL;
			return;
		}
	}
	
	// 6. Failure	
	printf("sorry ! can't find desire location\n");
	return;
}

void display(){
	// 1. Error check related to list
	if (start == NULL) printf("List is empty !\n");
	
	// 2. Display list
	printf("\033[32;1m[START]\033[0m");
	for (struct node *ptr = start ; ptr != NULL ; ptr = ptr -> next)
		printf(" <-> \033[31;1m%d\033[0m", ptr -> data);
	printf(" <-> \033[32;1m[NULL]\033[0m\n");
}

void explain(){
	// 1. Error check related to list
	if (start == NULL) printf("List is empty !\n");
	
	// 2. Display list
	printf("\033[32;1m[START]\033[0m is %p\n",start);
	for (struct node *ptr = start ; ptr != NULL ; ptr = ptr -> next)
		printf("%12p  :  %12p  |\033[31;1m%10d\033[0m  |  %12p\n", ptr , ptr -> prev , ptr -> data , ptr -> next);
	//printf(" or \033[32;1mNULL\033[0m\n");
}

void reverse(){
	// 1. Error check related to list
	if (start == NULL) {
		printf("List is empty ! can't perform operation.\n");
		return;
	}
	
	// 2. Reverse list
	struct node *swap_temp = NULL;
	for (struct node *ptr = start ; ptr != NULL ; ptr = ptr -> prev){
		swap_temp = ptr -> next;
		ptr -> next = ptr -> prev;
		ptr -> prev = swap_temp;
		start = ptr;
	}
}

void help(){
	// add
	printf(" -------------------\n");
	printf(" \033[32;1madd\033[0m value[@position]\n");
	printf(" -------------------\n");
	printf("\t By using it, you can add integers into the linked list.\n");
	printf("\t for example :\n");
	printf("\t $: add 3 \t will add 3 at the beginning\n");
	printf("\t $: add 89 \t will add 89 at the beginning\n");
	printf("\t $: add 4@1 \t will add 4 at beginning\n");
	printf("\t $: add 1@4 \t will add 1 at position 4th\n");
	
	// remove
	printf(" -------------------\n");
	printf(" \033[32;1mremove\033[0m position\n");
	printf(" -------------------\n");
	printf("\t By using it, you can delete integers at the specified position.\n");
	printf("\t for example :\n");
	printf("\t $: remove 3 \t will delete value at 3rd position\n");
	printf("\t $: remove 5 \t will delete value at 5th position\n");
	
	// show
	printf(" -------------------\n");
	printf(" \033[32;1mshow\033[0m\n");
	printf(" -------------------\n");
	printf("\t By using it, you can view the integers in the list\n");
	printf("\t for example :\n");
	printf("\t $: show\t will show all the elements in list\n");
	
	// explain
	printf(" -------------------\n");
	printf(" \033[32;1mexplain\033[0m\n");
	printf(" -------------------\n");
	printf("\t By using it, you can get complete details of elements\n");
	printf("\t for example :\n");
	printf("\t $: explain\t will show almost possible details of elements\n");
	
	// reverse
	printf(" -------------------\n");
	printf(" \033[32;1mreverse\033[0m\n");
	printf(" -------------------\n");
	printf("\t By using it, you can reverse the linked list\n");
	printf("\t for example :\n");
	printf("\t $: reverse\t will reverse the list\n");
	
	// help
	printf(" -------------------\n");
	printf(" \033[32;1mhelp\033[0m\n");
	printf(" -------------------\n");
	printf("\t By using it, you can get details of console command\n");
	printf("\t for example :\n");
	printf("\t $: help\t will list out the command\n");
	
	// exit
	printf(" -------------------\n");
	printf(" \033[32;1mexit\033[0m\n");
	printf(" -------------------\n");
	printf("\t By using it, you can get out of console\n");
	printf("\t for example :\n");
	printf("\t $: exit\t will let you exit.\n");
}


// ###########################
//        Main Section
// ###########################
int main(){
	char input[10];
	printf("\n\033[31;1m");
	printf(" ---------------------------------  \n");
	printf("        Douby List Console  \n");
	printf(" ---------------------------------  \n");
	printf("\n\033[0m");
	while(true) {
		printf("\033[34;1mList $: \033[0m");
		scanf("%s" , input);
		if (strcmp(input, "add") == 0) insert();
		else if (strcmp(input, "remove") == 0) delete();
		else if (strcmp(input, "show") == 0) display();
		else if (strcmp(input, "explain") == 0) explain();
		else if (strcmp(input, "reverse") == 0) reverse();
		else if (strcmp(input, "help") == 0) help();
		else if (strcmp(input, "exit") == 0) return 0;
		else printf("sorry ! we don't understand, type help for help.\n");
	}
	
	// Done successfully !!!
	return 0;
}
