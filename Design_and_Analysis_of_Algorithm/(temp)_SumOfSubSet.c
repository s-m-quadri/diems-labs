#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *set;
    int target_sum;
    int no_elements;
} problem;

int main(void){
    printf("Enter the no. of elements in the set : ");
    int n = 0;
    scanf("%d", &n);
    problem p1;
    p1.no_elements = n;
    p1.set = (int *) malloc(n * sizeof(int));
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &p1.set[i]);
    }
    printf("Enter the target sum out of sub sets : ");
    n = 0;
    scanf("%d", &n);
    p1.target_sum = n;

    // TODO complete implementation
    sum(p1, 0, )

    return 0;
}

void sum(problem p1, int take, int remain, int turn){
    // TODO complete implementation
    if(remain == 0) return;
    if(turn == p1.no_elements-1) return;
    if(take > target_sum) return;
    if(take == target_sum) printf(" Done\n");
    if(take < target_sum){
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &p1.set[i]);
        }
        print(" %d ", turn+1);
        sum(p1, take+p1.set[turn], take-p1.set[turn], turn++)
    }
}


