/** \file table.h 
 * \brief header file with function to manipulate a board
 * \see table.c
*/
#include <stdlib.h>
#include <time.h>

/** \brief enum is used to store a type of game */ 
enum types{CLIPPED,CIRCULAR};

/** \brief this function creates the matrix */
int **allocatedMatrix(int size);
/** \brief this function randomize a created mutrix */
int **randomMatrix(int **mat,int size);
int random0n(int n);