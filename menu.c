#include "Headers/headers.h"


int quit(SDL_Surface *ecran)
{
    //simple variable
    int yesIndex = 0, noIndex = 0, done = 1;
    int english ;
    getlanguage(&english);
   //  L.english = ; //langue : anglais par défaut

    //declare and set the position variable
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;

    //declare and set the exit alert images and the background
    SDL_Surface *exitMenuBg, *exitYes[3], *exitNo[3] ;

    exitMenuBg = IMG_Load("Assets/graphic/MainMenu/exitBg.jpg");

    exitNo[0] = IMG_Load("Assets/graphic/MainMenu/exit-no0.png");
    exitNo[1] = IMG_Load("Assets/graphic/MainMenu/exit-no1.png");
    exitNo[2] = IMG_Load("Assets/graphic/MainMenu/exit-no2.png");

    exitYes[0] = IMG_Load("Assets/graphic/MainMenu/exit-yes0.png");
    exitYes[1] = IMG_Load("Assets/graphic/MainMenu/exit-yes1.png");
    exitYes[2] = IMG_Load("Assets/graphic/MainMenu/exit-yes2.png");
    //declare and set the exit alert images and the background (frensh version)
    SDL_Surface *exitMenuBg_frensh, *exitOui[3], *exitNon[3] ;

    exitMenuBg_frensh = IMG_Load("Assets/graphic/MainMenu/quitterbg.png");

    exitNon[0] = IMG_Load("Assets/graphic/MainMenu/non_normal.png");
    exitNon[1] = IMG_Load("Assets/graphic/MainMenu/non_hover.png");
    exitNon[2] = IMG_Load("Assets/graphic/MainMenu/non_click.png");

    exitOui[0] = IMG_Load("Assets/graphic/MainMenu/oui_normal.png");
    exitOui[1] = IMG_Load("Assets/graphic/MainMenu/oui_hover.png");
    exitOui[2] = IMG_Load("Assets/graphic/MainMenu/oui_click.png");
    

    //declare the event
    SDL_Event event;

    while (done)
    {
        //blint the background and the exit no and yes buttons
        if(english == 0) //english version
        {
        SDL_BlitSurface(exitMenuBg, NULL, ecran, &pos);
        SDL_BlitSurface(exitNo[noIndex], NULL, ecran, &pos);
        SDL_BlitSurface(exitYes[yesIndex], NULL, ecran, &pos);
        SDL_Flip(ecran);
        }
        else if (english == 1)//frensh version
        {
        SDL_BlitSurface(exitMenuBg_frensh, NULL, ecran, &pos);
        SDL_BlitSurface(exitNon[noIndex], NULL, ecran, &pos);
        SDL_BlitSurface(exitOui[yesIndex], NULL, ecran, &pos);
        SDL_Flip(ecran);
        }

        SDL_WaitEvent(&event);

        switch (event.type)
        {

        case SDL_QUIT:
            return 1;

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                if (yesIndex == 0 && noIndex == 0)
                {
                    yesIndex = 0;
                    noIndex = 1;
                }

                else if (yesIndex == 0 && noIndex == 1)
                {
                    yesIndex = 1;
                    noIndex = 0;
                }

                else if (yesIndex == 1 && noIndex == 0)
                {
                    yesIndex = 0;
                    noIndex = 1;
                }
                break;

            case SDLK_RIGHT:

                if (yesIndex == 0 && noIndex == 0)
                {
                    yesIndex = 0;
                    noIndex = 1;
                }

                else if (yesIndex == 0 && noIndex == 1)
                {
                    yesIndex = 1;
                    noIndex = 0;
                }

                else if (yesIndex == 1 && noIndex == 0)
                {
                    yesIndex = 0;
                    noIndex = 1;
                }
                break;

            case SDLK_RETURN:
                if (noIndex == 1)
                {
                    if(english == 0)
                    {
                    SDL_BlitSurface(exitNo[2], NULL, ecran, &pos);
                    SDL_Flip(ecran);
                    SDL_Delay(200);
                    SDL_FreeSurface(exitMenuBg);
                    SDL_FreeSurface(exitNo[noIndex]);
                    }
                    else if(english ==1)
                    {
                    SDL_BlitSurface(exitNon[2], NULL, ecran, &pos);
                    SDL_Flip(ecran);
                    SDL_Delay(200);
                    SDL_FreeSurface(exitMenuBg_frensh);
                    SDL_FreeSurface(exitNon[noIndex]);
                    }
                    return 0;
                }
                else if (yesIndex == 1)
                {
                    if(english == 0)
                    {
                    SDL_BlitSurface(exitYes[2], NULL, ecran, &pos);
                    SDL_Flip(ecran);
                    SDL_Delay(200);
                    SDL_FreeSurface(exitMenuBg);
                    SDL_FreeSurface(exitYes[yesIndex]);
                    }
                    else if(english == 1 )
                    {
                    SDL_BlitSurface(exitOui[2], NULL, ecran, &pos);
                    SDL_Flip(ecran);
                    SDL_Delay(200);
                    SDL_FreeSurface(exitMenuBg_frensh);
                    SDL_FreeSurface(exitOui[yesIndex]);
                    }
                    return 1;
                }
                break;
            }
            break;

        case SDL_MOUSEMOTION:
            yesIndex = 0;
            noIndex = 0;
            if (event.motion.x > 648 && event.motion.y > 437 && event.motion.x < 788 && event.motion.y < 495)
            {
                noIndex = 1;
            }
            else if (event.motion.x > 492 && event.motion.y > 437 && event.motion.x < 632 && event.motion.y < 495)
            {
                yesIndex = 1;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:

            if (noIndex == 1)
            {
                if(english == 0)
                {
                SDL_BlitSurface(exitNo[2], NULL, ecran, &pos);
                SDL_Flip(ecran);
                SDL_Delay(200);
                }
                else if(english == 1)
                {
                SDL_BlitSurface(exitNon[2], NULL, ecran, &pos);
                SDL_Flip(ecran);
                SDL_Delay(200);
                }
                return 0;
            }

            else if (yesIndex == 1)
            {
                if(english == 0)
                {
                SDL_BlitSurface(exitYes[2], NULL, ecran, &pos);
                SDL_Flip(ecran);
                SDL_Delay(200);
                SDL_Quit();
                }
                else if(english ==1 )
                {
                SDL_BlitSurface(exitOui[2], NULL, ecran, &pos);
                SDL_Flip(ecran);
                SDL_Delay(200);
                SDL_Quit();
                }
                return 1;
            }
            break;
        }
    }
}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void mainMenu(SDL_Surface *screen, int *action)
{
    //simple variable
    int musicVol;
    int playIndex = 1, settingsIndex = 0, creditsIndex = 0, exitIndex = 0, muteIndex = 0; //declare the index of each button table
    int english ;
    getlanguage(&english);

    //get the music volume from volume.txt
    getVolume(&musicVol);

    //using text in our game----------------------------------
    TTF_Init();
    SDL_Surface *byLunaticsText , *parLunaticsText;
    TTF_Font *police;
    police = TTF_OpenFont("Assets/fonts/BelligiaDemoRegular.ttf", 20);
    SDL_Color white = {255, 255, 255};
    byLunaticsText = TTF_RenderText_Blended(police, "By Lunatics", white);
    parLunaticsText = TTF_RenderText_Blended(police, "Par Lunatics", white);
    SDL_Rect textPos;
    textPos.x = 10;
    textPos.y = 680;
    //using text----------------------------------

    //declare the main menu bg
    SDL_Surface *mainMenuBg = NULL;

    //declare and set the main menu buttons
    SDL_Surface *play[3], *settings[3], *credits[3], *exit[3];
    play[0] = IMG_Load("Assets/graphic/MainMenu/play0.png");
    play[1] = IMG_Load("Assets/graphic/MainMenu/play1.png");
    play[2] = IMG_Load("Assets/graphic/MainMenu/play2.png");

    settings[0] = IMG_Load("Assets/graphic/MainMenu/settings0.png");
    settings[1] = IMG_Load("Assets/graphic/MainMenu/settings1.png");
    settings[2] = IMG_Load("Assets/graphic/MainMenu/settings2.png");

    credits[0] = IMG_Load("Assets/graphic/MainMenu/credits0.png");
    credits[1] = IMG_Load("Assets/graphic/MainMenu/credits1.png");
    credits[2] = IMG_Load("Assets/graphic/MainMenu/credits2.png");

    exit[0] = IMG_Load("Assets/graphic/MainMenu/exit0.png");
    exit[1] = IMG_Load("Assets/graphic/MainMenu/exit1.png");
    exit[2] = IMG_Load("Assets/graphic/MainMenu/exit2.png");
    
    //declare and set the main menu buttons frensh version
    SDL_Surface *jouer[3], *parametre[3], *equipe[3], *quitter[3];
    jouer[0] = IMG_Load("Assets/graphic/MainMenu/jouer0.png");
    jouer[1] = IMG_Load("Assets/graphic/MainMenu/jouer1.png");
    jouer[2] = IMG_Load("Assets/graphic/MainMenu/jouer2.png");

    parametre[0] = IMG_Load("Assets/graphic/MainMenu/parametre0.png");
    parametre[1] = IMG_Load("Assets/graphic/MainMenu/parametre1.png");
    parametre[2] = IMG_Load("Assets/graphic/MainMenu/parametre2.png");

    equipe[0] = IMG_Load("Assets/graphic/MainMenu/credit0.png");
    equipe[1] = IMG_Load("Assets/graphic/MainMenu/credit1.png");
    equipe[2] = IMG_Load("Assets/graphic/MainMenu/credit2.png");

    quitter[0] = IMG_Load("Assets/graphic/MainMenu/quitter0.png");
    quitter[1] = IMG_Load("Assets/graphic/MainMenu/quitter1.png");
    quitter[2] = IMG_Load("Assets/graphic/MainMenu/quitter2.png");

    //declare and set the mute button
    SDL_Surface *mute[2];
    mute[0] = IMG_Load("Assets/graphic/MainMenu/musicOn0.png");
    mute[1] = IMG_Load("Assets/graphic/MainMenu/musicOff0.png");


    //declare position
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;

    //initialise audio
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

    //declare and set music
    Mix_Music *music;
    music = Mix_LoadMUS("Assets/graphic/MainMenu/ost.mp3");

    //declare and set the hover sound effect
    Mix_Chunk *hoverSound;
    hoverSound = Mix_LoadWAV("Assets/graphic/MainMenu/click.wav");

    //set the music volume andplay it
    Mix_VolumeMusic(musicVol);
    Mix_PlayMusic(music, -1);

    //declare the event
    SDL_Event event;

    int i = 0;
    char filename[100];
    SDL_EnableKeyRepeat(0, 0);
    int done = 1;
    int hoverPlay = 1, hoverOption = 1, hoverCredits = 1, hoverExit = 1, hoverMute;
    while (done)
    {
        //animate the background
        if (i != 0)
            SDL_FreeSurface(mainMenuBg);

        sprintf(filename, "Assets/graphic/menuAnimation/bgAnime_%d.jpg", i);
        mainMenuBg = IMG_Load(filename);
        i++;
        if (i > 190)
        {
            i = 0;
        }

        //blit the images on screen english version
        if(english == 0)
        {
        SDL_BlitSurface(mainMenuBg, NULL, screen, &pos);
        SDL_BlitSurface(play[playIndex], NULL, screen, &pos);
        SDL_BlitSurface(settings[settingsIndex], NULL, screen, &pos);
        SDL_BlitSurface(credits[creditsIndex], NULL, screen, &pos);
        SDL_BlitSurface(exit[exitIndex], NULL, screen, &pos);
        SDL_BlitSurface(mute[muteIndex], NULL, screen, &pos);
        SDL_BlitSurface(byLunaticsText, NULL, screen, &textPos);
        }
        else if(english == 1)
        {
        SDL_BlitSurface(mainMenuBg, NULL, screen, &pos);
        SDL_BlitSurface(jouer[playIndex], NULL, screen, &pos);
        SDL_BlitSurface(parametre[settingsIndex], NULL, screen, &pos);
        SDL_BlitSurface(equipe[creditsIndex], NULL, screen, &pos);
        SDL_BlitSurface(quitter[exitIndex], NULL, screen, &pos);
        SDL_BlitSurface(mute[muteIndex], NULL, screen, &pos);
        SDL_BlitSurface(parLunaticsText, NULL, screen, &textPos);
        }
        

        SDL_Flip(screen);

        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                (*action) = 0;
                done = 0;
                SDL_Quit();
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_m:
                    muteIndex = 1;
                    Mix_PauseMusic();
                    break;
                case SDLK_q:
                    (*action) = 0;
                    done = 0;
                    SDL_Quit();
                    break;
                case SDLK_p:
                    muteIndex = 0;
                    Mix_ResumeMusic();
                    break;

                case SDLK_UP:
                    if (playIndex == 0 && creditsIndex == 0 && exitIndex == 0 && settingsIndex == 0)
                    {
                        playIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (playIndex == 1)
                    {
                        playIndex = 0;
                        creditsIndex = 0;
                        settingsIndex = 0;
                        exitIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    else if (exitIndex == 1)
                    {
                        playIndex = 0;
                        settingsIndex = 0;
                        creditsIndex = 1;
                        exitIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    else if (creditsIndex == 1)
                    {
                        playIndex = 0;
                        settingsIndex = 1;
                        creditsIndex = 0;
                        exitIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    else if (settingsIndex == 1)
                    {
                        playIndex = 1;
                        settingsIndex = 0;
                        creditsIndex = 0;
                        exitIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    break;

                case SDLK_DOWN:
                    if (playIndex == 0 && creditsIndex == 0 && exitIndex == 0 && settingsIndex == 0)
                    {
                        playIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    else if (playIndex == 1)
                    {
                        playIndex = 0;
                        settingsIndex = 1;
                        creditsIndex = 0;
                        exitIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    else if (settingsIndex == 1)
                    {
                        playIndex = 0;
                        settingsIndex = 0;
                        creditsIndex = 1;
                        exitIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    else if (creditsIndex == 1)
                    {
                        playIndex = 0;
                        settingsIndex = 0;
                        creditsIndex = 0;
                        exitIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (exitIndex == 1)
                    {
                        playIndex = 1;
                        settingsIndex = 0;
                        creditsIndex = 0;
                        exitIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    break;

                case SDLK_RETURN:
                    if (playIndex == 1)
                    {
                        if(english == 0 )
                        {
                            SDL_BlitSurface(play[2], NULL, screen, &pos);
                        }else if (english == 1)
                        {
                            SDL_BlitSurface(jouer[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);
                       newORloadGame(screen);
                       // (*action) = 1;
                        //gameMode(screen);

                        done = 0;
                    }
                    else if (settingsIndex == 1)
                    {
                        if(english == 0 )
                        {
                        SDL_BlitSurface(settings[2], NULL, screen, &pos);
                        }
                        else if(english == 1)
                        {
                            SDL_BlitSurface(parametre[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);
                        (*action) = 2;
                        done = 0;
                    }
                    else if (creditsIndex == 1)
                    {
                        if(english == 0)
                        {
                            SDL_BlitSurface(credits[2], NULL, screen, &pos);
                        }
                        else if (english == 1)
                        {
                            SDL_BlitSurface(equipe[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);

                        (*action) = 3;
                        done = 0;
                    }
                    else if (exitIndex == 1)
                    {
                        if(english == 0)
                        {
                        SDL_BlitSurface(exit[2], NULL, screen, &pos);
                        }else if(english == 1)
                        {
                            SDL_BlitSurface(quitter[2], NULL, screen, &pos);
                        }        
                        SDL_Flip(screen);
                        SDL_Delay(16);
                        if (quit(screen) == 1)
                        {
                            (*action) = 0;
                            done = 0;
                            SDL_Quit();
                        }
                    }

                    break;
                }
                break;

            case SDL_MOUSEMOTION:
                //intialise the buttons
                playIndex = 0;
                settingsIndex = 0;
                creditsIndex = 0;
                exitIndex = 0;
                hoverMute = 0;

                if (event.motion.x > 510 && event.motion.y > 275 && event.motion.x < 776 && event.motion.y < 360)
                {
                    playIndex = 1;
                    if (hoverPlay == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    hoverPlay = 0;
                }
                else
                {
                    hoverPlay = 1;
                }

                if (event.motion.x > 510 && event.motion.y > 382 && event.motion.x < 776 && event.motion.y < 466)
                {
                    settingsIndex = 1;
                    if (hoverOption == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    hoverOption = 0;
                }
                else
                {
                    hoverOption = 1;
                }

                if (event.motion.x > 510 && event.motion.y > 488 && event.motion.x < 776 && event.motion.y < 573)
                {
                    creditsIndex = 1;
                    if (hoverCredits == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    hoverCredits = 0;
                }
                else
                {
                    hoverCredits = 1;
                }

                if (event.motion.x > 510 && event.motion.y > 593 && event.motion.x < 776 && event.motion.y < 677)
                {
                    exitIndex = 1;
                    if (hoverExit == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    hoverExit = 0;
                }
                else
                {
                    hoverExit = 1;
                }

                if (event.motion.x > 1150 && event.motion.y > 10 && event.motion.x < 1240 && event.motion.y < 92)
                {
                    hoverMute = 1;
                }
                else
                {
                    hoverMute = 0;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (playIndex == 1)
                    {
                        if(english == 0 )
                        {
                            SDL_BlitSurface(play[2], NULL, screen, &pos);
                        }else if (english == 1)
                        {
                            SDL_BlitSurface(jouer[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);
                        (*action) = 1;
                        //gameMode(screen);
                        done = 0;
                    }

                    else if (settingsIndex == 1)
                    {
                        if(english == 0 )
                        {
                        SDL_BlitSurface(settings[2], NULL, screen, &pos);
                        }
                        else if(english == 1)
                        {
                            SDL_BlitSurface(parametre[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);
                        (*action) = 2;
                        done = 0;
                    }

                    else if (creditsIndex == 1)
                    {
                        if(english == 0)
                        {
                            SDL_BlitSurface(credits[2], NULL, screen, &pos);
                        }
                        else if (english == 1)
                        {
                            SDL_BlitSurface(equipe[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);
                        (*action) = 3;
                        done = 0;
                    }

                    else if (exitIndex == 1)
                    {
                        if(english == 0)
                        {
                        SDL_BlitSurface(exit[2], NULL, screen, &pos);
                        }else if(english == 1)
                        {
                            SDL_BlitSurface(quitter[2], NULL, screen, &pos);
                        }
                        SDL_Flip(screen);
                        SDL_Delay(16);
                        if (quit(screen) == 1)
                        {
                            (*action) = 0;
                            done = 0;
                            SDL_Quit();
                        }
                    }

                    if (hoverMute == 1)
                    {
                        if (muteIndex == 0)
                        {
                            muteIndex = 1;
                            SDL_BlitSurface(mute[1], NULL, screen, &pos);
                            SDL_Flip(screen);
                            Mix_PauseMusic();
                        }
                        else
                        {
                            muteIndex = 0;
                            SDL_BlitSurface(mute[0], NULL, screen, &pos);
                            SDL_Flip(screen);
                            Mix_ResumeMusic();
                        }
                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(mainMenuBg);

    SDL_FreeSurface(play[0]);
    SDL_FreeSurface(play[1]);
    SDL_FreeSurface(play[2]);
    
    SDL_FreeSurface(jouer[0]);
    SDL_FreeSurface(jouer[1]);
    SDL_FreeSurface(jouer[2]);

    SDL_FreeSurface(settings[0]);
    SDL_FreeSurface(parametre[0]);
    SDL_FreeSurface(parametre[1]);
    SDL_FreeSurface(parametre[2]);

    SDL_FreeSurface(credits[0]);
    SDL_FreeSurface(credits[1]);
    SDL_FreeSurface(credits[2]);

    SDL_FreeSurface(equipe[0]);
    SDL_FreeSurface(equipe[1]);
    SDL_FreeSurface(equipe[2]);
    
    SDL_FreeSurface(exit[0]);
    SDL_FreeSurface(exit[1]);
    SDL_FreeSurface(exit[2]);

    SDL_FreeSurface(quitter[0]);
    SDL_FreeSurface(quitter[1]);
    SDL_FreeSurface(quitter[2]);
}

//get the volume level from the file "volume.txt"
void getVolume(int *music)
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/volume.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", music);
    fclose(fichier);
}

void getlanguage(int *english)
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/language.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d", english);
    fclose(fichier);
}