#include "Headers/headers.h"

void GameWin(SDL_Surface *screen)
{
    //declare simple variables
    int next_index = 0, menu_index = 0, done = 1;
    int english;
    getlanguage(&english);

    //simple variable hover test
    int nextHover = 1, menuhover = 1;

    //declare the select game over images
    SDL_Surface *gamewinBg, *next[2], *menu[2], *gamewinBg_fr, *next_fr[2], *menu_fr[2];

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
    gamewinBg = IMG_Load("Assets/graphic/gamewin/gamewinbg.png");
    gamewinBg_fr = IMG_Load("Assets/graphic/gamewin/gamewinbgfr.png");

    next[0] = IMG_Load("Assets/graphic/gamewin/nextlevel.png");
    next[1] = IMG_Load("Assets/graphic/gamewin/nextlevelhover.png");

    next_fr[0] = IMG_Load("Assets/graphic/gamewin/continuer.png");
    next_fr[1] = IMG_Load("Assets/graphic/gamewin/reessayerhover.png");

    menu[0] = IMG_Load("Assets/graphic/gamewin/menu.png");
    menu[1] = IMG_Load("Assets/graphic/gamewin/menuhover.png");

    menu_fr[0] = IMG_Load("Assets/graphic/gameover/menufr.png");
    menu_fr[1] = IMG_Load("Assets/graphic/gameover/menuhoverfr.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        if(english == 0)
        {
        SDL_BlitSurface(gamewinBg, NULL, screen, &pos);
        SDL_BlitSurface(next[next_index], NULL, screen, &pos);
        SDL_BlitSurface(menu[menu_index], NULL, screen, &pos);
        }
        else if (english == 1)
        {
        SDL_BlitSurface(gamewinBg_fr, NULL, screen, &pos);
        SDL_BlitSurface(next_fr[next_index], NULL, screen, &pos);
        SDL_BlitSurface(menu_fr[menu_index], NULL, screen, &pos);
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
                    if (next_index == 0 && menu_index == 0)
                    {
                        next_index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (next_index == 1 && menu_index == 0)
                    {
                        next_index = 0;
                        menu_index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (next_index == 0 && menu_index == 1)
                    {
                        next_index = 1;
                        menu_index = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;
                    
            case SDLK_DOWN:
                    if (next_index == 0 && menu_index == 0)
                    {
                        next_index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (next_index == 1 && menu_index == 0)
                    {
                        next_index = 0;
                        menu_index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (next_index == 0 && menu_index == 1 )
                    {
                        next_index = 1;
                        menu_index = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;

                case SDLK_RETURN:
                     if (next_index == 1)
                    {
                       stage_1(screen , 1);
                    }
                    else if (menu_index == 1)
                    {
                      mainMenu(screen, 0);
                    }

                break;
                }
                break;

        case SDL_MOUSEMOTION:
                next_index = 0;
                menu_index = 0;
                if (event.motion.x > 523 && event.motion.y > 280 && event.motion.x < 735 && event.motion.y < 346)
                {
                    next_index = 1;
                    if (nextHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    nextHover = 0;
                }
                else
                {
                    nextHover = 1;
                }

                if (event.motion.x > 523 && event.motion.y >403 && event.motion.x < 735 && event.motion.y < 465)
                {
                    menu_index = 1;
                    if (menuhover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    menuhover = 0;
                }
                else
                {
                    menuhover = 1;
                }

                
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                  if (next_index == 1)
                    {
                       stage_1(screen , 1);
                    }
                    else if (menu_index == 1)
                    {
                        mainMenu(screen, 0);
                    }
                }
                break;
            }
        }
    }
//SDL_FreeSurface(gamewinBg);   
            
}