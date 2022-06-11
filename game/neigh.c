#include "neigh.h"

int **matrixOfNeighbors(int **table,int size,int type){
	int **neighbors = allocatedMatrix(size);

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(type==CLIPPED)neighbors[i][j] = numberOfneighbors_clipped(table,i,j,size);
			else if(type==CIRCULAR)neighbors[i][j] = numberOfneighbors_circular(table,i,j,size);

	return neighbors;
}

int numberOfneighbors_clipped(int **table,int row,int column,int size){
	int nbNeigh=0;

	if(row) if(isalive(table[row-1][column])) nbNeigh++;
	if(column) if(isalive(table[row][column-1])) nbNeigh++;
	if(row < size-1) if(isalive(table[row+1][column])) nbNeigh++;
	if(column < size-1) if(isalive(table[row][column+1])) nbNeigh++;

	if(row && column) if(isalive(table[row-1][column-1])) nbNeigh++;
	if(row && column < size-1) if(isalive(table[row-1][column+1])) nbNeigh++;
	if(row < size-1 && column) if(isalive(table[row+1][column-1])) nbNeigh++;
	if(row < size-1 && column < size-1) if(isalive(table[row+1][column+1])) nbNeigh++;

	return nbNeigh;
}

int numberOfneighbors_circular(int **table,int row,int column,int size){
	int nbNeigh=0;

	if(isalive(table[(row+size-1)%size][column])) nbNeigh++;
	if(isalive(table[row][(column+size-1)%size])) nbNeigh++;
	if(isalive(table[(row+size+1)%size][column])) nbNeigh++;
	if(isalive(table[row][(column+size+1)%size])) nbNeigh++;

	if(isalive(table[(row+size-1)%size][(column+size-1)%size])) nbNeigh++;
	if(isalive(table[(row+size-1)%size][(column+size+1)%size])) nbNeigh++;
	if(isalive(table[(row+size+1)%size][(column+size-1)%size])) nbNeigh++;
	if(isalive(table[(row+size+1)%size][(column+size+1)%size])) nbNeigh++;

	return nbNeigh;
}

int isalive(int b){
	if(b == 1)return 1;//alive
	else if(b == 0)return 0;//dead
	return -1;//wrong input
}