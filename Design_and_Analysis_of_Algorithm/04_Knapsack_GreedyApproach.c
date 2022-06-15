#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int oid;
	int max_pt;
	int max_wt;
	float ratio;
	// float ratio -
	//     will be only for sort-key
	//     for greedy approch, taking,
	//     "profit per unit weight"
	//     into consideration
} object;

typedef struct{
    int max_cap;
    int rem_cap;
    float *quantity;
    // float quantity -
    //     will point to the float number array
    //     which will store the ratio of object taken
    float profit;
} knapspace;

int main(void){
	printf("\n----------------------\n");
	printf("Please Enter Details\n");
	printf("----------------------\n");
	// 1. Get the Objects and knapspace as input
	int n_obj = 0;
	printf("Enter the number of objects : ");
	scanf("%d", &n_obj);
	knapspace bag;
	object obj[n_obj];
	for(int i = 0 ; i < n_obj ; i++){
		printf("For object number %2d , enter ", i+1);
		obj[i].oid = i+1;
		printf("Profit and Weight : ");
		scanf("%d %d", &obj[i].max_pt, &obj[i].max_wt);
		obj[i].ratio = (float) obj[i].max_pt / obj[i].max_wt;
	}
	printf("Finally! Enter the knapspace capacity : ");
	scanf("%d", &bag.max_cap);

	// 2. Sort the objects
	for(int i = 0 ; i < n_obj - 1 ; i++){
		for(int j = i+1 ; j < n_obj ; j++){
			if (obj[i].ratio < obj[j].ratio){
				object temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
			}
		}
	}


	// 3. Calculate optimal solution using greedy approch
	bag.rem_cap = bag.max_cap;
	bag.quantity = (float*) malloc(n_obj * sizeof(float));
	for(int i = 0 ; i < n_obj ; i++){
		if (bag.rem_cap == 0) bag.quantity[i] = 0.0;
		else if (bag.rem_cap >= obj[i].max_wt){
			bag.quantity[i]  = 1.0;
			bag.rem_cap -= obj[i].max_wt;
		}
		// hint: remaining capacity is less than upcomming
		else{
			bag.quantity[i] = (float) bag.rem_cap / obj[i].max_wt;
			bag.rem_cap -= bag.quantity[i]  * obj[i].max_wt;
		}
	}

	// 4. Print the logs and result
	printf("\n\n----------------------\n");
	printf("Input Objects Confirmation.\n");
	printf("----------------------\n");
	for(int i = 0 ; i < n_obj ; i++){
		printf("Object no.(%d) with id: %2d and weight %2d kilograms, costs Rs. %2d/- only\n"
		        , i + 1
		        , obj[i].oid
		        , obj[i].max_wt
		        , obj[i].max_pt
		        );
	}
	printf("\n\n----------------------\n");
	printf("Feeding w.r.t. algorithm.\n");
	printf("----------------------\n");
	bag.profit = 0;
	for(int i = 0 ; i < n_obj ; i++){
		bag.profit += bag.quantity[i]  * obj[i].max_pt;
		printf("In bag, quantity of object no. %2d, is %2.1f kilograms only.\n", 
		        i+1 , bag.quantity[i] * obj[i].max_wt
		);
	}
	printf("\n\n-------------------------------------------------------------------------\n");
	printf("Thus we can have max profit of Rs. %3.2f/- only.\n", bag.profit);
	printf("... and with %3d kilograms remaining capacity of bag. \n", bag.rem_cap);
	printf("-------------------------------------------------------------------------\n\n\n");

	// Done!
	free(bag.quantity);
	return 0;
}
