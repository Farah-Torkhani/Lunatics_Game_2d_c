#ifndef option_H_INCLUDED
#define option_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void settingsMenu(SDL_Surface *screen);
void saveVolume(int music);
void controllersScreen(SDL_Surface *screen);

#endif