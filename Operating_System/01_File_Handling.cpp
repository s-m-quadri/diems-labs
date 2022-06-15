// By 5MQuadr! (s-m-quadri@github , CSE-SY@diems2020-24)
// Last Updated on : 12th April 2022

#include <stdio.h>

int main(void){
    //////////////////////////////////////////////////////////////////
    // 1. Write into the file
    //      a. Open the file to write and check for error
    //      b. Get the input from user
    //      c. Put it into the file
    //      d. Close the file
    //////////////////////////////////////////////////////////////////
    FILE *ptr = fopen("abc.txt", "w");
    if(ptr == NULL){
        printf("Sorry! somthing went wrong.\n");
        return 1;
    }
    char input[50];
    printf("Input : ");
    scanf(" %[^\n]", input);
    fputs(input, ptr);
    fclose(ptr);
    ptr = NULL;

    //////////////////////////////////////////////////////////////////
    // 2. Read from the file
    //     a. Open the file to read and check for error
    //     b. Print the output from the file
    //     c. Close the file
    //////////////////////////////////////////////////////////////////
    ptr = fopen("abc.txt", "r");
    if(ptr == NULL){
        printf("Sorry! somthing went wrong.\n");
        return 1;
    }
    printf("Output : ");
    char buffer = fgetc(ptr);
    while(buffer != EOF){
        printf("%c", buffer);
        buffer = fgetc(ptr);
    }
    printf("\n");
    fclose(ptr);
    ptr = NULL;

    //////////////////////////////////////////////////////////////////
    // 3. Done!
    //////////////////////////////////////////////////////////////////
    return 0;
}
