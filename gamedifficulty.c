#include "Headers/headers.h"
#include "Headers/gamedifficulty.h"







void gamedifficulty(SDL_Surface *screen)
{
    //declare simple variables
    int normalIndex = 0, hardIndex = 0, backIndex = 0, done = 1;

    //simple variable hover test
    int normalHover = 1, hardHover = 1, backHover = 1;

    //declare the select game difficulty images
    SDL_Surface *gameDifficultyBg, *normal[2], *hard[2], *back[2];

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
    gameDifficultyBg = IMG_Load("Assets/graphic/gameDifficulty/selectgamediffBg.png");

    normal[0] = IMG_Load("Assets/graphic/gameDifficulty/normal.png");
    normal[1] = IMG_Load("Assets/graphic/gameDifficulty/normalhover.png");

    hard[0] = IMG_Load("Assets/graphic/gameDifficulty/hard.png");
    hard[1] = IMG_Load("Assets/graphic/gameDifficulty/hardhover.png");

    back[0] = IMG_Load("Assets/graphic/gameDifficulty/back.png");
    back[1] = IMG_Load("Assets/graphic/gameDifficulty/backhover.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        SDL_BlitSurface(gameDifficultyBg, NULL, screen, &pos);
        SDL_BlitSurface(normal[normalIndex], NULL, screen, &pos);
        SDL_BlitSurface(hard[hardIndex], NULL, screen, &pos);
        SDL_BlitSurface(back[backIndex], NULL, screen, &pos);

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
                    if (normalIndex == 0 && hardIndex == 0 && backIndex == 0)
                    {
                        normalIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (normalIndex == 1 && hardIndex == 0 && backIndex == 0)
                    {
                        normalIndex = 0;
                        hardIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (normalIndex == 0 && hardIndex == 1 && backIndex == 0)
                    {
                        normalIndex = 1;
                        hardIndex = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (normalIndex == 0 && hardIndex == 0 && backIndex == 1)
                    {
                        normalIndex = 0;
                        hardIndex = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;
                    
            case SDLK_DOWN:
                    if (normalIndex == 0 && hardIndex == 0 && backIndex == 0)
                    {
                        normalIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (normalIndex == 1 && hardIndex == 0 && backIndex == 0)
                    {
                        normalIndex = 0;
                        hardIndex = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (normalIndex == 0 && hardIndex == 1 && backIndex == 0)
                    {
                        normalIndex = 0;
                        hardIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (normalIndex == 0 && hardIndex == 0 && backIndex == 1)
                    {
                        normalIndex = 1;
                        hardIndex = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;
                case SDLK_RETURN:
                    if (backIndex == 1)
                    {
                        done = 0;
                    }
                    else if (normalIndex == 1)
                    {
                      
                      selectchamp(screen);

                    }
                    else if (hardIndex == 1)
                    {
                       selectchamp(screen);
                    }

                break;
                }
                break;

        case SDL_MOUSEMOTION:
                normalIndex = 0;
                hardIndex = 0;
                backIndex = 0;
                if (event.motion.x > 523 && event.motion.y > 280 && event.motion.x < 735 && event.motion.y < 346)
                {
                    normalIndex = 1;
                    if (normalHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    normalHover = 0;
                }
                else
                {
                    normalHover = 1;
                }

                if (event.motion.x > 523 && event.motion.y >403 && event.motion.x < 735 && event.motion.y < 465)
                {
                    hardIndex = 1;
                    if (hardHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    hardHover = 0;
                }
                else
                {
                    hardHover = 1;
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
                    else if (normalIndex == 1)
                    {
                      
                      selectchamp(screen);

                    }
                    else if (hardIndex == 1)
                    {
                       selectchamp(screen);
                    }
                }
                break;
            }
        }
    }
SDL_FreeSurface(gameDifficultyBg);                
}