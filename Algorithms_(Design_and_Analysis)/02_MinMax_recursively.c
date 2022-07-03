#include <stdio.h>
#include <stdlib.h>

// Global variables
int *inputs, min, max;

// Getting min function
int get_min(int a, int b){
	return (a<b)?a:b;
}

// Getting max function
int get_max(int a, int b){
	return (a<b)?b:a;
}

// Find min/max in array
void minmax(int a, int b){
	// Sub problem having only one node
	if(a == b) {
		min = get_min(inputs[a], min);
		max = get_max(inputs[a], max);
	}
	// Sub problem having two nodes
	else if(b-a == 1) {
		min = get_min(inputs[a], get_min(inputs[b], min));
		max = get_max(inputs[a], get_max(inputs[b], max));
	}
	// Divide the bigger problem recursively
	else{
		int mid = (a + b) / 2;
		minmax(a, mid);
		minmax(mid+1, b);
	}
}

int main(void){
	// 1. Prepare the input
	printf("How many inputs you'll provide : ");
	int num = 0;
	scanf("%d", &num);
	inputs = (int *) malloc(sizeof(int) * num);

	// 2. Get the input
	printf("Enter the elements of array,\n");
	for(int i = 0 ; i < num ; i++){
		printf("\tElement %02d : ", i+1);
		scanf("%d", &inputs[i]);
	}

	// 3. Find min and max
	max = min = inputs[0];
	minmax(0, num-1);

	// 4. Print them for user
	printf("Max : %d\n", max);
	printf("Min : %d\n", min);

	// 5. Done!
	return 0;
}



