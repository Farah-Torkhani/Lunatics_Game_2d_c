#include "Headers/headers.h"

void GameOver(SDL_Surface *screen)
{
    //declare simple variables
    int TryAgain = 0, menu = 0, done = 1;
    int english;
    getlanguage(&english);

    //simple variable hover test
    int tryagainHover = 1, loadHover = 1;

    //declare the select game over images
    SDL_Surface *gameoverBg, *tryagain[2], *load[2], *gameoverBg_fr, *tryagain_fr[2], *load_fr[2], *back_fr[2];

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
    gameoverBg = IMG_Load("Assets/graphic/gameover/gameover.jpg");
    gameoverBg_fr = IMG_Load("Assets/graphic/gameover/gameover.jpg");

    tryagain[0] = IMG_Load("Assets/graphic/gameover/tryagain.png");
    tryagain[1] = IMG_Load("Assets/graphic/gameover/tryagainhover.png");

    tryagain_fr[0] = IMG_Load("Assets/graphic/gameover/resessayer.png");
    tryagain_fr[1] = IMG_Load("Assets/graphic/gameover/tryagainhover.png");

    load[0] = IMG_Load("Assets/graphic/gameover/menu.png");
    load[1] = IMG_Load("Assets/graphic/gameover/menuhover.png");

    load_fr[0] = IMG_Load("Assets/graphic/gameover/menu.png");
    load_fr[1] = IMG_Load("Assets/graphic/gameover/menuhover.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        if(english == 0)
        {
        SDL_BlitSurface(gameoverBg, NULL, screen, &pos);
        SDL_BlitSurface(tryagain[TryAgain], NULL, screen, &pos);
        SDL_BlitSurface(load[menu], NULL, screen, &pos);
        }
        else if (english == 1)
        {
        SDL_BlitSurface(gameoverBg_fr, NULL, screen, &pos);
        SDL_BlitSurface(tryagain_fr[TryAgain], NULL, screen, &pos);
        SDL_BlitSurface(load_fr[menu], NULL, screen, &pos);
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
                    if (TryAgain == 0 && menu == 0)
                    {
                        TryAgain = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (TryAgain == 1 && menu == 0)
                    {
                        TryAgain = 0;
                        menu = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (TryAgain == 0 && menu == 1)
                    {
                        TryAgain = 1;
                        menu = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;
                    
            case SDLK_DOWN:
                    if (TryAgain == 0 && menu == 0)
                    {
                        TryAgain = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (TryAgain == 1 && menu == 0)
                    {
                        TryAgain = 0;
                        menu = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (TryAgain == 0 && menu == 1 )
                    {
                        TryAgain = 1;
                        menu = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;

                case SDLK_RETURN:
                     if (TryAgain == 1)
                    {
                       stage_1(screen , 1);
                    }
                    else if (menu == 1)
                    {
                      mainMenu(screen, 0);
                    }

                break;
                }
                break;

        case SDL_MOUSEMOTION:
                TryAgain = 0;
                menu = 0;
                if (event.motion.x > 523 && event.motion.y > 280 && event.motion.x < 735 && event.motion.y < 346)
                {
                    TryAgain = 1;
                    if (tryagainHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    tryagainHover = 0;
                }
                else
                {
                    tryagainHover = 1;
                }

                if (event.motion.x > 523 && event.motion.y >403 && event.motion.x < 735 && event.motion.y < 465)
                {
                    menu = 1;
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

                
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                  if (TryAgain == 1)
                    {
                       stage_1(screen , 1);
                    }
                    else if (menu == 1)
                    {
                        mainMenu(screen, 0);
                    }
                }
                break;
            }
        }
    }
//SDL_FreeSurface(gameoverBg);   
            
}