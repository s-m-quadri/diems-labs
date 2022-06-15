// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 7th December 2021


// #########################
//     Header Section
// #########################
#include <stdio.h>
// Order is important. use below, define above
struct ofCollage{
	char name[50];
	int prn;
};
struct ofPersonal{
	char name[50];
	int roll;
};
struct ofResult{
	float sub_marks[4];
};
struct ofStudent {
	struct ofPersonal personal;
	struct ofCollage collage;
	struct ofResult resullt;
};
void get_student(struct ofStudent *Class , int count);
void display_student(struct ofStudent *Class , int count);


// #########################
//       Main Section
// #########################
int main(){
	// Getting size << IMP
	printf("🔸️ How many students are there in the class : ");
	int size_class = 0;
	scanf("%d" , &size_class);
	
	// Error checking  << Optional
	if (size_class <= 0) {
		printf("Sorry ! Not a single student in the class !\n");
		return 0;
	}
	
	// Declaring class << IMP
	struct ofStudent Class[size_class];
	
	// Getting Details from user << IMP
	get_student(Class , size_class);
	
	// Displaying << IMP
	display_student(Class , size_class);
	
	// Done !
	return 0;
}


// #########################
//   Definition Section
// #########################
void get_student(struct ofStudent *Class , int count){
	// Getting Details from user
	for (int i = 0 ; i < count ; i++){
		printf("🔸️ Enter the details of student %02d \n",i+1);
		printf("\t🔹️ Name    \t: ");
		scanf(" %[^\n]%*c" , Class[i].personal.name);
		printf("\t🔹️ Roll     \t: ");
		scanf("%d" , &Class[i].personal.roll);
		printf("\t🔹️ Clg. Name \t: ");
		scanf(" %[^\n]%*c" , Class[i].collage.name);
		printf("\t🔹️ Clg. PRN \t: ");
		scanf("%d" , &Class[i].collage.prn);
		printf("\t🔹️ Mark out of 100 among\n");
		for (int j = 0 ; j < 4 ; j++){
			printf("\t    Sub %02d \t: " , j+1);
			scanf("%f" , &Class[i].resullt.sub_marks[j]);
		}
		printf("\n");
	}
}

void display_student(struct ofStudent *Class , int count){
	// Displaying
	printf("\n Now ...\n Displaying The Details ... \n");
	for(int i = 0 ; i < count ; i++){
		printf("\n🔸️ Details of student %02d from class\n" , i+1);
		printf("\t🔹️ Name    \t: %s    \n" , Class[i].personal.name);
		printf("\t🔹️ Roll    \t: %d    \n" , Class[i].personal.roll);
		printf("\t🔹️ Clg. Name\t: %s    \n" , Class[i].collage.name);
		printf("\t🔹️ Clg. PRN \t: %d    \n" , Class[i].collage.prn);
		float total = 0;
		printf("\t🔹️ Mark out of 100 among\n");
		for (int j = 0 ; j < 4 ; j++){
			printf("\t    Sub %02d \t: %02.2f\n" , j+1 , Class[i].resullt.sub_marks[j]);
			total += Class[i].resullt.sub_marks[j];
			}
		printf("\t🔹️ Total is \t: %02.2f%% \n", total/4);
	}
	
}
