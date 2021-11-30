/*Gauss-Jordan method*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4
int main(void){
    int i,j,k,p;
    float A[N][N+1],x[N],q;
    FILE *fp;
    if( (fp=fopen("20191105-1.dat","r"))==NULL ) {
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
/* forward elimination */
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
    /* backward substitution */
    for(i=N-1;i>=0;i--) {
        x[i]=A[i][N];
        for(j=i+1;j<N;j++) x[i]-=A[i][j]*x[j];
        x[i]/=A[i][i];
    }
/* output result */
    for(i=0;i<N;i++) {
        for(j=0;j<N+1;j++) printf(" %6.2f",A[i][j]);
        printf("\t%6.2f\n",x[i]);
    }
}