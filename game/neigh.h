#include "table.h"

int **matrixOfNeighbors(int **table,int size,int type);
int numberOfneighbors_clipped(int **table,int row,int column,int size);
int numberOfneighbors_circular(int **table,int row,int column,int size);
int isalive(int b);