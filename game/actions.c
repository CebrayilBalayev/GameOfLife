#include "actions.h"

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