// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 3rd January 2021


// #########################
//     Header Section
// #########################
#include <stdio.h>
#include <stdlib.h>
//#include "15_structure_task.c"


// #########################
//   Definition Section
// #########################


// #########################
//       Main Section
// #########################
int main(){	
	FILE *file_info;
	char temp[200];
	
	// 1. Open to write
	printf("🔹️ Enter the details.\n");
	printf("```````````````````````\n");
	file_info = fopen("/home/lab-20-1/A66/info.txt" , "w");
	printf("Enter Your name : ");
	scanf(" %[^\n]" , temp);
	fprintf(file_info , "Your name is Mr. %s.\n" , temp);
	printf("Enter Your roll number / ID : ");
	scanf(" %[^\n]" , temp);
	fprintf(file_info , "Your roll number is %s.\n" , temp);
	// fputs("is it correct !\n" , file_info);
	// fputc('c' ,file_info);
	fclose(file_info);
	
	// 2. Open to read
	printf("\n🔹️ Printing from the file.\n");
	printf("```````````````````````````````\n");
	file_info = fopen("/home/lab-20-1/A66/info.txt" , "r");
	// fscanf(file_pointer , .... similar to scanf arguments)
	fscanf(file_info , " %[^\n]\n" , temp);
	printf("%s\n",temp);
	// fgets( String_output , char_count , file_pointer)
	fgets(temp , 200 , file_info);
	printf("%s\n",temp);
	fclose(file_info);
	
	// 3. Duplicating file
	printf("\n🔹️ Duplicating. As info.txt --> info1.txt\n");
	printf("```````````````````````````````````````````````\n");
	FILE *file_sourse = fopen("/home/lab-20-1/A66/info.txt" , "r");
	FILE *file_destination = fopen("/home/lab-20-1/A66/info1.txt" , "w");
	fgets(temp , 200 , file_sourse);
	fprintf(file_destination , "%s" , temp);
	fgets(temp , 200 , file_sourse);
	fprintf(file_destination , "%s" , temp);
	fclose(file_sourse);
	fclose(file_destination);
	printf("Done !\n");
	
	return 0;
}


