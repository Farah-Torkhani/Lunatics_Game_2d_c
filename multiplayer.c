//#include "Headers/headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "Headers/multiplayer.h"

#include "Headers/perso_multiplayer.h"
#include "Headers/background_multiplayer.h"



#include "Headers/menu.h"
#include "Headers/settings.h"
#include "Headers/gameMode.h"
#include "Headers/credits.h"
#include "Headers/selectchamp.h"
#include "Headers/gamedifficulty.h"
#include "Headers/input.h"
#include "Headers/enemy.h"
#include "Headers/struct.h"
#include "Headers/enigme_avec_fichier.h"
#include "Headers/enigme_sans_fichier.h"




void stage_1_multiplayer(SDL_Surface *screen, int newORload)
{
    int attack = 0;
    //declare simple variables
    int done = 1, run = 0, run2 = 0, test_velocity = 5, test_velocity2 = 5;

    SDL_Surface *score, *separateur;
    separateur = IMG_Load("Assets/s.jpg");
    SDL_Rect separateurPos;
    separateurPos.x = 0;
    separateurPos.y = 0;

    enemie f;
    enigme enigme_avec_fichier;
    enigmee enigme_sans_fichier;

    //----------------------------------------------------------------------------------------------------------------------
    Hero hero;
    char direction[50];
    char scoreText[100];
    Uint32 dt, t_prev;

    //hero 2----------------------------------------------------------------------------------------------------------------------
    Hero hero2;
    Input I2;
    init_hero(&hero2);
    hero2.heroPos.x = 650;
    initialiser_input(&I2);
    char direction2[50];
    char scoreText2[100];

    hero2.hpBarPos.x = 650;
    hero2.hpBarPos.y = 0;

    hero2.scoreImgPos.x = 700;
    hero2.scoreImgPos.y = 100;

    //--------------------------------------------------------------------------
    GameplayBg b;

    bool running = true;
    SDL_Event event;
    Input I;
    int next;
    int i = 0;
    int act = 1;
    int enigme_reponse = 0, enigme2_reponse = 0;

    initBg(&b);
    init_hero(&hero);
    Init_enigme(&enigme_avec_fichier);
    Init_enigmee(&enigme_sans_fichier);
    inisialiser_enemie(&f);
    initialiser_input(&I);

    hero.scoreImgPos.x = 50;
    hero.scoreImgPos.y = 100;

  /*  if (newORload == 1)
    {
        charger(&hero.heroPos.x, &hero.heroPos.y, &f.rect.x, &f.rect.y, &hero.hp, &hero.score, &b.camera.x, &hero.heroPos_relative.x, &enigme_avec_fichier.poschoix.x, &enigme_avec_fichier.poschoix.y, "Fichier/savepos.txt", &enigme_reponse, &enigme2_reponse, &enigme_sans_fichier.posechoix.x, &enigme_sans_fichier.posechoix.y);
    }
    if (newORload == 2)
    {
        charger(&hero.heroPos.x, &hero.heroPos.y, &f.rect.x, &f.rect.y, &hero.hp, &hero.score, &b.camera.x, &hero.heroPos_relative.x, &enigme_avec_fichier.poschoix.x, &enigme_avec_fichier.poschoix.y, "Fichier/savepos2.txt", &enigme_reponse, &enigme2_reponse, &enigme_sans_fichier.posechoix.x, &enigme_sans_fichier.posechoix.y);
    }*/
    /*
//-----------------------------------------
    if(enigme2_reponse == 0)
    {
        SDL_BlitSurface(e->enigme[i],NULL,screen,&e->pos);
    }
//--------------------------------------------
  */

    TTF_Init();
    TTF_Font *police;
    police = TTF_OpenFont("Assets/fonts/DelaGothicOne-Regular.ttf", 25);
    SDL_Color white = {255, 255, 255};
    sprintf(scoreText, "Score: %d", hero.score);
    hero.scoreImg = TTF_RenderText_Blended(police, scoreText, white);
    hero2.scoreImg = TTF_RenderText_Blended(police, scoreText, white);
    SDL_EnableKeyRepeat(200, 0);
    while (done)
    {
        t_prev = SDL_GetTicks();

        if (hero.currentMode == 0 || hero.currentMode == 2 || hero.currentMode == 4 || hero.currentMode == 6)
        {
            strcpy(direction, "right");
        }
        else
        {
            strcpy(direction, "left");
        }

        if (hero2.currentMode == 0 || hero2.currentMode == 2 || hero2.currentMode == 4 || hero2.currentMode == 6)
        {
            strcpy(direction2, "right");
        }
        else
        {
            strcpy(direction2, "left");
        }

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                SDL_Quit();
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {

                case SDLK_ESCAPE:
                    //done = 0;
                    sauvegarder(hero.heroPos.x, hero.heroPos.y, f.rect.x, f.rect.y, hero.hp, hero.score, b.camera.x, hero.heroPos_relative.x, enigme_avec_fichier.poschoix.x, enigme_avec_fichier.poschoix.y, "Fichier/savepos2.txt", enigme_reponse, enigme2_reponse, enigme_sans_fichier.posechoix.x, enigme_sans_fichier.posechoix.y);

                    pause(screen);
                    break;

                case SDLK_KP0:
                    I.jump = 1;

                    break;

                case SDLK_RIGHT:
                    I.right = 1;
                    //hero.currentMode = 2;
                    hero.currentMode = 6;
                    break;

                case SDLK_LEFT:
                    I.left = 1;
                    hero.currentMode = 7;
                    //hero.currentMode = 3;
                    break;

                case SDLK_KP2:
                    I.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 4;
                    }
                    else
                    {
                        hero.currentMode = 5;
                    }
                    attack = 1;

                    break;

                case SDLK_KP1:
                    test_velocity = 10;
                    if (hero.currentMode == 6)
                    {
                        hero.currentMode = 2;
                    }
                    else if (hero.currentMode == 7)
                    {
                        hero.currentMode = 3;
                    }
                    break;

                case SDLK_p:

                    updateHeroHealth(&hero, direction);

                    if (hero.hp <= 0)
                    {
                        SDL_Delay(2000);
                        GameOver(screen);
                    }

                    break;
                case SDLK_l:
                    hero.heroPos.x += 150;
                    break;
                case SDLK_k:
                    hero.heroPos.x -= 150;
                    break;
                case SDLK_g:
                    GameWin(screen);
                    break;

                case SDLK_o:
                    updateHeroScore(&hero, police, white, scoreText, screen);

                    break;
                case SDLK_e:
                    I.e = 1;
                    I.test = 1;
                    break;

                //hero two--------------------------
                case SDLK_SPACE:
                    I2.jump = 1;
                    break;

                case SDLK_d:
                    I2.right = 1;
                    I.right2 = 1;
                    //hero2.currentMode = 2;
                    hero2.currentMode = 6;
                    break;

                case SDLK_q:
                    I2.left = 1;
                    I.left2 = 1;
                    hero2.currentMode = 7;
                    //hero2.currentMode = 3;
                    break;

                case SDLK_z:
                    I2.attack = 1;
                    if (strcmp(direction2, "right") == 0)
                    {
                        hero2.currentMode = 4;
                    }
                    else
                    {
                        hero2.currentMode = 5;
                    }
                    break;

                case SDLK_v:
                    test_velocity2 = 10;
                    if (hero2.currentMode == 6)
                    {
                        hero2.currentMode = 2;
                    }
                    else if (hero2.currentMode == 7)
                    {
                        hero2.currentMode = 3;
                    }
                    break;

                case SDLK_i:
                    updateHeroHealth(&hero2, direction2);
                    break;

                case SDLK_u:
                    updateHeroScore(&hero2, police, white, scoreText2, screen);
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_KP0:
                    I.jump = 0;
                    if (I.right == 1)
                    {
                        hero.currentMode = 6;
                    }
                    else if (I.left == 1)
                    {
                        hero.currentMode = 7;
                    }
                    else
                    {
                        if (strcmp(direction, "right") == 0)
                        {
                            hero.currentMode = 0;
                        }
                        else
                        {
                            hero.currentMode = 1;
                        }
                    }

                    break;

                case SDLK_RIGHT:
                    I.right = 0;
                    hero.currentMode = 0;
                    run = 0;
                    break;

                case SDLK_LEFT:
                    I.left = 0;
                    hero.currentMode = 1;
                    run = 0;
                    break;

                case SDLK_KP2:
                    I.attack = 0;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 0;
                    }
                    else
                    {
                        hero.currentMode = 1;
                    }
                    break;

                case SDLK_KP1:
                    test_velocity = 5;
                    if (hero.currentMode == 2)
                    {
                        hero.currentMode = 6;
                    }
                    else if (hero.currentMode == 3)
                    {
                        hero.currentMode = 7;
                    }
                    break;

                case SDLK_SPACE:
                    I2.jump = 0;
                    if (I2.right == 1)
                    {
                        hero2.currentMode = 6;
                    }
                    else if (I2.left == 1)
                    {
                        hero2.currentMode = 7;
                    }
                    else
                    {
                        if (strcmp(direction2, "right") == 0)
                        {
                            hero2.currentMode = 0;
                        }
                        else
                        {
                            hero2.currentMode = 1;
                        }
                    }
                    break;
                case SDLK_d:
                    I2.right = 0;
                    I.right2 = 0;
                    hero2.currentMode = 0;
                    run2 = 0;
                    break;

                case SDLK_q:
                    I2.left = 0;
                    I.left2 = 0;
                    hero2.currentMode = 1;
                    run2 = 0;
                    break;
                case SDLK_z:
                    I2.attack = 0;
                    if (strcmp(direction2, "right") == 0)
                    {
                        hero2.currentMode = 0;
                    }
                    else
                    {
                        hero2.currentMode = 1;
                    }
                    break;

                case SDLK_v:
                    test_velocity2 = 5;
                    if (hero2.currentMode == 2)
                    {
                        hero2.currentMode = 6;
                    }
                    else if (hero2.currentMode == 3)
                    {
                        hero2.currentMode = 7;
                    }
                }
                break;
            }

            dt = SDL_GetTicks() - t_prev;
        }
        SDL_BlitSurface(separateur, NULL, screen, &separateurPos);
        //run left and right
        leftAndRightHeroMvtR(&hero, I, dt);
        //run left and right

        //jump movement
        jumpHeroMvt(&hero, I, &run);
        //jump movement

        //SDL_BlitSurface(b.bg, NULL, screen, &b.BgPos);
        idleAnimation(&hero);
        runAnimation(&hero);
        walkAnimation(&hero);
        jumpAnimation(&hero, &hero2, screen, &b, f, run, I);
        attackAnimation(&hero, &hero2, screen, &b, f, I);
        deadAnimation(&hero, &hero2, screen, &b, f);

        afficher_background(screen, &b);

        afficher_Hero(&hero, screen);

        //hero 2 functions----------------------------------
        //run left and right
        leftAndRightHeroMvtR(&hero2, I2, dt);
        //run left and right

        //jump movement
        jumpHeroMvt(&hero2, I2, &run);
        //jump movement

        //SDL_BlitSurface(b.bg, NULL, screen, &b.BgPos);
        idleAnimation(&hero2);
        runAnimation(&hero2);
        walkAnimation(&hero2);
        jumpAnimation(&hero2, &hero, screen, &b, f, run2, I2);
        attackAnimation(&hero2, &hero, screen, &b, f, I2);
        deadAnimation(&hero2, &hero, screen, &b, f);

        //afficher_background(screen, &b);

        afficher_Hero(&hero2, screen);

        // pos ennemi
        SDL_Rect relcoord = {f.rect.x, f.rect.y};
        //
        SDL_Rect relcoord1 = {f.rect.x, f.rect.y, f.rect.h, f.rect.w};
        /*
         if(hero.hp<=0)
        {
            SDL_Delay(2000);  
            GameOver(screen);
        }  

        int collision=0;
        collision = collision_BB(hero.heroPos ,relcoord1 );
        if(collision == 1)
        {
         	
         //  hero.heroPos.x-=150; 
            updateHeroHealth(&hero, direction);
           
           }
  */

        //MoveEnnemi(&f);

        scrolling_right(&b, test_velocity, test_velocity2, screen, I, &hero, &f, &enigme_avec_fichier, &enigme_sans_fichier);
        scrolling_left(&b, test_velocity, test_velocity2, screen, I, &hero, &f, &enigme_avec_fichier, &enigme_sans_fichier);

        scrolling_right(&b, test_velocity, test_velocity2, screen, I, &hero2, &f, &enigme_avec_fichier, &enigme_sans_fichier);
        scrolling_left(&b, test_velocity, test_velocity2, screen, I, &hero2, &f, &enigme_avec_fichier, &enigme_sans_fichier);

        if (attack == 0)
        {
            afficher_enemie(&f, screen, relcoord);
            update_ennemi(&f, screen, hero.heroPos, b, &hero);
        }

        //afficher enigme 1
        if (hero.heroPos.x > 2180 - b.camera.x && hero.heroPos.x <= 2680 - b.camera.x && enigme_reponse == 0)
        {
            SDL_BlitSurface(enigme_avec_fichier.choix, NULL, screen, &enigme_avec_fichier.poschoix);
        }
        if (hero.heroPos.x > 2180 - b.camera.x && hero.heroPos.x <= 2680 - b.camera.x && I.e == 1 && enigme_reponse == 0)
        {
            // enigme_reponse = 1;
            sauvegarder(hero.heroPos.x, hero.heroPos.y, f.rect.x, f.rect.y, hero.hp, hero.score, b.camera.x, hero.heroPos_relative.x, enigme_avec_fichier.poschoix.x, enigme_avec_fichier.poschoix.y, "Fichier/savepos.txt", enigme_reponse, enigme2_reponse, enigme_sans_fichier.posechoix.x, enigme_sans_fichier.posechoix.y);

            afficherEnigme(&enigme_avec_fichier);
        }
        else
        {
            I.e = 0;
        }
        //afficher enigme 2
        if (hero.heroPos.x > 5200 - b.camera.x && hero.heroPos.x <= 5500 - b.camera.x && enigme2_reponse == 0)
        {
            SDL_BlitSurface(enigme_sans_fichier.choiix, NULL, screen, &enigme_sans_fichier.posechoix);
        }
        if (hero.heroPos.x > 5200 - b.camera.x && hero.heroPos.x <= 5500 - b.camera.x && I.test == 1 && enigme2_reponse == 0)
        {
            enigme2_reponse = 1;
            sauvegarder(hero.heroPos.x, hero.heroPos.y, f.rect.x, f.rect.y, hero.hp, hero.score, b.camera.x, hero.heroPos_relative.x, enigme_avec_fichier.poschoix.x, enigme_avec_fichier.poschoix.y, "Fichier/savepos.txt", enigme_reponse, enigme2_reponse, enigme_sans_fichier.posechoix.x, enigme_sans_fichier.posechoix.y);

            afficherEnigmee(&enigme_sans_fichier);
        }
        else
        {
            I.test = 0;
        }

        SDL_Flip(screen);
        SDL_Delay(20);
    }
}
