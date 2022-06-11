/** \file neigh.h
 * \brief this file contains the declarations of function that will help us to handle the amount of neighbors of cell
 * \see neigh.c
*/


#include "table.h"

/** \brief this function is used to count the amount of neighbors of cell */
int **matrixOfNeighbors(int **table,int size,int type);
int numberOfneighbors_clipped(int **table,int row,int column,int size);
int numberOfneighbors_circular(int **table,int row,int column,int size);
int isalive(int b);