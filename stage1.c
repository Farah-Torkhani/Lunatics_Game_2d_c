#include "Headers/headers.h"

void stage_1(SDL_Surface *screen , int newORload)
{
    //declare simple variables
    int done = 1, run = 0, test_velocity = 10;

    SDL_Surface *score;

    enemie f;
    enigme enigme_avec_fichier;
    enigmee enigme_sans_fichier;

    //----------------------------------------------------------------------------------------------------------------------
    Hero hero;
    char direction[50];
    char scoreText[100];
    Uint32 dt, t_prev;

    //----------------------------------------------------------------------------------------------------------------------

    GameplayBg b;

    bool running = true;
    SDL_Event event;
    Input I;
    int next;
    int i = 0;
    int act = 1;
    int enigme_reponse = 0 , enigme2_reponse = 0;

    initBg(&b);
    init_hero(&hero);
    Init_enigme(&enigme_avec_fichier);
    Init_enigmee(&enigme_sans_fichier);
    inisialiser_enemie(&f);
    initialiser_input(&I);
    if(newORload == 1)
    {
        charger(&hero.heroPos.x ,&hero.heroPos.y, &f.rect.x, &f.rect.y ,&hero.hp ,&hero.score  ,&b.camera.x ,&hero.heroPos_relative.x  , &enigme_avec_fichier.poschoix.x ,&enigme_avec_fichier.poschoix.y , "Fichier/savepos.txt" , &enigme_reponse , &enigme2_reponse);
    }
    if(newORload == 2)
    {
        charger(&hero.heroPos.x ,&hero.heroPos.y, &f.rect.x, &f.rect.y ,&hero.hp ,&hero.score  ,&b.camera.x ,&hero.heroPos_relative.x  , &enigme_avec_fichier.poschoix.x ,&enigme_avec_fichier.poschoix.y , "Fichier/savepos2.txt" , &enigme_reponse , &enigme2_reponse);
    }
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
    police = police = TTF_OpenFont("Assets/fonts/DelaGothicOne-Regular.ttf", 25);
    SDL_Color white = {255, 255, 255};
    sprintf(scoreText, "Score: %d", hero.score);
    hero.scoreImg = TTF_RenderText_Blended(police, scoreText, white);

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
                    sauvegarder(hero.heroPos.x, hero.heroPos.y , f.rect.x ,f.rect.y, hero.hp , hero.score  , b.camera.x , hero.heroPos_relative.x , enigme_avec_fichier.poschoix.x,enigme_avec_fichier.poschoix.y , "Fichier/savepos2.txt" , enigme_reponse , enigme2_reponse);

                    pause(screen);
                    break;

                case SDLK_SPACE:
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

                case SDLK_x:
                    //I.jump = 0;
                    I.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 4;
                    }
                    else
                    {
                        hero.currentMode = 5;
                    }
                    break;
                case SDLK_w:
                    test_velocity = 20;
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
                   GameOver(screen);
                    break;

                case SDLK_o:
                    updateHeroScore(&hero, police, white, scoreText, screen);
                     
                    break;
                case SDLK_e:
                    I.e = 1;
                    I.test = 1;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
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
                case SDLK_x:
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

                case SDLK_w:
                    test_velocity = 10;
                    if (hero.currentMode == 2)
                    {
                        hero.currentMode = 6;
                    }
                    else if (hero.currentMode == 3)
                    {
                        hero.currentMode = 7;
                    }
                }
                break;
            }
            dt = SDL_GetTicks() - t_prev;
        }

        //run left and right
        leftAndRightHeroMvtR(&hero, I, dt);
        //run left and right

        //jump movement
        jumpHeroMvt(&hero, I, &run);
        //jump movement

        SDL_BlitSurface(b.bg, NULL, screen, &b.BgPos);
        idleAnimation(&hero);
        runAnimation(&hero);
        walkAnimation(&hero);
        jumpAnimation(&hero, screen, &b, f, run, I);
        attackAnimation(&hero, screen, &b, f, I);
        deadAnimation(&hero, screen, &b, f);

        afficher_background(screen, &b);

        afficher_Hero(&hero, screen);

        // pos ennemi
        SDL_Rect relcoord = {f.rect.x, f.rect.y};
        //
        SDL_Rect relcoord1 = {f.rect.x, f.rect.y, f.rect.h, f.rect.w};

        /*
        int collision=0;
        collision = collision_BB(heropos ,relcoord1 );
        if(collision == 1)
        {
            heropos.y+=10;
        }
        */

        update_ennemi(&f, screen, hero.heroPos, b);

        //MoveEnnemi(&f);

        scrolling_right(&b, test_velocity, screen, I, &hero, &f, &enigme_avec_fichier, &enigme_sans_fichier);
        scrolling_left(&b, test_velocity, screen, I, &hero, &f, &enigme_avec_fichier, &enigme_sans_fichier);

        afficher_enemie(&f, screen, relcoord);

        //afficher enigme 1
        if (hero.heroPos.x > 2180 - b.camera.x && hero.heroPos.x <= 2680 - b.camera.x && enigme_reponse == 0)
        {
            SDL_BlitSurface(enigme_avec_fichier.choix, NULL, screen, &enigme_avec_fichier.poschoix);
        }
        if (hero.heroPos.x > 2180 - b.camera.x && hero.heroPos.x <= 2680 - b.camera.x && I.e == 1 && enigme_reponse == 0)
        {
            enigme_reponse = 1;
            sauvegarder(hero.heroPos.x, hero.heroPos.y , f.rect.x ,f.rect.y, hero.hp , hero.score  , b.camera.x , hero.heroPos_relative.x , enigme_avec_fichier.poschoix.x,enigme_avec_fichier.poschoix.y , "Fichier/savepos.txt" , enigme_reponse , enigme2_reponse);

            afficherEnigme(&enigme_avec_fichier);
        }
        else
        {
            I.e = 0;
        }
   /*     //afficher enigme 2
        if (hero.heroPos.x > 2180 - b.camera.x && hero.heroPos.x <= 2680 - b.camera.x && enigme2_reponse == 0)
        {
            SDL_BlitSurface(enigme_sans_fichier.choiix, NULL, screen, &enigme_sans_fichier.posechoix);
        }
        if (hero.heroPos.x > 2180 - b.camera.x && hero.heroPos.x <= 2680 - b.camera.x && I.e == 1 && enigme_reponse == 0)
        {
        //    savePose2(hero.heroPos.x, hero.heroPos.y , f.rect.x ,f.rect.y, hero.hp , hero.score  , b.camera.x , hero.heroPos_relative.x , enigme_avec_fichier.poschoix.x,enigme_avec_fichier.poschoix.y );
          sauvegarder(hero.heroPos.x, hero.heroPos.y , f.rect.x ,f.rect.y, hero.hp , hero.score  , b.camera.x , hero.heroPos_relative.x , enigme_avec_fichier.poschoix.x,enigme_avec_fichier.poschoix.y , "Fichier/savepos.txt" , enigme_reponse , enigme2_reponse);

            afficherEnigmee(&enigme_sans_fichier);
        }
        else
        {
            I.e = 0;
        }
    
*/    
        SDL_Flip(screen);
        SDL_Delay(20);
    }
}
