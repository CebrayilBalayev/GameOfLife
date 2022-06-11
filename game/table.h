#include <stdlib.h>
#include <time.h>

enum types{CLIPPED,CIRCULAR};

int **allocatedMatrix(int size);
int **randomMatrix(int **mat,int size);
int random0n(int n);