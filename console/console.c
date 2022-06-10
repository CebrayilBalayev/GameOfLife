#include "console.h"

void showMatrix(int **array,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			if(isalive(array[i][j])) printf("\033[43m  \033[0m");
			else  printf("\033[40m  \033[0m");
	printf("\n");}printf("\n");
}