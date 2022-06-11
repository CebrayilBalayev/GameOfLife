/** \file interface.h
 * \brief The header file with the declaration of functions that will be used sdl interface 
 * \see inteface.c
*/


#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <unistd.h>

// (SIZE/size) must be integer not double 
/** \brief SIZE is used to define the size in pixels of Window */
#define SIZE 1040 //1024 + 2*margin => margin = 8
#define MARGIN 8

void addcolor(SDL_Renderer* renderer,SDL_Rect rect,int row,int column,int size);
void drawmatrix(SDL_Renderer* renderer,int **matrix,int size);