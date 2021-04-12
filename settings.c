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

void controllersScreen(SDL_Surface *screen)
{
    //declare simple variables
    int backIndex = 0, done = 1;

    //simple variable hover test
    int backHover = 1;

    //declare the select game mode images
    SDL_Surface *controllersBg, *keyboard, *joystick, *table, *back[2];

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

    keyboard = IMG_Load("Assets/graphic/controllers/keyboard_active.png");

    joystick = IMG_Load("Assets/graphic/controllers/joystick_disable.png");

    table = IMG_Load("Assets/graphic/controllers/table.png");

    back[0] = IMG_Load("Assets/graphic/controllers/back_normal.png");
    back[1] = IMG_Load("Assets/graphic/controllers/back_hover.png");

    //declare the event var
    SDL_Event event;
    while (done)
    {
        SDL_BlitSurface(controllersBg, NULL, screen, &pos);
        SDL_BlitSurface(keyboard, NULL, screen, &pos);
        SDL_BlitSurface(joystick, NULL, screen, &pos);
        SDL_BlitSurface(table, NULL, screen, &pos);
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
                    if (backIndex == 0)
                    {
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else
                    {
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;

                case SDLK_DOWN:
                    if (backIndex == 0)
                    {
                        backIndex = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else
                    {
                        backIndex = 0;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    break;
                case SDLK_RETURN:
                    if (backIndex == 1)
                    {
                        done = 0;
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
    SDL_FreeSurface(joystick);
    SDL_FreeSurface(table);
}

