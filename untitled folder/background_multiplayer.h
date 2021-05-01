#ifndef background_H_INCLUDED
#define background_H_INCLUDED

#include "struct.h"

void initBg(GameplayBg *b);
void afficher_background(SDL_Surface *screen, GameplayBg *b);
void scrolling_right(GameplayBg *b, float velocity, float velocity2, SDL_Surface *screen, Input I, Hero *hero, enemie *e, enigme *enigme1, enigmee *enigme2);
void scrolling_left(GameplayBg *b, float velocity, float velocity2, SDL_Surface *screen, Input I, Hero *h, enemie *e, enigme *enigme1, enigmee *enigme2);

#endif // DS_H_INCLUDED