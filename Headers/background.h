#ifndef background_H_INCLUDED
#define background_H_INCLUDED

#include "struct.h"



void initBg(GameplayBg *b);
void afficher_background(SDL_Surface *screen, GameplayBg *b);
void scrolling_right(GameplayBg *b, float velocity, SDL_Surface *screen, Input I , Hero *hero , enemie *e);
void scrolling_left(GameplayBg *b, float velocity, SDL_Surface *screen, Input I , Hero *h , enemie *e);

/*
typedef struct  background
{
  SDL_Surface *bg;
	    SDL_Surface *background;
      SDL_Surface *mask;
	    SDL_Rect camera;
	    int x_relative;
	    int y_relative;
      SDL_Rect pos;
}background;

void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b,perssonage *p,SDL_Surface *screen);
void scrolling_left (background *b,perssonage *p,SDL_Surface *screen);
*/


  #endif // DS_H_INCLUDED