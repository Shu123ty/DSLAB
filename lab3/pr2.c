/* Q) WAP to perform operations on a square matrix::
a> Number of non-zero enteries.
b> Display upper-triangular Matirx.
c> Print diagonal.
d> Perform Transpose.*/

#include<stdio.h>
#include<stdlib.h>

void countzero(int **mat, int n){
    int i,j,c=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]!=0){
				c++;
			}
		}
	}
	printf("non zero count = %d\n",c);
}

void upper(int **mat, int n){
    int i,j;
	printf("upper triangular matrix is\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<=j)
				printf("%d ",mat[i][j]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

void diagonal(int **mat, int n){
    int i,j;
	printf("diagonal matrix is\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				printf("%d ",mat[i][j]);
            }
			else{
				printf("0 ");
            }
		}
		printf("\n");
	}
}
void trans(int **mat, int n){
    int i,j;
	printf("transpose matrix is\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[j][i]);
		}
		printf("\n");
	}
}

int main(){
	int n,i,j,ch;
	int **mat;

	printf("enter size of matrix n = ");
	scanf("%d",&n);

	mat=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		mat[i]=(int*)malloc(n*sizeof(int));
	}

	printf("enter %d elements\n",n*n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}

	while(1){
		printf("1.count non zero\n");
		printf("2.upper triangular\n");
		printf("3.diagonal matrix\n");
		printf("4.transpose\n");
		printf("enter ur choice = ");
		scanf("%d",&ch);

		switch(ch){
		case 1:
			countzero(mat,n);
			break;

		case 2:
			upper(mat,n);
			break;

		case 3:
			diagonal(mat,n);
			break;

		case 4:
			trans(mat,n);
			break;
		default:
			printf("wrong choice re-enter\n");
		}
	}

    
	for(i=0;i<n;i++){
		free(mat[i]);
	}
	free(mat);

	return 0;
}