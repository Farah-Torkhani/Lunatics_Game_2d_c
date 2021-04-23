#include "Headers/headers.h"
#include "Headers/selectchamp.h"

int selectchamp(SDL_Surface *screen)
{
    //declare simple variables
    int select_right_Index = 0, select_left_Index = 0, backIndex = 0, done = 1;
    int english;
     getlanguage(&english);

    //simple variable hover test
    int select_right_Hover = 1, select_left_Hover = 1, backHover = 1;

    //declare the select champ images
    SDL_Surface *selectchampBg ,*selectchampBg_fr, *select_right[2] ,*select_right_fr[2], *select_left[2] ,*select_left_fr[2], *back[2],*back_fr[2];

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
    selectchampBg = IMG_Load("Assets/graphic/selectchamp/selectchampBg.png");
    selectchampBg_fr = IMG_Load("Assets/graphic/selectchamp/champbg_fr.png");

    select_right[0] = IMG_Load("Assets/graphic/selectchamp/select_right.png");
    select_right[1] = IMG_Load("Assets/graphic/selectchamp/select_right_hover.png");

    select_right_fr[0] = IMG_Load("Assets/graphic/selectchamp/choisird0.png");
    select_right_fr[1] = IMG_Load("Assets/graphic/selectchamp/choisird1.png");

    select_left[0] = IMG_Load("Assets/graphic/selectchamp/select_left.png");
    select_left[1] = IMG_Load("Assets/graphic/selectchamp/select_left_hover.png");

    select_left_fr[0] = IMG_Load("Assets/graphic/selectchamp/choisirg0.png");
    select_left_fr[1] = IMG_Load("Assets/graphic/selectchamp/choisirg1.png");

    back[0] = IMG_Load("Assets/graphic/selectchamp/back.png");
    back[1] = IMG_Load("Assets/graphic/selectchamp/backhover.png");

    back_fr[0] = IMG_Load("Assets/graphic/selectchamp/retour1.png");
    back_fr[1] = IMG_Load("Assets/graphic/selectchamp/retour0.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        if(english == 0)
        {
        SDL_BlitSurface(selectchampBg, NULL, screen, &pos);
        SDL_BlitSurface(select_right[select_right_Index], NULL, screen, &pos);
        SDL_BlitSurface(select_left[select_left_Index], NULL, screen, &pos);
        SDL_BlitSurface(back[backIndex], NULL, screen, &pos);
        }
        else if (english == 1)
        {
        SDL_BlitSurface(selectchampBg_fr, NULL, screen, &pos);
        SDL_BlitSurface(select_right_fr[select_right_Index], NULL, screen, &pos);
        SDL_BlitSurface(select_left_fr[select_left_Index], NULL, screen, &pos);
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
                    if (select_right_Index == 0 && select_left_Index == 0 && backIndex == 0)
                    {
                        select_left_Index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 0 && select_left_Index == 1 && backIndex == 0)
                    {
                        select_left_Index = 0;
                        select_right_Index = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 1 && select_left_Index == 0 && backIndex == 0)
                    {
                        select_left_Index = 0;
                        select_right_Index = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 0 && select_left_Index == 0 && backIndex == 1)
                    {
                        select_left_Index = 1;
                        select_right_Index = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;

                    case SDLK_DOWN:
                    if (select_right_Index == 0 && select_left_Index == 0 && backIndex == 0)
                    {
                        select_left_Index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 0 && select_left_Index == 1 && backIndex == 0)
                    {
                        select_left_Index = 0;
                        select_right_Index = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 1 && select_left_Index == 0 && backIndex == 0)
                    {
                        select_left_Index = 0;
                        select_right_Index = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 0 && select_left_Index == 0 && backIndex == 1)
                    {
                        select_left_Index = 1;
                        select_right_Index = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;

                    case SDLK_RIGHT:
                     if (select_right_Index == 0 && select_left_Index == 1 && backIndex == 0)
                    {
                        select_left_Index = 0;
                        select_right_Index = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 1 && select_left_Index == 0 && backIndex == 0)
                    {
                        select_left_Index = 1;
                        select_right_Index = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;

                    case SDLK_LEFT:
                     if (select_right_Index == 0 && select_left_Index == 1 && backIndex == 0)
                    {
                        select_left_Index = 0;
                        select_right_Index = 1;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (select_right_Index == 1 && select_left_Index == 0 && backIndex == 0)
                    {
                        select_left_Index = 1;
                        select_right_Index = 0;
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                       break;

                    case SDLK_RETURN:
                    if (backIndex == 1)
                    {
                        done = 0;
                    }
                    else if (select_right_Index == 1 && select_left_Index == 0 && backIndex == 0)
                    {
                        /*
                      if(stage_1(screen)==1)
                      {
                          done=0;
                          return 1;
                      }*/
                      stage_1(screen , 0);
                       

                    }
                    break;
                }
                break;

            case SDL_MOUSEMOTION:
                select_right_Index = 0;
                select_left_Index = 0;
                backIndex = 0;
                if (event.motion.x > 247 && event.motion.y > 442 && event.motion.x < 375 && event.motion.y < 500)
                {
                    select_left_Index = 1;
                    if (select_left_Hover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    select_left_Hover = 0;
                }
                else
                {
                    select_left_Hover = 1;
                }

                if (event.motion.x > 916 && event.motion.y >440 && event.motion.x < 1050 && event.motion.y < 500)
                {
                    select_right_Index = 1;
                    if (select_right_Hover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    select_right_Hover = 0;
                }
                else
                {
                    select_right_Hover = 1;
                }

                if (event.motion.x > 570 && event.motion.y > 570 && event.motion.x < 710 && event.motion.y < 630)
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
                }
                break;
            }
        }
    }
//SDL_FreeSurface(selectchampBg);         
return 0;       
}