#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define size 5

int **allocatedMatrix(){
	int **matrix;
	matrix=(int **)malloc(size*sizeof(int *));
	for(int i=0;i<size;i++)
		matrix[i]=(int *)malloc(size*sizeof(int));
	return matrix;
}

int random0n(int n){
	return random()%n;// 0 to n not included
}

int activate(){
	return 1;
}

int kill(){
	return 0;
}

int isalive(int b){
	if(b == 1)return 1;
	return 0;
}

void showMatrix(int **array){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			if(isalive(array[i][j])) printf("\033[47m  \033[0m");
			//if(isalive(array[i][j])) printf("\033[4%dm  \033[0m",random0n(7)+1);
			else  printf("\033[40m  \033[0m");
	printf("\n");}printf("\n");
}

void showsimpleMatrix(int **array){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			printf("%d ",array[i][j] );
	printf("\n");}printf("\n\n\n");
}


int numberOfneighbors(int **array,int row,int column){
	int n=0;

	if(row) if(isalive(array[row-1][column])) n++;
	if(column) if(isalive(array[row][column-1])) n++;
	if(row < size-1) if(isalive(array[row+1][column])) n++;
	if(column < size-1) if(isalive(array[row][column+1])) n++;

	if(row && column) if(isalive(array[row-1][column-1])) n++;
	if(row && column < size-1) if(isalive(array[row-1][column+1])) n++;
	if(row < size-1 && column) if(isalive(array[row+1][column-1])) n++;
	if(row < size-1 && column < size-1) if(isalive(array[row+1][column+1])) n++;

	return n;
}

int **matrixOfNeighbors(int **array){
	int **neighbors = allocatedMatrix();

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			neighbors[i][j] = numberOfneighbors(array,i,j);

	return neighbors;
}

int **dostep(int **array){
	int **neighborMatrix=matrixOfNeighbors(array);
	int **returnArray = allocatedMatrix();

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(isalive(array[i][j]))
				if(neighborMatrix[i][j] > 3 || neighborMatrix[i][j] < 2)
					returnArray[i][j]=kill();
				else returnArray[i][j]=activate();
			else
				if(neighborMatrix[i][j] == 3)
					returnArray[i][j]=activate();
				else returnArray[i][j]=kill();

	return returnArray;
}

void writeTo(int **array,FILE *pFile){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			if(array[i][j])fprintf(pFile,"1" );
			else fprintf(pFile,"0" );
		//fprintf(pFile,"\n" );
	}//fprintf(pFile,"\n" );
}

int main(){
	srand(time(NULL)); // randomize the seed
	int **array = allocatedMatrix();

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			array[i][j]=random0n(2);

	showMatrix(array);

	FILE *pFile;

	pFile=fopen("module", "w");
	if(pFile==NULL) perror("Error opening file.");

	/*for(int i=0;i<1;i++){
		writeTo(array,pFile);
		array = dostep(array);
		showMatrix(array);
		sleep(1);
	}*/

	while(1){
		array = dostep(array);
		showMatrix(array);
		sleep(1);
		//system("clear");
	}

	fclose(pFile);

}
