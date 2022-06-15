// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 30th January 2022

// ###########################
//      Header Section
// ###########################
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *right;
	struct node *left;
} *root = NULL;

// ###########################
//     Definition Section
// ###########################
void insert(struct node *r, struct node *input){
	if (input->data < r->data){
		if (r->left == NULL){
			r->left = input;
			printf("%d is inserted left of %d !\n", input->data, r->data);
		} else 	insert(r->left, input);
	} else if (input->data > r->data){
		if (r->right == NULL){
			r->right = input;
			printf("%d is inserted right of %d !\n", input->data, r->data);
		} else 	insert(r->right, input);
	} else printf("%d is already present !\n", input->data);
	
}

void search(struct node *r, int key){
	if (r == NULL) printf("Value dosn't exist in BST\n");
	else if (r->data == key) printf("Value exist !\n");
	else if (r->data > key) search(r->left, key);
	else search(r->right, key);
}

// ###########################
//        Main Section
// ###########################
int main(){
	int ch;
	while (1){
		printf("-------------------------------------------\n");
		printf("  1. Insert an element to the BST.\n");
		printf("  2. Search an element in the BST.\n");
		printf("  3. Exit.\n");
		printf("-------------------------------------------\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		switch (ch){
		case 1:
			printf("Enter new data : ");
			struct node *p = NULL;
			p = (struct node *)malloc(sizeof(struct node *));
			scanf("%d", &p->data);
			p->right = p->left = NULL;
			if (root == NULL) root = p;
			else insert(root, p);
			break;
		case 2:
			printf("Enter value to search for : ");
			int input = 0;
			scanf("%d", &input);
			search(root, input);
			break;
		case 3:
			return 0;
		default:
			printf("Enter valid choice. Try again.\n");
		}
	}
	return 0;
}
