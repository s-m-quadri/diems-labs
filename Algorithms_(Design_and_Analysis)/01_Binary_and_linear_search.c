// Header Section
#include <stdio.h>

// * For TURBO C++ functionality of clearing and holding screen
// #include <conio.h>
//    NOTE:
// 	This is only for TURBO C++, if you're not using it
// 	delete the above single line

// Globally storing the members and search key
int members[5];
int key;

// Binary Search function (takes two argument as the boundaries)
void binsearch(int A, int Z){
	// Till the boundaries exist (i.e. don't overlap)
	if(A < Z){
		// 1. Find the mid term
		int mid = (A + Z)/2;
		// 2. If it is the desire element, we've found it!
		if (members[mid] == key){
			printf("Found %d (@%d location) using binary search!\n", key, mid);
			return;
		}
		// 3. No! it's less than middle, search in first half.
		if (members[mid] > key){
			binsearch(A, mid);
		}
		// 4. Otherwise (it's greater than middle),
		//    search in second half.
		else{
			binsearch(mid+1, Z);
		}

	}
	// If the boundary orlap, i.e. finished searching
	// print that we don't found it.
	else{
		printf("Sorry! Not found using binary search.\n");
	}
}

// Linear serach function
void linsearch(){
    	// Search linearly for desire value

	for (int i = 0 ; i < 5 ; i++){
		// If found! print the success and exit.
		if (members[i] == key){
			printf("Found %d (@%d location) using linear search!\n", members[i], i);
			return;
		}
	}
	// Not found till this point. Surely it doesn't exist, it means.
	printf("Sorry! Not found using linear search.\n");
}

int main(void){
	// * Clear the screen
	// clrscr();
	//    NOTE:
	// 	This is only for TURBO C++, if you're not using it
	// 	delete the above single line

	///////////////////////////////////////////////////////////
	// 1. Get the Array elements
	printf("Enter the elements of array.\n");
	for(int i = 0 ; i < 5 ; i++){
		printf("\tElement %02d : ", i+1);
		scanf("%d", &members[i]);
	}
	// 2. Get the element user want to search for
	printf("Enter the value to search : ");
	scanf("%d", &key);
	// 3. Search for the key, using function call
	binsearch(0, 4);
	linsearch();
	///////////////////////////////////////////////////////////

	// * Hold the screen
	// getch();
	//    NOTE:
	// 	This is only for TURBO C++, if you're not using it
	// 	delete the above single line

	// 4. Done!
	return 0;
}
