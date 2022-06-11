/** \file interface.c 
 * \brief This function contains all the implementations of functions created in interface.h
*/
#include "interface.h"

/** This function is used to create a matrix 
 * \param renderer this is simple SDL_Renderer pointer
 * \param matrix is two dimensional array of our table where we are creating our cells
 * \param size the size of SDL_rect
*/
void drawmatrix(SDL_Renderer* renderer,int **matrix,int size){
	int pixel_size = (SIZE-(2*MARGIN))/size;
	SDL_SetRenderDrawColor(renderer, random()%256, random()%256, random()%256, 255);
	SDL_RenderClear(renderer);
	SDL_Rect rect = {.w = pixel_size,.h = pixel_size};

	SDL_SetRenderDrawColor(renderer, 255,255,0,255);
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			if(matrix[i][j]){
				SDL_SetRenderDrawColor(renderer, 255,255,0,255);
				addcolor(renderer,rect,i,j,size);
			}
			else {
				SDL_SetRenderDrawColor(renderer, 0,0,0,255);
				addcolor(renderer,rect,i,j,size);
			}
}
/** This function is used to make our cells colorful 
 * \param renderer this is simple SDL_Renderer pointer
 * \param renct this is SDL_Rect
 * \param row is used to handle the position of cell
 * \param column is used to handle the position of cell 
 * \param size the size of SDL_rect
*/
void addcolor(SDL_Renderer* renderer,SDL_Rect rect,int row,int column,int size){
	int pixel_size = (SIZE-(2*MARGIN))/size;
	rect.x=column*pixel_size + MARGIN;
	rect.y=row*pixel_size + MARGIN;
	SDL_RenderFillRect(renderer, &rect);
}