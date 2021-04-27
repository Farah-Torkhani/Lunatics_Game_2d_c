#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include "struct.h"


void setrects_enemie(SDL_Rect* clip);

    void inisialiser_enemie (enemie *f );
    void MoveEnnemi(enemie *E);
	void afficher_enemie (enemie *f,SDL_Surface *screen , SDL_Rect pos);
	void animation (enemie *p);
    int collision_BB(SDL_Rect pos_hero , SDL_Rect pos_e );
  void update_ennemi(enemie *e , SDL_Surface *screen , SDL_Rect pos_hero ,GameplayBg bg , Hero *hero);

#endif // DS_H_INCLUDED