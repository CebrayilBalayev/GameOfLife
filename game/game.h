#include <time.h>
#include <stdlib.h>

int **dostep(int **array,int size);
int **allocatedMatrix(int size);
int random0n(int n);
int **randomMatrix(int **mat,int size);
int activate();
int kill();
int isalive(int b);
int numberOfNeighborsClipped(int **array,int row,int column,int size);
int numberOfNeighborsCircular(int **array,int row,int column,int size);
int **matrixOfNeighbors(int **array,int size);
