#include <stdio.h>
#include <stdlib.h>
double** dmatrix(int nr,int nc);

void matmult(double** A,double** B,double** C,int n1,int n2,int n3){
	for (int i = 0; i < n1; i++) {
        for (int j = 0 ; j < n2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n3; k++) {
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            	// printf("%10lf  %10lf  %10lf\n",/*C[i][j]*/(A[i][k] * B[k][j]),A[i][k],B[k][j]);
            }
            // printf("--\n");
            // printf("%lf \n",C[i][j] );
        }
        // printf("\n");
    }
}


int main(int argc, char const *argv[])
{

	double** A = dmatrix(3,3);
	A[0][0] = 5;A[0][1] = 2;A[0][2] = 3;
	A[1][0] = 4;A[1][1] = 5;A[1][2] = 6;
	A[2][0] = 7;A[2][1] = 8;A[2][2] = 9;
	double** B = dmatrix(3,3);
	B[0][0] = 0.25;B[0][1] = -0.5;   B[0][2] = 0.25;
	B[1][0] = -0.5;B[1][1] = -2;     B[1][2] = 1.5;
	B[2][0] = 0.25;B[2][1] = 2.16667;B[2][2] = -1.41667;
	double** C = dmatrix(3,3);
	// printf("--------\n");
	matmult(A,B,C,3,3,3);
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			printf("%10lf",C[j][i]);
		}
		printf("\n");
	}
	return 0;
}

double** dmatrix(int nr,int nc){
	double** ptr;
	ptr = (double**)malloc(nr*sizeof(double*));
	for (int i = 0; i < nr; ++i)
	{
		ptr[i] = (double*)malloc(nc*sizeof(double));
	}
	return ptr;
}
