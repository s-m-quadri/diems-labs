// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 30th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
#include <string.h>
#define SIZE_LIB1 2
void structure_books();
void structure_employee();

// employee global data ...
struct ofEmployee {
	char name[50];
	int age;
	float salary;
	char email_id[50];
};

// employee prototypes
void get_employee(struct ofEmployee *Company , int count);
void display_employee(struct ofEmployee *Company , int count);


// #########################
//       MAIN FUNCTION
// #########################
int main(){

	/* TASK 1 :
	Write a program to illustrate the use of structures.
	NOTE : Uncomment below line to execute structure of book (in any) */
	//structure_books();
	
	/* TASK 2 :
	Write a program to illustrate the passing structures to functions.
	NOTE : Uncomment below line to execute structure of employee (in any) */
	structure_employee();

	// Done !
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
void structure_employee(){
	// Getting size 
	printf("🔸️ How many employees are there in the company : ");
	int size_company = 0;
	scanf("%d" , &size_company);
	
	// Error checking
	if (size_company <= 0) {
		printf("Sorry ! No employee in the company !\n");
		return;
	}

	// Declaring company	
	struct ofEmployee Company[size_company];
	// Getting Details from user
	get_employee(Company , size_company);
	// Displaying
	display_employee(Company , size_company);
}

void get_employee(struct ofEmployee *Company , int count){
	// Getting Details from user
	for (int i = 0 ; i < count ; i++){
		printf("🔸️ Enter the details of employee %02d \n",i+1);
		printf("\t🔹️ Name    \t: ");
		scanf(" %[^\n]%*c" , Company[i].name);
		printf("\t🔹️ Age     \t: ");
		scanf("%d" , &Company[i].age);
		printf("\t🔹️ Salary  \t: Rs. ");
		scanf("%f" , &Company[i].salary);
		printf("\t🔹️ Email-id\t: ");
		scanf(" %[^\n]%*c" , Company[i].email_id);
		printf("\n");
	}
}

void display_employee(struct ofEmployee *Company , int count){
	// Displaying
	printf("\n Now ...\n Displaying The Details ... \n");
	for(int i = 0 ; i < count ; i++){
		printf("\n🔸️ Details of Employee %d from Company\n" , i+1);
		printf("\t🔹️ Name    \t: %s    \n" , Company[i].name);
		printf("\t🔹️ Age     \t: %d    \n" , Company[i].age);
		printf("\t🔹️ Salary  \t: Rs. %02.2f /-    \n" , Company[i].salary);
		printf("\t🔹️ Email id\t: %s   \n" , Company[i].email_id);
	}
	
}

void structure_books(){
	// Structure data type for book
	struct ofBook {
		char name[50];
		char author[50];
		char subject[100];
		int no_pages;
		float price;
	} lib1[SIZE_LIB1];

	// Details of Book 1 from Library 1
	strcpy(lib1[0].name, "Let us C");
	strcpy(lib1[0].author, "Unknown");
	strcpy(lib1[0].subject, "Computer science");
	lib1[0].no_pages = 250;
	lib1[0].price = 349.25;
	
	// Details of Book 2 from Library 1
	strcpy(lib1[1].name, "Data structures in C");
	strcpy(lib1[1].author, "Unknown");
	strcpy(lib1[1].subject, "Data Structures");
	lib1[1].no_pages = 223;
	lib1[1].price = 390.00;
	
	// Displaying the details of book
	for(int i = 0 ; i < SIZE_LIB1 ; i++){
		printf("\n🔸️ Details of Book %d from library 1\n" , i+1);
		printf("\t🔹️ Name   \t : %s    \n" , lib1[i].name);
		printf("\t🔹️ Author \t : %s    \n" , lib1[i].author);
		printf("\t🔹️ Subject\t : %s    \n" , lib1[i].subject);
		printf("\t🔹️ Pages  \t : %3d   \n" , lib1[i].no_pages);
		printf("\t🔹️ Price  \t : Rs. %2.2f /- \n\n" , lib1[i].price);
	}
}



