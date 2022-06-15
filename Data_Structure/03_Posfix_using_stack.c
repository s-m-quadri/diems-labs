// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 02nd December 2021


// ###########################
//  HEADERS AND GLOBAL DATA
// ###########################
#include <stdio.h>
#include <ctype.h>
int stack[20];
int top = -1;

// ########################
//        FUNCTIONS
// ########################
void push(int input){
	// Increase pointer
	top++;
	// Put the input into the stack
	stack[top] = input;
}

int pop(){
	// Return stack[top] then only decrement the value of top
	return stack[top--];
	
}




// ########################
//     MAIN FUNCTION
// ########################
int main(){
	// Getting expression from the user
	printf("🔹️ Enter the post-fix expression : ");
	char postfix[21];
	scanf("%s" , postfix);
	
	// Performing operations taking "ptr" as temporary
	for (char *ptr = postfix ; *ptr != '\0' ; ptr++){
		// if it is digit - push integer value not ASCII
		// for ASCII
		// '0' = 48 (= 48+0)
		// '1' = 49 (= 48+1)
		// '2' = 50 (= 48+2)
		// '3' = 51 (= 48+3)
		// ... and so on ... i.e 48 is extra
		if (isdigit(*ptr)) push(*ptr - 48);
		else {
			// if there is operator then pop 2 times
			// and apply operation
			int n1 = pop();
			int n2 = pop();
			switch(*ptr){
				case '+' : push(n2 + n1); break;
				case '-' : push(n2 - n1); break;
				case '*' : push(n2 * n1); break;
				case '/' : push(n2 / n1); break;
				case '%' : push(n2 % n1); break;
				// Error checking
				default : printf("🔺️ Sorry ! invalid symbol - couldn't process.\n");
				return 0;
			}
		}

	}
	
	// Printing Result
	printf("🔸️ Result is %d\n" , pop());
	
	// Successfully done !
	return 0;
}









