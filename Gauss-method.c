/*Gauss-Jordan method*/

#include <stdio.h>
#include <stdlib.h>


#include <math.h>
#define N 4
int main(void){
    int i,j,k,p;
    float A[N][N+1],x[N],q;
    FILE *fp;
    if( (fp=fopen("text.txt","r"))==NULL ) {
    printf("cannot open file.\n");
    exit(0);
    }
    for(i=0;i<N;i++)
        for(j=0;j<N+1;j++)
        fscanf(fp,"%f",&A[i][j]);
    fclose(fp);
    for(i=0;i<N;i++) {
        for(j=0;j<N+1;j++) printf(" %6.2f",A[i][j]);
        printf("\n");
    }

    printf("\n");
    for(k=0;k<N-1;k++) {
        for(j=k+1;j<N;j++) {
        if(fabs(A[k][k])<1.0e-6) {
            printf("A[k][k] is zero.\n");
            exit(0);
        }
        q=A[j][k]/A[k][k];
        for(p=k;p<N+1;p++) A[j][p]-=q*A[k][p];
        }
    }
    for(i=N-1;i>=0;i--) {
        x[i]=A[i][N];
        for(j=i+1;j<N;j++) x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
    for(i=0;i<N;i++) {
        for(j=0;j<N+1;j++) printf(" %6.2f",A[i][j]);
        printf("\t%6.2f\n",x[i]);
    }
}

/*
   1.00   1.00   2.00   1.00   1.00
   2.00   1.00   2.00   3.00   1.00
   1.00   4.50   0.00   0.00   0.00
   0.00   0.00   0.00   0.00   0.00

   1.00   1.00   2.00   1.00   1.00      -0.00
   0.00  -1.00  -2.00   1.00  -1.00       0.00
   0.00   0.00  -9.00   2.50  -4.50       0.50
   0.00   0.00   0.00   0.00   0.00       0.00
*/