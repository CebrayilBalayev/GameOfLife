#include "table.h"

int **allocatedMatrix(int size){
	int **matrix;
	matrix=(int **)malloc(size*sizeof(int *));
	for(int i=0;i<size;i++)
		matrix[i]=(int *)malloc(size*sizeof(int));
	return matrix;
}

int **randomMatrix(int **mat,int size){
	int **matrix = mat;

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			matrix[i][j]=random0n(2);
		
	return matrix;
}

int random0n(int n){
	return random()%n;
}