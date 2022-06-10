#include <unistd.h>
#include "console.h"
#include "game.h"

#define size 32

int main(){
	srand(time(NULL));
	int **array = allocatedMatrix(size);
	array = randomMatrix(array,size);

	showMatrix(array,size);

	while(1){
		sleep(1);
		system("clear");
		array = dostep(array,size);
		showMatrix(array,size);
	}
}
