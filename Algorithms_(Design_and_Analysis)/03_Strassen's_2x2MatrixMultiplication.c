#include <stdio.h>

int main(void){
	// 1. Taking first and second matrix as input
	int A[2][2];
	printf("\nEnter the 4 elements of first matrix,\n\n\t >>> ");
	for(int i = 0 ; i < 2 ; i++)
		for (int j = 0 ; j < 2 ; j++)
			scanf("%d", &A[i][j]);
	int B[2][2];
	printf("\nEnter the 4 elements of second matrix,\n\n\t >>> ");
	for(int i = 0 ; i < 2 ; i++)
		for (int j = 0 ; j < 2 ; j++)
			scanf("%d", &B[i][j]);

	// 2. Strassen's Formulae and Calculations
	int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
	int m2 = (A[1][0] + A[1][1]) * B[0][0];
	int m3 = A[0][0] * (B[0][1] - B[1][1]);
	int m4 = A[1][1] * (B[1][0] - B[0][0]);
	int m5 = (A[0][0] + A[0][1]) * B[1][1];
	int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
	int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
	int C[2][2];
	C[0][0] = m1 + m4 - m5 + m7;
	C[0][1] = m3 + m5;
	C[1][0] = m2 + m4;
	C[1][1] = m1 + m3 - m2 + m6;

	// 3. Printing Formatted Result
	printf("\nSolution is give by,\n\n");
	for(int i = 0 ; i < 2 ; i++){
		printf("\t");

		for (int j = 0 ; j < 2 ; j++)
			printf("%3d ", A[i][j]);

		printf("        ");

		for (int j = 0 ; j < 2 ; j++)
			printf("%3d ", B[i][j]);

		printf("       ");

		for (int j = 0 ; j < 2 ; j++)
			printf("%3d ", C[i][j]);

		if(i==0) printf("\n\t            x              =\n");
	}
	printf("\n");

	// Done!
	return 0;
}
