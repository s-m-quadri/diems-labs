// By 5MQuadr! (s-m-quadri@github , 26107@diems2021)
// Last Updated On : 16th November 2021


// #########################
//   HEADER AND PROTOTYPES
// #########################
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int count(char key , char *name);
void Sentenced_case(char *string);


// #########################
//       MAIN FUNCTION
// #########################
int main(){
	// Get Name and Greet
	char name[51];
	printf("What is your name ? \n");
	scanf("%[^\n]" , name);
	
	// Change to Sentence Case >> IMP <<
	Sentenced_case(name);

	// Add "Mr." as prefix
	char name_display[56]= "Mr. ";
	strcat(name_display , name);
	
	// Greet USER or ADMIN
	if (strcmp("Admin" , name) != 0) printf("🔸️ Welcome %s, nice to meet you !!!\n" , name_display);
	else {
		strcpy(name_display, "BOSS");
		printf("🔸️ Ohh !!! Welcome %s, nice to meet you !!!\n" , name_display);
	}
	
	// Count Vowels And Display
	int vowels = count('a' , name) + count('e' , name) + count('i' , name) + count('o' , name) + count('u' , name);
	int total = (int) strlen(name) - count(' ' , name);
	printf("🔹️ There are %d vowels in your name out of %d \n" , vowels , total);
	
	// Done Successfully !
	return 0;
}


// #########################
//   FUNCTIONS DEFINITIONS
// #########################
int count(char key , char *name){
	int count = 0;
	// Counting the number of occurrence
	for (int i = 0 ; name[i] != '\0' ; i++) if (name[i] == key) count++;
	return count;
}

void Sentenced_case(char *string){
	for (int i = 0 ; string[i] != '\0' ; i++) {
		// "Very first letter" or "first letter after space" of name is there
		// Capitalize it
		if (string[i-1] == ' ' || i == 0) string[i] = toupper(string[i]);
		// Small "all the other" letters
		else string[i] = tolower(string[i]);
	}
}
