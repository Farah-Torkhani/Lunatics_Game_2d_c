#include "Headers/headers.h"

void settingsMenu(SDL_Surface *screen)
{
    //declare simple variables
    int done = 1, volInputIndex = 0, prevVolIndex = 0, nextVolIndex = 0, volBarIndex, resInputIndex = 0, prevResIndex = 0, nextResIndex = 0, resModeIndex = 0;
    int langInputIndex = 0, prevLangIndex = 0, nextLangIndex = 0, langModeIndex = 0, contInputIndex = 0, backIndex = 0;
    int musicVol;
    int english;
     getlanguage(&english);
   

    //simple variable hover test
    int volInputHover = 1, resInputHover = 1, langInputHover = 1, contInputHover = 1, backHover = 1;

    //declare the settings images
    SDL_Surface *settingBG = NULL ,*settingBG_fr = NULL,*resMode_fr[2], *volInput[2], *prevVol[2], *nextVol[2], *volBar[6], *resInput[2] , *resInput_fr[2], *prevRes[2], *nextRes[2], *resMode[2];
    SDL_Surface *langInput[2],*controllers_fr[2], *langInput_fr[2] ,*retour[2], *prevLang[2], *nextLang[2], *langMode[2], *controllers[2], *back[2];

    //declare and set the global position
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
    hoverSound = Mix_LoadWAV("Assets/graphic/settings/click.wav");

    //get the music volume from the file
    getVolume(&musicVol);

    volBarIndex = musicVol / 20;

    //set the music volume andplay it
    Mix_VolumeMusic(musicVol);
    Mix_PlayMusic(music, -1);

    hoverSound = Mix_LoadWAV("Assets/graphic/settings/click.wav");

    //set settings bg
    settingBG = IMG_Load("Assets/graphic/settings/settingsMenuBg.jpg");

//*******set settings bg frensh version*******************************************************
    settingBG_fr = IMG_Load("Assets/graphic/settings/parametrebg.png");

    //set volume input images
    volInput[0] = IMG_Load("Assets/graphic/settings/VolumeInput_normal.png");
    volInput[1] = IMG_Load("Assets/graphic/settings/VolumeInput_hover.png");

    prevVol[0] = IMG_Load("Assets/graphic/settings/prevVol_normal.png");
    prevVol[1] = IMG_Load("Assets/graphic/settings/prevVol_hover.png");

    nextVol[0] = IMG_Load("Assets/graphic/settings/nextVol_normal.png");
    nextVol[1] = IMG_Load("Assets/graphic/settings/nextVol_hover.png");

    volBar[0] = IMG_Load("Assets/graphic/settings/vol0.png");
    volBar[1] = IMG_Load("Assets/graphic/settings/vol1.png");
    volBar[2] = IMG_Load("Assets/graphic/settings/vol2.png");
    volBar[3] = IMG_Load("Assets/graphic/settings/vol3.png");
    volBar[4] = IMG_Load("Assets/graphic/settings/vol4.png");
    volBar[5] = IMG_Load("Assets/graphic/settings/vol5.png");

    //set resolution input images
    resInput[0] = IMG_Load("Assets/graphic/settings/resInput_normal.png");
    resInput[1] = IMG_Load("Assets/graphic/settings/resInput_hover.png");

    resInput_fr[0] = IMG_Load("Assets/graphic/settings/resolution1.png");
    resInput_fr[1] = IMG_Load("Assets/graphic/settings/resolution0.png");

    prevRes[0] = IMG_Load("Assets/graphic/settings/prevRes_normal.png");
    prevRes[1] = IMG_Load("Assets/graphic/settings/prevRes_hover.png");

    nextRes[0] = IMG_Load("Assets/graphic/settings/nextRes_normal.png");
    nextRes[1] = IMG_Load("Assets/graphic/settings/nextRes_hover.png");

    resMode[0] = IMG_Load("Assets/graphic/settings/windowed.png");
    resMode[1] = IMG_Load("Assets/graphic/settings/fulScreen.png");

    resMode_fr[0] = IMG_Load("Assets/graphic/settings/fenetre.png");
    resMode_fr[1] = IMG_Load("Assets/graphic/settings/plein-ecran.png");

    //set language input images
    langInput[0] = IMG_Load("Assets/graphic/settings/languageInput_normal.png");
    langInput[1] = IMG_Load("Assets/graphic/settings/languageInput_hover.png");

    langInput_fr[0] = IMG_Load("Assets/graphic/settings/langue0.png");
    langInput_fr[1] = IMG_Load("Assets/graphic/settings/langue1.png");

    prevLang[0] = IMG_Load("Assets/graphic/settings/prevLanguage_normal.png");
    prevLang[1] = IMG_Load("Assets/graphic/settings/prevLanguage_hover.png");

    nextLang[0] = IMG_Load("Assets/graphic/settings/nextLanguage_normal.png");
    nextLang[1] = IMG_Load("Assets/graphic/settings/nextLanguage_hover.png");

    langMode[0] = IMG_Load("Assets/graphic/settings/english.png");
    langMode[1] = IMG_Load("Assets/graphic/settings/francais.png");

    //set controllers input images
    controllers[0] = IMG_Load("Assets/graphic/settings/controllers_normal.png");
    controllers[1] = IMG_Load("Assets/graphic/settings/controllers_hover.png");

    //set controllers input images frensh version
    controllers_fr[0] = IMG_Load("Assets/graphic/settings/controleurs1.png");
    controllers_fr[1] = IMG_Load("Assets/graphic/settings/controleurs0.png");

    //set back images
    back[0] = IMG_Load("Assets/graphic/settings/back_normal.png");
    back[1] = IMG_Load("Assets/graphic/settings/back_hover.png");

    //set back images frensh version
    retour[0] = IMG_Load("Assets/graphic/settings/retour1.png");
    retour[1] = IMG_Load("Assets/graphic/settings/retour0.png");

    //declare the event
    SDL_Event event;

    while (done)
    {
        if(english == 0)
        {
            SDL_BlitSurface(settingBG, NULL, screen, &pos);
        }
        else if( english == 1 )
        {
            SDL_BlitSurface(settingBG_fr, NULL, screen, &pos);
        }
        

        //blit the volume input images
        SDL_BlitSurface(volInput[volInputIndex], NULL, screen, &pos);
        SDL_BlitSurface(prevVol[prevVolIndex], NULL, screen, &pos);
        SDL_BlitSurface(nextVol[nextVolIndex], NULL, screen, &pos);
        SDL_BlitSurface(volBar[volBarIndex], NULL, screen, &pos);

        
        if(english == 0)
        {
              //blit language input images
        SDL_BlitSurface(langInput[langInputIndex], NULL, screen, &pos);
        SDL_BlitSurface(prevLang[prevLangIndex], NULL, screen, &pos);
        SDL_BlitSurface(nextLang[nextLangIndex], NULL, screen, &pos);
        SDL_BlitSurface(langMode[english], NULL, screen, &pos);
        //blit resolution input images
        SDL_BlitSurface(resInput[resInputIndex], NULL, screen, &pos);//
        SDL_BlitSurface(prevRes[prevResIndex], NULL, screen, &pos);
        SDL_BlitSurface(nextRes[nextResIndex], NULL, screen, &pos);
        SDL_BlitSurface(resMode[resModeIndex], NULL, screen, &pos);//
    
        //blit controllers input images
        SDL_BlitSurface(controllers[contInputIndex], NULL, screen, &pos);//

        //blit back images
        SDL_BlitSurface(back[backIndex], NULL, screen, &pos);//
        }
        else if(english == 1)//frensh version
        {
             
         //blit language input images
        SDL_BlitSurface(langInput_fr[langInputIndex], NULL, screen, &pos);
        SDL_BlitSurface(prevLang[prevLangIndex], NULL, screen, &pos);
        SDL_BlitSurface(nextLang[nextLangIndex], NULL, screen, &pos);
        SDL_BlitSurface(langMode[english], NULL, screen, &pos);
        //blit resolution input images
        SDL_BlitSurface(resInput_fr[resInputIndex], NULL, screen, &pos);//
        SDL_BlitSurface(prevRes[prevResIndex], NULL, screen, &pos);
        SDL_BlitSurface(nextRes[nextResIndex], NULL, screen, &pos);
        SDL_BlitSurface(resMode_fr[resModeIndex], NULL, screen, &pos);//
    
        //blit controllers input images
        SDL_BlitSurface(controllers_fr[contInputIndex], NULL, screen, &pos);//

        //blit back images
        SDL_BlitSurface(retour[backIndex], NULL, screen, &pos);//
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
                    //mainMenu(screen, action);
                    break;

                case SDLK_UP:
                    if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 0)
                    {
                        volInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 1 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 0)
                    {
                        volInputIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 1)
                    {
                        backIndex = 0;
                        contInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 1 && backIndex == 0)
                    {
                        contInputIndex = 0;
                        langInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 1 && contInputIndex == 0 && backIndex == 0)
                    {
                        langInputIndex = 0;
                        resInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 1 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 0)
                    {
                        resInputIndex = 0;
                        volInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;

                case SDLK_DOWN:
                    if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 0)
                    {
                        volInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 1 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 0)
                    {
                        volInputIndex = 0;
                        resInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 1 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 0)
                    {
                        resInputIndex = 0;
                        langInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 1 && contInputIndex == 0 && backIndex == 0)
                    {
                        langInputIndex = 0;
                        contInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 1 && backIndex == 0)
                    {
                        contInputIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (volInputIndex == 0 && resInputIndex == 0 && langInputIndex == 0 && contInputIndex == 0 && backIndex == 1)
                    {
                        backIndex = 0;
                        volInputIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;
                case SDLK_LEFT:
                    if (volInputIndex == 1)
                    {
                        if (volBarIndex > 0)
                        {
                            volBarIndex--;
                            musicVol = volBarIndex * 20;
                            saveVolume(musicVol);
                            Mix_VolumeMusic(musicVol);
                        }
                    }
                    else if (resInputIndex == 1)
                    {
                        if (resModeIndex == 0)
                        {
                            resModeIndex = 1;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                        }
                        else
                        {
                            resModeIndex = 0;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        }
                    }
                    else if (langInputIndex == 1)
                    {
                        if (langModeIndex == 0)//english
                        {
                            langModeIndex = 1;//frensh
                            english = 1;
                            savelanguge(english);

                        }
                        else
                        {
                            langModeIndex = 0;
                            english = 0;
                            savelanguge(english);
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    if (volInputIndex == 1)
                    {
                        if (volBarIndex < 5)
                        {
                            volBarIndex++;
                            musicVol = volBarIndex * 20;
                            saveVolume(musicVol);
                            Mix_VolumeMusic(musicVol);
                        }
                    }
                    else if (resInputIndex == 1)
                    {
                        if (resModeIndex == 0)
                        {
                            resModeIndex = 1;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                        }
                        else
                        {
                            resModeIndex = 0;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);
                        }
                    }
                    else if (langInputIndex == 1)
                    {
                        if (langModeIndex == 0)
                        {
                            langModeIndex = 1;
                            english = 1;
                            savelanguge(english);
                        }
                        else
                        {
                            langModeIndex = 0;
                            english = 0;
                            savelanguge(english);
                        }
                    }
                    break;
                case SDLK_RETURN:
                    if (backIndex == 1)
                    {    
                       done = 0;
                       
                    }
                    else if (contInputIndex == 1)
                    {
                        controllersScreen(screen);
                    }
                    break;
                    
                }
                break;

            case SDL_MOUSEMOTION:
                volInputIndex = 0;
                prevVolIndex = 0;
                nextVolIndex = 0;

                resInputIndex = 0;
                prevResIndex = 0;
                nextResIndex = 0;

                langInputIndex = 0;
                prevLangIndex = 0;
                nextLangIndex = 0;

                contInputIndex = 0;

                backIndex = 0;

                //volume input
                if (event.motion.x > 350 && event.motion.y > 178 && event.motion.x < 930 && event.motion.y < 242)
                {
                    volInputIndex = 1;
                    if (volInputHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    volInputHover = 0;
                }
                else
                {
                    volInputHover = 1;
                }
                //hover prevVol
                if (event.motion.x > 557 && event.motion.y > 191 && event.motion.x < 585 && event.motion.y < 226)
                {
                    prevVolIndex = 1;
                }
                //hover nextVol
                if (event.motion.x > 874 && event.motion.y > 191 && event.motion.x < 900 && event.motion.y < 226)
                {
                    nextVolIndex = 1;
                }
                //volume input
                //--------------------------------------------------------------------------

                //res input
                if (event.motion.x > 350 && event.motion.y > 276 && event.motion.x < 930 && event.motion.y < 341)
                {
                    resInputIndex = 1;
                    if (resInputHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    resInputHover = 0;
                }
                else
                {
                    resInputHover = 1;
                }
                //hover prevRes
                if (event.motion.x > 628 && event.motion.y > 291 && event.motion.x < 657 && event.motion.y < 327)
                {
                    prevResIndex = 1;
                }

                //hover nextRes
                if (event.motion.x > 873 && event.motion.y > 291 && event.motion.x < 900 && event.motion.y < 327)
                {
                    nextResIndex = 1;
                }
                //res input
                //--------------------------------------------------------------------------

                //language input
                if (event.motion.x > 350 && event.motion.y > 377 && event.motion.x < 930 && event.motion.y < 442)
                {
                    langInputIndex = 1;
                    if (langInputHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    langInputHover = 0;
                }
                else
                {
                    langInputHover = 1;
                }
                //hover prevlang
                if (event.motion.x > 628 && event.motion.y > 392 && event.motion.x < 657 && event.motion.y < 426)
                {
                    prevLangIndex = 1;
                }

                //hover nextlang
                if (event.motion.x > 873 && event.motion.y > 392 && event.motion.x < 900 && event.motion.y < 426)
                {
                    nextLangIndex = 1;
                }
                //language input
                //--------------------------------------------------------------------------

                //controllers input
                if (event.motion.x > 350 && event.motion.y > 475 && event.motion.x < 708 && event.motion.y < 540)
                {
                    contInputIndex = 1;
                    if (contInputHover == 1)
                    {
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    contInputHover = 0;
                }
                else
                {
                    contInputHover = 1;
                }

                //controllers input
                //--------------------------------------------------------------------------

                //back button
                if (event.motion.x > 560 && event.motion.y > 614 && event.motion.x < 720 && event.motion.y < 678)
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

                //back button
                //--------------------------------------------------------------------------


            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    //volume input
                    if (nextVolIndex == 1)
                    {
                        if (volBarIndex < 5)
                        {
                            volBarIndex++;
                            musicVol = volBarIndex * 20;
                            saveVolume(musicVol);
                            Mix_VolumeMusic(musicVol);
                        }
                    }

                    if (prevVolIndex == 1)
                    {
                        if (volBarIndex > 0)
                        {
                            volBarIndex--;
                            musicVol = volBarIndex * 20;
                            saveVolume(musicVol);
                            Mix_VolumeMusic(musicVol);
                        }
                    }
                    //volume input
                    //------------------------------------------------------------------------------

                    //resolution input
                    if (nextResIndex == 1)
                    {
                        if (resModeIndex == 0)
                        {
                            resModeIndex = 1;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                        }
                        else
                        {
                            resModeIndex = 0;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);
                        }
                    }

                    if (prevResIndex == 1)
                    {
                        if (resModeIndex == 0)
                        {
                            resModeIndex = 1;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                        }
                        else
                        {
                            resModeIndex = 0;
                            screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_SWSURFACE | SDL_DOUBLEBUF);
                        }
                    }
                    //resolution input
                    //------------------------------------------------------------------------------

                    //language input
                    if (nextLangIndex == 1)
                    {
                        if (langModeIndex == 0)
                        {
                            langModeIndex = 1;
                        }
                        else
                        {
                            langModeIndex = 0;
                        }
                    }

                    if (prevLangIndex == 1)
                    {
                        if (langModeIndex == 0)
                        {
                            langModeIndex = 1;
                        }
                        else
                        {
                            langModeIndex = 0;
                        }
                    }
                    //language input
                    //------------------------------------------------------------------------------

                    //controllers input
                    if (contInputIndex == 1)
                    {
                        controllersScreen(screen);
                    }
                    //controllers input
                    //------------------------------------------------------------------------------

                    //back-----------
                    if (backIndex == 1)
                    {
                        //mainMenu(screen, action);
                        
                           done = 0;
                        
                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(settingBG);
    SDL_FreeSurface(volInput[0]);
    SDL_FreeSurface(volInput[1]);

    SDL_FreeSurface(prevVol[0]);
    SDL_FreeSurface(prevVol[1]);

    SDL_FreeSurface(nextVol[0]);
    SDL_FreeSurface(nextVol[1]);

    SDL_FreeSurface(volBar[0]);
    SDL_FreeSurface(volBar[1]);
    SDL_FreeSurface(volBar[2]);
    SDL_FreeSurface(volBar[3]);
    SDL_FreeSurface(volBar[4]);
    SDL_FreeSurface(volBar[5]);

    SDL_FreeSurface(prevRes[0]);
    SDL_FreeSurface(prevRes[1]);

    SDL_FreeSurface(nextRes[0]);
    SDL_FreeSurface(nextRes[1]);

    SDL_FreeSurface(resMode[0]);
    SDL_FreeSurface(resMode[1]);

    SDL_FreeSurface(prevLang[0]);
    SDL_FreeSurface(prevLang[1]);

    SDL_FreeSurface(nextLang[0]);
    SDL_FreeSurface(nextLang[1]);

    SDL_FreeSurface(langMode[0]);
    SDL_FreeSurface(langMode[1]);

    SDL_FreeSurface(controllers);

    SDL_FreeSurface(back[0]);
    SDL_FreeSurface(back[1]);
}

//save the volume level to the file "volume.txt"
void saveVolume(int music)
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/volume.txt", "w");
    fprintf(fichier, "%d", music);
    fclose(fichier);
}
//save the language to the file "languge.txt"
void savelanguge(int english)
{
FILE *fichier = NULL;
    fichier = fopen("Fichier/language.txt", "w");
    fprintf(fichier, "%d", english);
    fclose(fichier);
}


//---------------------------------------------ControllersScreen------------------------------------------------------------
void controllersScreen(SDL_Surface *screen)
{
    char Player1_Jump[10] , Player1_MouveR[10] , Player1_MouveL[10] , Player1_Run[10] , Player1_Attack[10];
    char Player2_Jump[10] , Player2_MouveR[10] , Player2_MouveL[10] , Player2_Run[10] , Player2_Attack[10];

    //declare simple variables
    int english,backIndex = 0 ,keyboardIndex = 0 ,keyboard2Index =0 , done = 1;
     getlanguage(&english);

    //simple variable hover test
    int backHover = 1;

    //declare the select game mode images
    SDL_Surface *controllersBg, *keyboard[3], *keyboard2[3], *table, *back[2];
    SDL_Surface *controllersBgfr, *keyboardfr[3], *keyboard2fr[3], *tablefr, *backfr[2];

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
    controllersBg = IMG_Load("Assets/graphic/controllers/controllersBg.jpg");
    keyboard[0] = IMG_Load("Assets/graphic/controllers/keyboard1_0.png");
    keyboard[1] = IMG_Load("Assets/graphic/controllers/keyboard1hover.png");
    keyboard[2] = IMG_Load("Assets/graphic/controllers/keyboard1_selected.png");
    keyboard2[0] = IMG_Load("Assets/graphic/controllers/keyboard2_0.png");
    keyboard2[1] = IMG_Load("Assets/graphic/controllers/keyboard2hover.png");
    keyboard2[2] = IMG_Load("Assets/graphic/controllers/keyboard2_selected.png");
   // table = IMG_Load("Assets/graphic/controllers/table.png");
    back[0] = IMG_Load("Assets/graphic/controllers/backnormal.png");
    back[1] = IMG_Load("Assets/graphic/controllers/backhover.png");

   /* //controllersBg = IMG_Load("Assets/graphic/controllers/controllersBg.jpg");
    keyboard[0] = IMG_Load("Assets/graphic/controllers/keyboard_active.png");
    keyboard[1] = IMG_Load("Assets/graphic/controllers/keyboard_active.png");
    keyboard[2] = IMG_Load("Assets/graphic/controllers/keyboard_active.png");
    keyboard2[0] = IMG_Load("Assets/graphic/controllers/keyboard2_disable.png");
    keyboard2[1] = IMG_Load("Assets/graphic/controllers/keyboard2_disable.png");
    keyboard2[2] = IMG_Load("Assets/graphic/controllers/keyboard2_disable.png");
    //tablefr = IMG_Load("Assets/graphic/controllers/table.png");
    backfr[0] = IMG_Load("Assets/graphic/controllers/back_normal.png");
    backfr[1] = IMG_Load("Assets/graphic/controllers/back_hover.png");
*/
    //declare the event var
    SDL_Event event;
    while (done)
    {
        if(english ==0)
        {
        SDL_BlitSurface(controllersBg, NULL, screen, &pos);
        SDL_BlitSurface(keyboard[keyboardIndex], NULL, screen, &pos);
        SDL_BlitSurface(keyboard2[keyboard2Index], NULL, screen, &pos);
      //  SDL_BlitSurface(table, NULL, screen, &pos);
        SDL_BlitSurface(back[backIndex], NULL, screen, &pos);
        }
        else if(english == 1)
        {
        SDL_BlitSurface(controllersBg, NULL, screen, &pos);
        SDL_BlitSurface(keyboardfr[keyboardIndex], NULL, screen, &pos);
        SDL_BlitSurface(keyboard2fr[keyboard2Index], NULL, screen, &pos);
        //SDL_BlitSurface(tablefr, NULL, screen, &pos);
        SDL_BlitSurface(backfr[backIndex], NULL, screen, &pos);
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
                    case SDLK_a:
                    getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                    SaveInput(Player1_Jump,"a" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                    break;
                case SDLK_ESCAPE:
                    done = 0;

                    break;
                case SDLK_DOWN:
                    if (backIndex == 0 && keyboardIndex == 0 && keyboard2Index == 0)
                    {
                        keyboardIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (backIndex == 0 && keyboardIndex == 1 && keyboard2Index == 0)
                    {
                        keyboardIndex = 0;
                        keyboard2Index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (backIndex == 0 && keyboardIndex == 0 && keyboard2Index == 1)
                    {
                        backIndex = 1;
                        keyboard2Index = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (backIndex == 1 && keyboardIndex == 0 && keyboard2Index == 0)
                    {
                        backIndex = 0;
                        keyboardIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;

                case SDLK_UP:
                    if (backIndex == 0 && keyboardIndex == 0 && keyboard2Index == 0)
                    {
                        keyboardIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (backIndex == 0 && keyboardIndex == 1 && keyboard2Index == 0)
                    {
                        keyboardIndex = 0;
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (backIndex == 1 && keyboardIndex == 0 && keyboard2Index == 0)
                    {
                        backIndex = 0;
                        keyboard2Index = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (backIndex == 0 && keyboardIndex == 0 && keyboard2Index == 1)
                    {
                        keyboard2Index = 0;
                        keyboardIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;
                    
                case SDLK_RETURN:
                    if (backIndex == 1)
                    {
                        done = 0;
                    }
                    else if(keyboardIndex == 1)
                    {
                        if(english ==0)
                        {
                            SDL_BlitSurface(keyboard[2], NULL, screen, &pos);
                        }
                        else if(english ==1)
                        {
                            SDL_BlitSurface(keyboardfr[2], NULL, screen, &pos);
                        }
                        SDL_Delay(200);
                        ControllersScreenTable(screen ,1);
                    }
                    else if(keyboard2Index == 1)
                    {
                        if(english ==0)
                        {
                            SDL_BlitSurface(keyboard2[2], NULL, screen, &pos);
                        }
                        else if(english ==1)
                        {
                            SDL_BlitSurface(keyboard2fr[2], NULL, screen, &pos);
                        }
                        SDL_Delay(200);
                        ControllersScreenTable(screen ,2);
                    }
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                backIndex = 0;

                if (event.motion.x > 40 && event.motion.y > 480 && event.motion.x < 201 && event.motion.y < 544)
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
    SDL_FreeSurface(controllersBg);
    SDL_FreeSurface(keyboard);
    SDL_FreeSurface(keyboard2);
    SDL_FreeSurface(table);
}

//----------------------------------------------ControllersScreenTable-----------------------------------------------------
void ControllersScreenTable(SDL_Surface *screen , int Player )
{
    
    char Player1_Jump[10] , Player1_MouveR[10] , Player1_MouveL[10] , Player1_Run[10] , Player1_Attack[10];
    char Player2_Jump[10] , Player2_MouveR[10] , Player2_MouveL[10] , Player2_Run[10] , Player2_Attack[10];

    int english, done = 1;
    int jumpHover = 0, mouveRHover = 0, mouveLHover = 0, runHover = 0 ,attackHover =0;
    getlanguage(&english);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Lunatics", NULL); //window title

    //initialise audio
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

    //declare and set music
    Mix_Music *music;
    music = Mix_LoadMUS("Assets/graphic/MainMenu/ost.mp3");

    //declare and set the hover sound effect
    Mix_Chunk *hoverSound;
    hoverSound = Mix_LoadWAV("Assets/graphic/settings/click.wav");

    //get the music volume from the file
    /* getVolume(&musicVol);

    volBarIndex = musicVol / 20;*/

    //set the music volume andplay it
    //  Mix_VolumeMusic(musicVol);
    Mix_PlayMusic(music, -1);

    hoverSound = Mix_LoadWAV("Assets/graphic/settings/click.wav");

    SDL_Surface *bg, *BACKGROUND, *jump[2], *mouveR[2], *mouveL[2], *run[2] , *attack[2];
    SDL_Surface *bgfr, *BACKGROUND_FR, *jump_FR[2], *mouveR_FR[2], *mouveL_FR[2], *run_FR[2] ,*attack_fr[2];
    bg = IMG_Load("Assets/graphic/controllers/controllersBg.jpg");
    BACKGROUND = IMG_Load("Assets/graphic/controllers/controllers0.png");
    jump[0] = IMG_Load("Assets/graphic/controllers/jumpnormal.png");
    jump[1] = IMG_Load("Assets/graphic/controllers/jumphover.png");
    mouveR[0] = IMG_Load("Assets/graphic/controllers/rightnormal.png");
    mouveR[1] = IMG_Load("Assets/graphic/controllers/right-hover.png");
    mouveL[0] = IMG_Load("Assets/graphic/controllers/leftnormal.png");
    mouveL[1] = IMG_Load("Assets/graphic/controllers/lefthover.png");
    run[0] = IMG_Load("Assets/graphic/controllers/runnormal.png");
    run[1] = IMG_Load("Assets/graphic/controllers/runhover.png");
    attack[0] = IMG_Load("Assets/graphic/controllers/attacknormal.png");
    attack[1] = IMG_Load("Assets/graphic/controllers/attackhover.png");
/*
BACKGROUND = IMG_Load("Assets/graphic/controllers/controllers0.png");
    BACKGROUND_FR = IMG_Load("Assets/graphic/controllers/bg.jpg");
    jump_FR[0] = IMG_Load("Assets/graphic/controllers/resumefr0.png");
    jump_FR[1] = IMG_Load("Assets/graphic/controllers/resumefr1.png");
    mouveR_FR[0] = IMG_Load("Assets/graphic/controllers/savefr0.png");
    mouveR_FR[1] = IMG_Load("Assets/graphic/controllers/savefr1.png");
    mouveL_FR[0] = IMG_Load("Assets/graphic/controllers/parametre0.png");
    mouveL_FR[1] = IMG_Load("Assets/graphic/controllers/parametre1.png");
    run_FR[0] = IMG_Load("Assets/graphic/controllers/quitter0.png");
    run_FR[1] = IMG_Load("Assets/graphic/controllers/quitter1.png");
    attack_fr[0] = IMG_Load("Assets/graphic/controllers/quitter0.png");
    attack_fr[1] = IMG_Load("Assets/graphic/controllers/quitter1.png");
*/
    SDL_Rect pos;

    pos.x = 0;
    pos.y = 0;
    SDL_Event event;

    while (done)
    {
        if (english == 0)
        {
          //  SDL_BlitSurface(bg, NULL, screen, &pos);        
            SDL_BlitSurface(BACKGROUND, NULL, screen, &pos);
            SDL_BlitSurface(jump[jumpHover], NULL, screen, &pos);
            SDL_BlitSurface(mouveR[mouveRHover], NULL, screen, &pos);
            SDL_BlitSurface(mouveL[mouveLHover], NULL, screen, &pos);
            SDL_BlitSurface(run[runHover], NULL, screen, &pos);
            SDL_BlitSurface(attack[attackHover], NULL, screen, &pos);
        }
        else if (english == 1)
        {
            SDL_BlitSurface(BACKGROUND_FR, NULL, screen, &pos);
            SDL_BlitSurface(jump_FR[jumpHover], NULL, screen, &pos);
            SDL_BlitSurface(mouveR_FR[mouveRHover], NULL, screen, &pos);
            SDL_BlitSurface(mouveL_FR[mouveLHover], NULL, screen, &pos);
            SDL_BlitSurface(run_FR[runHover], NULL, screen, &pos);
            SDL_BlitSurface(attack_fr[runHover], NULL, screen, &pos);
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
                   // done = 0;
                    controllersScreen(screen);
                    break;

                case SDLK_UP:
                    if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 0 && runHover == 0 && attackHover == 0)
                    {
                        jumpHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 1 && mouveRHover == 0 && mouveLHover == 0 && runHover == 0 && attackHover == 0)
                    {
                        jumpHover = 0;
                        attackHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 0 && runHover == 0 && attackHover == 1)
                    {
                        runHover = 1;
                        attackHover = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 0 && runHover == 1 && attackHover == 0)
                    {
                        runHover = 0;
                        mouveLHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 1 && runHover == 0 && attackHover == 0)
                    {
                        mouveLHover = 0;
                        mouveRHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 1 && mouveLHover == 0 && runHover == 0 && attackHover == 0)
                    {
                        mouveRHover = 0;
                        jumpHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }


                    break;

                case SDLK_DOWN:
                    if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 0 && runHover == 0 && attackHover == 0)
                    {
                        jumpHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 1 && mouveRHover == 0 && mouveLHover == 0 && runHover == 0 && attackHover == 0)
                    {
                        jumpHover = 0;
                        mouveRHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 1 && mouveLHover == 0 && runHover == 0 && attackHover == 0)
                    {
                        mouveLHover = 1;
                        mouveRHover = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 1 && runHover == 0 && attackHover == 0)
                    {
                        mouveLHover = 0;
                        runHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 0 && runHover == 1 && attackHover == 0)
                    {
                        runHover = 0;
                        attackHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (jumpHover == 0 && mouveRHover == 0 && mouveLHover == 0 && runHover == 0 && attackHover == 1)
                    {
                        jumpHover = 1;
                        attackHover = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }

                    break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------saveInput------------------------------------------------
                     case SDLK_a:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("a",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("a",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"a" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"a" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"a" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"a" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"a" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"a" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"a" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"a" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;
                     
                     case SDLK_z:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("z",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("z",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"z" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"z" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"z" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"z" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"z" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"z" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"z" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"z" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_e:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("e",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("e",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"e" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"e" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"e" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"e" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"e" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"e" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"e" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"e" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;
                     
                     case SDLK_r:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("r",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("r",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"r" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"r" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"r" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"r" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"r" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"r" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"r" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"r" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_t:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("t",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("t",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"t" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"t" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"t" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"t" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"t" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"t" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"t" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"t" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_y:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("y",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("y",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"y" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"y" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"y" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"y" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"y" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"y" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"y" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"y" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_u:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("u",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("u",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"u" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"u" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"u" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"u" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"u" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"u" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"u" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"u" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_i:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("i",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("i",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"i" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"i" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"i" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"i" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"i" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"i" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"i" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"i" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_o:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("o",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("o",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"o" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"o" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"o" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"o" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"o" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"o" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"o" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"o" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_p:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("p",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("p",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"p" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"p" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"p" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"p" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"p" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"p" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"p" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"p" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_q:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("q",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("q",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"q" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"q" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"q" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"q" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"q" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"q" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"q" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"q" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_s:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("s",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("s",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"s" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"s" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"s" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"s" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"s" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"s" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"s" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"s" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_d:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("s",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("s",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"s" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"s" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"s" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"s" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"s" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"s" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"s" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"s" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_f:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("f",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("f",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"f" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"f" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"f" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"f" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"f" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"f" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"f" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"f" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_g:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("g",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("g",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"g" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"g" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"g" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"g" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"g" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"g" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"g" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"g" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_h:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("h",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("h",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"h" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"h" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"h" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"h" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"h" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"h" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"h" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"h" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_j:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("j",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("j",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"j" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"j" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"j" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"j" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"j" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"j" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"j" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"j" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_k:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("k",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("k",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"k" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"k" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"k" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"k" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"k" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"k" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"k" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"k" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_l:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("l",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("l",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"l" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"l" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"l" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"l" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"l" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"l" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"l" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"l" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_m:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("m",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("m",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"m" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"m" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"m" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"m" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"m" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"m" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"m" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"m" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_w:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("w",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("w",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"w" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"w" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"w" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"w" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"w" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"w" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"w" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"w" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_x:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("x",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("x",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"x" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"x" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"x" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"x" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"x" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"x" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"x" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"x" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_c:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("c",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("c",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"c" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"c" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"c" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"c" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"c" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"c" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"c" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"c" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_v:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("v",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("v",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"v" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"v" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"v" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"v" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"v" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"v" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"v" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"v" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_b:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("b",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("b",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"b" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"b" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"b" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"b" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"b" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"b" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"b" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"b" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_n:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("n",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("n",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"n" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"n" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"n" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"n" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"n" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"n" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"n" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"n" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP0:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP0",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP0",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP0" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP0" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP0" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP0" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP0" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP0" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP0" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP0" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP1:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP1",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP1",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP1" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP1" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP1" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP1" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP1" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP1" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP1" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP1" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP2:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP2",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP2",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP2" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP2" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP2" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP2" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP2" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP2" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP2" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP2" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP3:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP3",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP3",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP3" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP3" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP3" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP3" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP3" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP3" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP3" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP3" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP4:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP4",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP4",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP4" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP4" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP4" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP4" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP4" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP4" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP4" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP4" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP5:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP5",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP5",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP5" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP5" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP5" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP5" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP5" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP5" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP5" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP5" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP6:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP6",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP6",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP6" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP6" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP6" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP6" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP6" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP6" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP6" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP6" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP7:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP7",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP7",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP7" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP7" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP7" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP7" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP7" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP7" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP7" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP7" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP8:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP8",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP8",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP8" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP8" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP8" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP8" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP8" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP8" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP8" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP8" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP9:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP9",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP9",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP9" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP9" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP9" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP9" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP9" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP9" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP9" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP9" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP_PERIOD:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP_PERIOD",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP_PERIOD",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP_PERIOD" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP_PERIOD" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP_PERIOD" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP_PERIOD" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP_PERIOD" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP_PERIOD" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP_PERIOD" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP_PERIOD" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP_ENTER:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP_ENTER",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP_ENTER",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP_ENTER" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP_ENTER" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP_ENTER" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP_ENTER" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP_ENTER" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP_ENTER" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP_ENTER" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP_ENTER" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP_PLUS:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP_PLUS",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP_PLUS",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP_PLUS" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP_PLUS" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP_PLUS" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP_PLUS" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP_PLUS" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP_PLUS" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP_PLUS" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP_PLUS" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP_MINUS:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP_MINUS",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP_MINUS",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP_MINUS" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP_MINUS" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP_MINUS" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP_MINUS" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP_MINUS" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP_MINUS" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP_MINUS" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP_MINUS" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP_MULTIPLY:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP_MULTIPLY",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP_MULTIPLY",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP_MULTIPLY" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP_MULTIPLY" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP_MULTIPLY" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP_MULTIPLY" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP_MULTIPLY" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP_MULTIPLY" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP_MULTIPLY" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP_MULTIPLY" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_KP_DIVIDE:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("KP_DIVIDE",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("KP_DIVIDE",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"KP_DIVIDE" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"KP_DIVIDE" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"KP_DIVIDE" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"KP_DIVIDE" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"KP_DIVIDE" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"KP_DIVIDE" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"KP_DIVIDE" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"KP_DIVIDE" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_SPACE:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("SPACE",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("SPACE",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"SPACE" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"SPACE" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"SPACE" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"SPACE" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"SPACE" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"SPACE" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"SPACE" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"SPACE" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_RIGHT:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("RIGHT",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("RIGHT",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"RIGHT" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"RIGHT" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"RIGHT" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"RIGHT" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"RIGHT" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"RIGHT" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"RIGHT" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"RIGHT" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_LEFT:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("LEFT",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("LEFT",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"LEFT" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"LEFT" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"LEFT" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"LEFT" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"LEFT" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"LEFT" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"LEFT" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"LEFT" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;


                     case SDLK_LSHIFT:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("LSHIFT",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("LSHIFT",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"LSHIFT" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"LSHIFT" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"LSHIFT" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"LSHIFT" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"LSHIFT" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"LSHIFT" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"LSHIFT" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"LSHIFT" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;

                     case SDLK_LCTRL:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("LCTRL",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("LCTRL",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"LCTRL" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"LCTRL" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"LCTRL" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"LCTRL" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"LCTRL" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"LCTRL" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"LCTRL" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"LCTRL" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;
/*
                     case SDLK_LALT:
                     if(jumpHover == 1)
                     {

                         if(Player==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput("LALT",Player1_MouveR ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput("LALT",Player2_MouveR ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                     }
                     else if(mouveRHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,"LALT" ,Player1_MouveL ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,"LALT" ,Player2_MouveL ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     else if(mouveLHover==1)
                     {
                         if(Player == 1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,"LALT" ,Player1_Run ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player == 2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,"LALT" ,Player2_Run ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }
         
                     }
                     else if(runHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,"LALT" ,Player1_Attack ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,"LALT" ,Player2_Attack ,"Fichier/SaveInput2.txt");
                         }

                     }
                     else if(attackHover==1)
                     {
                         if(Player ==1)
                         {
                         getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
                         SaveInput(Player1_Jump,Player1_MouveR ,Player1_MouveL ,Player1_Run ,"LALT" ,"Fichier/SaveInput.txt");
                         }
                         else if(Player ==2)
                         {
                         getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");
                         SaveInput(Player2_Jump,Player2_MouveR ,Player2_MouveL ,Player2_Run ,"LALT" ,"Fichier/SaveInput2.txt");
                         }
                         
                     }
                     break;*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
                
                }
            }
        }
    
    

    //----------------------------------Afficher les inputs dans le tableau----------------------------------- 
    getInput(&Player1_Jump, &Player1_MouveR , &Player1_MouveL , &Player1_Run , &Player1_Attack , "Fichier/SaveInput.txt");
    //getInput(&Player2_Jump, &Player2_MouveR , &Player2_MouveL , &Player2_Run , &Player2_Attack , "Fichier/SaveInput2.txt");

    TTF_Init();
    SDL_Surface *Player1_Jump_text = NULL ,*Player1_MouveR_text = NULL ,*Player1_MouveL_text = NULL ,*Player1_Run_text = NULL ,*Player1_Attack_text = NULL;
    SDL_Rect Player1_Jump_textPos ,Player1_MouveR_textPos  ,Player1_MouveL_textPos ,Player1_Run_textPos ,Player1_Attack_textPos;

    Player1_Jump_textPos.x = 800;
    Player1_Jump_textPos.y = 250;

    Player1_MouveR_textPos.x = 800;
    Player1_MouveR_textPos.y = 330;

    Player1_MouveL_textPos.x = 800;
    Player1_MouveL_textPos.y = 400;

    Player1_Run_textPos.x = 800;
    Player1_Run_textPos.y = 500;

    Player1_Attack_textPos.x = 800;
    Player1_Attack_textPos.y = 580;

    SDL_Surface *Player2_Jump_text = NULL ,*Player2_MouveR_text = NULL ,*Player2_MouveL_text = NULL ,*Player2_Run_text = NULL ,*Player2_Attack_text = NULL;
    SDL_Rect Player2_Jump_textPos ,Player2_MouveR_textPos ,Player2_MouveL_textPos ,Player2_Run_textPos ,Player2_Attack_textPos;
    
    Player2_Jump_textPos.x = 700;
    Player2_Jump_textPos.y = 50;

    Player2_MouveR_textPos.x = 700;
    Player2_MouveR_textPos.y = 100;

    Player2_MouveL_textPos.x = 700;
    Player2_MouveL_textPos.y = 150;

    Player2_Run_textPos.x = 700;
    Player2_Run_textPos.y = 200;

    Player2_Attack_textPos.x = 700;
    Player2_Attack_textPos.y = 250;

    TTF_Font *police;
    police =  TTF_OpenFont("Assets/fonts/DelaGothicOne-Regular.ttf", 25);
    SDL_Color white = {255, 255, 255};
    
    
    Player1_Jump_text = TTF_RenderText_Blended(police, Player1_Jump, white);
    Player1_MouveR_text = TTF_RenderText_Blended(police, Player1_MouveR, white);
    Player1_MouveL_text = TTF_RenderText_Blended(police, Player1_MouveL, white);
    Player1_Run_text = TTF_RenderText_Blended(police, Player1_Run, white);
    Player1_Attack_text = TTF_RenderText_Blended(police, Player1_Attack, white);

    Player2_Jump_text = TTF_RenderText_Blended(police, Player2_Jump, white);
    Player2_MouveR_text = TTF_RenderText_Blended(police, Player2_MouveR, white);
    Player2_MouveL_text = TTF_RenderText_Blended(police, Player2_MouveL, white);
    Player2_Run_text = TTF_RenderText_Blended(police, Player2_Run, white);
    Player2_Attack_text = TTF_RenderText_Blended(police, Player2_Attack, white);

    if(Player == 1)
    {
       SDL_BlitSurface(bg, NULL, screen, &pos);
        SDL_BlitSurface(Player1_Jump_text, NULL, screen, &Player1_Jump_textPos);
        SDL_BlitSurface(Player1_MouveR_text, NULL, screen, &Player1_MouveR_textPos);
        SDL_BlitSurface(Player1_MouveL_text, NULL, screen, &Player1_MouveL_textPos);
        SDL_BlitSurface(Player1_Run_text, NULL, screen, &Player1_Run_textPos);
        SDL_BlitSurface(Player1_Attack_text, NULL, screen, &Player1_Attack_textPos);
    }
    else if(Player == 2)
    {
        SDL_BlitSurface(Player2_Jump_text, NULL, screen, &Player2_Jump_textPos);
        SDL_BlitSurface(Player2_MouveR_text, NULL, screen, &Player2_MouveR_textPos);
        SDL_BlitSurface(Player2_MouveL_text, NULL, screen, &Player2_MouveL_textPos);
        SDL_BlitSurface(Player2_Run_text, NULL, screen, &Player2_Run_textPos);
        SDL_BlitSurface(Player2_Attack_text, NULL, screen, &Player2_Attack_textPos);
    }



  }
  
    TTF_Quit();

    SDL_FreeSurface(screen);
    SDL_Quit();
}

//----------------------SaveInput -----------------
void SaveInput( char jump[] ,char mouveR[] ,char mouveL[] ,char run[] ,char attack[] ,char *nomfichier)
{
    FILE *fichier = NULL;
    fichier = fopen(nomfichier ,"w");
    fprintf(fichier,"%s %s %s %s %s",jump ,mouveR, mouveL ,run ,attack);
    fclose(fichier);

}//"Fichier/SaveInput.txt"

//--------------getInput----------------------------------
void getInput(char *jump ,char *mouveR ,char *mouveL ,char *run ,char *attack ,char *nomfichier)
{
    FILE *fichier = NULL;
    fichier = fopen(nomfichier, "r");
    while (!feof(fichier))
    {
    fscanf(fichier, "%s %s %s %s %s" ,jump ,mouveR, mouveL ,run ,attack);
    //fscanf(fichier,"%d",heropos->x);
    }
    fclose(fichier);

}

