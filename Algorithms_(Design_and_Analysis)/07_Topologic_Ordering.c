#include <stdio.h>
#include <conio.h>

int main(void){
	int i, j, k, n, a[10][10], in[10], fg[10], count = 0;

	clrscr();
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	printf("Enter adjacency matrix,\n");
	for(i = 0 ; i < n ; i++){
		printf("\t >>> ");
		for(j = 0 ; j < n ; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i = 0 ; i < n ; i++){
		in[i] = 0;
		fg[i] = 0;
	}
	for(i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			in[i] =in[i] + a[j][i];
		}
	}

	// Topological order
	printf("Topo logical order is given by,\n\t >>> ");
	while(count < n){
		for(k = 0 ; k < n ; k++){
			if((in[k] == 0) && (fg[k] == 0)){
				printf("%d ", k+1);
				fg[k] = 1;
			}
			for(i = 0 ; i < n ; i++){
				if(a[i][k] == 1){
					in[k]--;
				}
			}
		}
		count++;
	}
	getch();

	return 0;
}