#include "game.h"

int **dostep(int **array,int size){
	int **neighborMatrix=matrixOfNeighbors(array,size);
	int **returnArray = allocatedMatrix(size);

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(isalive(array[i][j]))
				if(neighborMatrix[i][j] > 3 || neighborMatrix[i][j] < 2)
					returnArray[i][j]=kill();
				else returnArray[i][j]=activate();
			else
				if(neighborMatrix[i][j] == 3)
					returnArray[i][j]=activate();
				else returnArray[i][j]=kill();

	return returnArray;
}

int **allocatedMatrix(int size){
	int **matrix;
	matrix=(int **)malloc(size*sizeof(int *));
	for(int i=0;i<size;i++)
		matrix[i]=(int *)malloc(size*sizeof(int));
	return matrix;
}

int random0n(int n){
	return random()%n;
}

int **randomMatrix(int **mat,int size){
	int **matrix = mat;

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			matrix[i][j]=random0n(2);
		
	return matrix;
}

int activate(){
	return 1;
}

int kill(){
	return 0;
}

int isalive(int b){
	if(b == 1)return 1;
	return 0;
}

int numberOfNeighborsClipped(int **array,int row,int column,int size){
	int nbNeigh=0;

	if(row) if(isalive(array[row-1][column])) nbNeigh++;
	if(column) if(isalive(array[row][column-1])) nbNeigh++;
	if(row < size-1) if(isalive(array[row+1][column])) nbNeigh++;
	if(column < size-1) if(isalive(array[row][column+1])) nbNeigh++;

	if(row && column) if(isalive(array[row-1][column-1])) nbNeigh++;
	if(row && column < size-1) if(isalive(array[row-1][column+1])) nbNeigh++;
	if(row < size-1 && column) if(isalive(array[row+1][column-1])) nbNeigh++;
	if(row < size-1 && column < size-1) if(isalive(array[row+1][column+1])) nbNeigh++;

	return nbNeigh;
}

int numberOfNeighborsCircular(int **array,int row,int column,int size){
	int nbNeigh=0;

	if(isalive(array[(row+size-1)%size][column])) nbNeigh++;
	if(isalive(array[row][(column+size-1)%size])) nbNeigh++;
	if(isalive(array[(row+size+1)%size][column])) nbNeigh++;
	if(isalive(array[row][(column+size+1)%size])) nbNeigh++;

	if(isalive(array[(row+size-1)%size][(column+size-1)%size])) nbNeigh++;
	if(isalive(array[(row+size-1)%size][(column+size+1)%size])) nbNeigh++;
	if(isalive(array[(row+size+1)%size][(column+size-1)%size])) nbNeigh++;
	if(isalive(array[(row+size+1)%size][(column+size+1)%size])) nbNeigh++;

	return nbNeigh;
}

int **matrixOfNeighbors(int **array,int size){
	int **neighbors = allocatedMatrix(size);

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			neighbors[i][j] = numberOfNeighborsCircular(array,i,j,size);//numberOfNeighborsClipped(array,i,j,size);

	return neighbors;
}
