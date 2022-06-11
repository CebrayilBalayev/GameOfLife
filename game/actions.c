/** \file actions.c
 * \brief This is file where we placed the functions that are used to make some actions with our cells
*/

#include "actions.h"


/** The function dostep is used to move our cells accordig to specified type of Game of Life clipped or circular
 * \param table is a pointer a matrix where the cells will be located
 * \param size the size of tabel
 * \param type this is type of game
 * 
*/ 
int **dostep(int **table,int size,int type){
	int **neighborMatrix = matrixOfNeighbors(table,size,type);
	int **returnArray = allocatedMatrix(size);

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(isalive(table[i][j]))
				if(neighborMatrix[i][j] > 3 || neighborMatrix[i][j] < 2)
					returnArray[i][j]=kill();
				else returnArray[i][j]=activate();
			else
				if(neighborMatrix[i][j] == 3)
					returnArray[i][j]=activate();
				else returnArray[i][j]=kill();

	return returnArray;
}

int activate(){
	return 1;
}

int kill(){
	return 0;
}