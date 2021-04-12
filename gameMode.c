#include "Headers/headers.h"

void gameMode(SDL_Surface *screen, int *action)
{
    //declare simple variables
    int soloIndex = 0, backIndex = 0, done = 1;
    int english;
     getlanguage(&english);

    //simple variable hover test
    int soloHover = 1, backHover = 1;

    //declare the select game mode images
    SDL_Surface *gameModeBg , *gameModeBg_fr , *solo[2], *multiplayer,*multiplayer_fr , *back[2] , *retour[2];

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
    gameModeBg = IMG_Load("Assets/graphic/gameMode/modeBg.jpg");
    gameModeBg_fr = IMG_Load("Assets/graphic/gameMode/modebg_fr.jpg");

    solo[0] = IMG_Load("Assets/graphic/gameMode/solo_normal.png");
    solo[1] = IMG_Load("Assets/graphic/gameMode/solo_hover.png");

    multiplayer = IMG_Load("Assets/graphic/gameMode/multiplayerDes.png");
    multiplayer_fr = IMG_Load("Assets/graphic/gameMode/multijoueurs.png");

    back[0] = IMG_Load("Assets/graphic/gameMode/back_normal.png");
    back[1] = IMG_Load("Assets/graphic/gameMode/back_hover.png");

    retour[0] = IMG_Load("Assets/graphic/gameMode/retour_normal.png");
    retour[1] = IMG_Load("Assets/graphic/gameMode/retour_hover.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        if(english == 0)
        {
        SDL_BlitSurface(gameModeBg, NULL, screen, &pos);
        SDL_BlitSurface(solo[soloIndex], NULL, screen, &pos);
        SDL_BlitSurface(multiplayer, NULL, screen, &pos);
        SDL_BlitSurface(back[backIndex], NULL, screen, &pos);
        }
        else if(english == 1)
        {
        SDL_BlitSurface(gameModeBg_fr, NULL, screen, &pos);
        SDL_BlitSurface(solo[soloIndex], NULL, screen, &pos);
        SDL_BlitSurface(multiplayer_fr, NULL, screen, &pos);
        SDL_BlitSurface(retour[backIndex], NULL, screen, &pos);
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
                    if (soloIndex == 0 && backIndex == 0)
                    {
                        soloIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (soloIndex == 1 && backIndex == 0)
                    {
                        soloIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (soloIndex == 0 && backIndex == 1)
                    {
                        soloIndex = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;

                case SDLK_DOWN:
                    if (soloIndex == 0 && backIndex == 0)
                    {
                        soloIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (soloIndex == 1 && backIndex == 0)
                    {
                        soloIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (soloIndex == 0 && backIndex == 1)
                    {
                        soloIndex = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;
                case SDLK_RETURN:
                    if (backIndex == 1)
                    {
                        done = 0;
                    }
                    else if (soloIndex == 1)
                    {

                         if(gamedifficulty(screen)==1)
                        {
                            done=0;
                        }
                    }

                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                soloIndex = 0;
                backIndex = 0;
                if (event.motion.x > 560 && event.motion.y > 280 && event.motion.x < 722 && event.motion.y < 346)
                {
                    soloIndex = 1;
                    if (soloHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    soloHover = 0;
                }
                else
                {
                    soloHover = 1;
                }

                if (event.motion.x > 560 && event.motion.y > 520 && event.motion.x < 722 && event.motion.y < 586)
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
                    else if (soloIndex == 1)
                    {

                        if(gamedifficulty(screen)==1)
                        {
                            done=0;
                        }
                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(gameModeBg);
    SDL_FreeSurface(multiplayer);
}