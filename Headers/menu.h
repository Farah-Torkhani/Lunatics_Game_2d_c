#ifndef option_H_INCLUDED
#define option_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void mainMenu(SDL_Surface *screen, int *action);
int quit(SDL_Surface *ecran);
void getVolume(int *music, int *sfx);

#endif