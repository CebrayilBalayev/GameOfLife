/** \file actions.h
* \brief this file contains functions that is used to move our cells within the matrix 
 * \see actions.c
*/

#include "neigh.h"

/** \brief is used to move a cell **/
int **dostep(int **table,int size,int type);
/** \brief function to make cell active */ 
int activate();
/** \brief function to kill a cell active */ 
int kill();