/** \file neigh.c
 * \brief this functions will help us to control the amount of cells in the board
*/ 
#include "neigh.h"

/** This function helps ous to create a new matrix based of the amount of neighbors of previous board
 * \param table is a pointer a matrix where the cells will be located
 * \param size the size of tabel
 * \param type this is type of game
 * \param[out] neighbors the amount of neighbors
*/

int **matrixOfNeighbors(int **table,int size,int type){
	int **neighbors = allocatedMatrix(size);

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(type==CLIPPED)neighbors[i][j] = numberOfneighbors_clipped(table,i,j,size);
			else if(type==CIRCULAR)neighbors[i][j] = numberOfneighbors_circular(table,i,j,size);

	return neighbors;
}

/** This function is used when type of game is set clipped 
 * \param renderer this is simple SDL_Renderer pointer
 * \param row is used to handle the position of cell
 * \param column is used to handle the position of cell 
 * \param size the size of SDL_rect
 * \param[out] nbNeigh the new position of cell
*/
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

/** This function is used when type of game is set circular 
 * \param renderer this is simple SDL_Renderer pointer
 * \param row is used to handle the position of cell
 * \param column is used to handle the position of cell 
 * \param size the size of SDL_rect
 * \param[out] nbNeigh the new position of cell
*/
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

/** This function is used to check the "status" of cell if it is dead of alive
 * \param b is status of cell within its structure 
 * \return 1 or \return 0
*/
int isalive(int b){
	if(b == 1)return 1;//alive
	else if(b == 0)return 0;//dead
	return -1;//wrong input
}