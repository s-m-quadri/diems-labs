#include <stdio.h>

int n, a[10][10], p[10][10];

int main(void){
	int i, j, k;
	clrscr();

	printf("\nEnter number of nodes : ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix,\n\n");
	for (i = 0 ; i < n ; i++){
		printf("\t >  ");
		for (j = 0 ; j < n ; j++){
			scanf("%d", &a[i][j]);
			if (i == j) p[i][j] = 1;
			else p[i][j] = a[i][j];
		}
	}
	for (k = 0 ; k < n ; k++){
		for (i = 0 ; i < n ; i++){
			for (j = 0 ; j < n ; j++){
				if(p[i][k] == 1 && p[k][j] == 1)
					p[i][j] = 1;
			}
		}
	}

	printf("\nThe reachability matrix is,\n\n");
	for (i = 0 ; i < n ; i++){
		printf("\t >  ");
		for (j = 0 ; j < n ; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}