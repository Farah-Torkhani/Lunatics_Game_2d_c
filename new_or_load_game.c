#include "Headers/headers.h"

void newORloadGame(SDL_Surface *screen)
{
    //declare simple variables
    int newIndex = 0, loadIndex = 0, backIndex = 0, done = 1;
    int english;
    getlanguage(&english);

    //simple variable hover test
    int newHover = 1, loadHover = 1, backHover = 1;

    //declare the select game difficulty images
    SDL_Surface *newORloadGameBg, *new[2], *load[2], *back[2] , *newORloadGameBg_fr, *new_fr[2], *load_fr[2], *back_fr[2];

    //declare and set the postion
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;

    //declare and set music
    Mix_Music *music;
    music = Mix_LoadMUS("Assets/graphic/MainMenu/ost.mp3");

    //declare and set the hover sound effect
    Mix_Chunk *hoverSound;
    hoverSound = Mix_LoadWAV("Assets/graphic/MainMenu/click.wav");

    //set images
    newORloadGameBg = IMG_Load("Assets/graphic/newORloadGame/0.png");
    newORloadGameBg_fr = IMG_Load("Assets/graphic/newORloadGame/0.png");

    new[0] = IMG_Load("Assets/graphic/newORloadGame/newgame.png");
    new[1] = IMG_Load("Assets/graphic/newORloadGame/newgamehover.png");

    new_fr[0] = IMG_Load("Assets/graphic/newORloadGame/nouvellepartie.png");
    new_fr[1] = IMG_Load("Assets/graphic/newORloadGame/nouvellepartiehover.png");

    load[0] = IMG_Load("Assets/graphic/newORloadGame/loadgame.png");
    load[1] = IMG_Load("Assets/graphic/newORloadGame/loadgamehover.png");

    load_fr[0] = IMG_Load("Assets/graphic/newORloadGame/chargement.png");
    load_fr[1] = IMG_Load("Assets/graphic/newORloadGame/chargementhover.png");

    back[0] = IMG_Load("Assets/graphic/newORloadGame/back.png");
    back[1] = IMG_Load("Assets/graphic/newORloadGame/backhover.png");

    back_fr[0] = IMG_Load("Assets/graphic/newORloadGame/retour.png");
    back_fr[1] = IMG_Load("Assets/graphic/newORloadGame/retourhover.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        if(english == 0)
        {
        SDL_BlitSurface(newORloadGameBg, NULL, screen, &pos);
        SDL_BlitSurface(new[newIndex], NULL, screen, &pos);
        SDL_BlitSurface(load[loadIndex], NULL, screen, &pos);
        SDL_BlitSurface(back[backIndex], NULL, screen, &pos);
        }
        else if (english == 1)
        {
        SDL_BlitSurface(newORloadGameBg_fr, NULL, screen, &pos);
        SDL_BlitSurface(new_fr[newIndex], NULL, screen, &pos);
        SDL_BlitSurface(load_fr[loadIndex], NULL, screen, &pos);
        SDL_BlitSurface(back_fr[backIndex], NULL, screen, &pos);
        }
        

        SDL_Flip(screen);

        if (SDL_WaitEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = 0;
                SDL_Quit();
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 0;

                    break;
                case SDLK_UP:
                    if (newIndex == 0 && loadIndex == 0 && backIndex == 0)
                    {
                        newIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (newIndex == 1 && loadIndex == 0 && backIndex == 0)
                    {
                        newIndex = 0;
                        loadIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (newIndex == 0 && loadIndex == 1 && backIndex == 0)
                    {
                        newIndex = 1;
                        loadIndex = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (newIndex == 0 && loadIndex == 0 && backIndex == 1)
                    {
                        newIndex = 0;
                        loadIndex = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;
                    
            case SDLK_DOWN:
                    if (newIndex == 0 && loadIndex == 0 && backIndex == 0)
                    {
                        newIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (newIndex == 1 && loadIndex == 0 && backIndex == 0)
                    {
                        newIndex = 0;
                        loadIndex = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (newIndex == 0 && loadIndex == 1 && backIndex == 0)
                    {
                        newIndex = 0;
                        loadIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (newIndex == 0 && loadIndex == 0 && backIndex == 1)
                    {
                        newIndex = 1;
                        loadIndex = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;
                case SDLK_RETURN:
                    if (backIndex == 1)
                    {
                        done = 0;
                    }
                    else if (newIndex == 1)
                    {
                      
                      gameMode(screen, 1);
                    }
                    else if (loadIndex == 1)
                    {
                       stage_1(screen , 1);
                    }

                break;
                }
                break;

        case SDL_MOUSEMOTION:
                newIndex = 0;
                loadIndex = 0;
                backIndex = 0;
                if (event.motion.x > 523 && event.motion.y > 280 && event.motion.x < 735 && event.motion.y < 346)
                {
                    newIndex = 1;
                    if (newHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    newHover = 0;
                }
                else
                {
                    newHover = 1;
                }

                if (event.motion.x > 523 && event.motion.y >403 && event.motion.x < 735 && event.motion.y < 465)
                {
                    loadIndex = 1;
                    if (loadHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    loadHover = 0;
                }
                else
                {
                    loadHover = 1;
                }

                if (event.motion.x > 547 && event.motion.y > 584 && event.motion.x < 700 && event.motion.y < 640)
                {
                    backIndex = 1;
                    if (backHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    backHover = 0;
                }
                else
                {
                    backHover = 1;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (backIndex == 1)
                    {
                        done = 0;
                    }
                    else if (newIndex == 1)
                    {
                      
                      if(selectchamp(screen)==1)
                      {
                          done=0;
                          return 1;
                      }

                    }
                    else if (loadIndex == 1)
                    {
                       if(selectchamp(screen)==1)
                       {
                           done=0;
                           return 1;
                       }
                    }
                }
                break;
            }
        }
    }
//SDL_FreeSurface(newORloadGameBg);   
           
}