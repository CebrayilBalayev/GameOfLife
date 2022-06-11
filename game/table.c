/** \file table.c
 * \brief this function the implementations of functions created in table.h
*/ 
#include "table.h"

/** This function is used to create a matrix 
 * \param size the size of Board
 * \return matrix of allocated size
*/
int **allocatedMatrix(int size){
	int **matrix;
	matrix=(int **)malloc(size*sizeof(int *));
	for(int i=0;i<size;i++)
		matrix[i]=(int *)malloc(size*sizeof(int));
	return matrix;
}
/** This function is used to randomize a created matrix 
 * \param size the size of Board
 * \param mat this is created matrix
 * \return matrix of with randomized place of cells
*/
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