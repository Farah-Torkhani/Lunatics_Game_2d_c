#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#include "struct.h"

#define Ground 400;

void setrects(SDL_Rect *crop);

void init_hero(Hero *h);
void afficher_Hero(Hero *h, SDL_Surface *screen, SDL_Surface *topBg, SDL_Surface *score);

void idleAnimation(Hero *h);
void runAnimation(Hero *h);
void walkAnimation(Hero *h);

void jumpAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, int run, Input I);
void attackAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, Input I);

void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt);

void jumpHeroMvt(Hero *hero, Input I, int *run);
void deadAnimation(Hero *h, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos);

void updateHeroHealth(Hero *h, char *direction);
void updateHeroScore(Hero *h, SDL_Surface **score, TTF_Font *police, SDL_Color color, char *scoreText, SDL_Surface *screen);

#endif