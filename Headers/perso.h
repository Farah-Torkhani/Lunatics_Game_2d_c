#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED
#define Ground 400;


#include "struct.h"


//#include "background.h"

void setrects(SDL_Rect *crop);
void init_hero(Hero *h);
void afficher_Hero(Hero *h, SDL_Surface *screen);

void idleAnimation(Hero *h);
void runAnimation(Hero *h);

void jumpAnimation(Hero *h, SDL_Surface *screen,  int run);

void attackAnimation(Hero *h, SDL_Surface *screen);
void leftAndRightHeroMvt(Hero *hero, Input I);
void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt);
void jumpHeroMvt(Hero *hero, Input I, int *run);

#endif