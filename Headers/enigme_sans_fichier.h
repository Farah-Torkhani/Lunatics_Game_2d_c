#ifndef enigmee_H_INCLUDED
#define enigme_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

/*
typedef struct 
{
	SDL_Rect pos ;
	SDL_Surface *enigme[2] ;


}enigme;
*/




int Init_enigmee(enigmee *g );
void afficherenigmee(enigmee *e);
int genererenigmee(enigmee *e , SDL_Surface * screen);

#endif // DS_H_INCLUDED