#include "Headers/headers.h"

void credits(SDL_Surface *screen)
{
    //declare and set the hover sound effect
    Mix_Chunk *hoverSound;
    hoverSound = Mix_LoadWAV("Assets/graphic/MainMenu/click.wav");

    int done = 1;

    //declare and set the position variable

    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;

    //declare and set the position variable
    SDL_Rect backpos;
    backpos.x = 10;
    backpos.y = 10;

    int backindex = 0;
    int backhover = 1;

    //declare and set the exit alert images and the background
    SDL_Surface *creditsBg, *back[2];

    creditsBg = IMG_Load("Assets/graphic/credits/credits.png");

    back[0] = IMG_Load("Assets/graphic/credits/back1.png");
    back[1] = IMG_Load("Assets/graphic/credits/back2.png");

    //declare the event
    SDL_Event event;

    while (done)
    {
        //blint the background and the exit no and yes buttons
        SDL_BlitSurface(creditsBg, NULL, screen, &pos);
        SDL_BlitSurface(back[backindex], NULL, screen, &backpos);
        SDL_Flip(screen);

        SDL_WaitEvent(&event);

        switch (event.type)
        {

        case SDL_QUIT:
            return 1;

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done = 0;
                break;
            case SDLK_UP:
                if (backindex == 0)
                {
                    backindex = 1;
                    Mix_PlayChannel(1, hoverSound, 0);
                }
                else
                {
                    backindex = 0;
                    Mix_PlayChannel(1, hoverSound, 0);
                }
                break;
            case SDLK_DOWN:
                if (backindex == 0)
                {
                    backindex = 1;
                    Mix_PlayChannel(1, hoverSound, 0);
                }
                else
                {
                    backindex = 0;
                    Mix_PlayChannel(1, hoverSound, 0);
                }
                break;

            case SDLK_RETURN:
                if (backindex == 1)
                {

                    done = 0;
                }

                break;
            }
            break;

        case SDL_MOUSEMOTION:
            backindex = 0;
            if (event.motion.x > 10 && event.motion.y > 10 && event.motion.x < 200 && event.motion.y < 80)
            {
                backindex = 1;
                if (backhover == 1)
                {
                    Mix_PlayChannel(1, hoverSound, 0);
                }
                backhover = 0;
            }
            else
            {
                backhover = 1;
            }

            break;

        case SDL_MOUSEBUTTONDOWN:

            if (backindex == 1)
            {
                done = 0;
            }

            break;
        }
    }

    SDL_FreeSurface(creditsBg);
}
