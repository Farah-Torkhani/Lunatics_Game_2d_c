#include "Headers/headers.h"
#include "Headers/settings.h"
void displaySettingMenu(SDL_Surface *screen, int *action)
{
    //simple variable
    int loopCondition = 1, muteCondition = 0, mute=0, volume=100;
    
    //declaration surfaces positions
    SDL_Surface *SettingsBg = NULL, *textvolume =NULL,*right_black=NULL,*right_oran=NULL ,*left_black=NULL,*left_oran=NULL ,*textkeyboard=NULL,*textlanguage=NULL,*vol0, *TextMainSettings = NULL, *volup, *voldown, *TextResolution = NULL, *Textfull = NULL, *Textwind = NULL, *muteImg = NULL, *backImg = NULL;
    SDL_Rect SettingBgPos,textvolumePos, TextMainSettingsPos, volBarPos, volPlusPos, volMinusPos, ResolPos, fullPos, WindPos, mutePos, backPos;

    //declaration son
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_Music *bgMusic;
    Mix_Chunk *hoverSound;

    //set setting screen
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

    //set setting bg image
    SettingsBg = IMG_Load("Assets/graphic/Settings/bg.jpg");

    //set mute button image
    muteImg = IMG_Load("Assets/graphic/MainMenu/musicOff1.png");

    //set setting volume images
    vol0 = IMG_Load("Assets/graphic/Settings/volume/vol_5.png");
    vol0 = IMG_Load("Assets/graphic/Settings/volume/vol_5.png");
    volup = IMG_Load("Assets/graphic/Settings/volume/+.png");
    //voldown = IMG_Load("Assets/graphic/Settings/volume/-.png");

    //set bouttons text
    textvolume= IMG_Load("Assets/graphic/Settings/button_volume.png");
    textkeyboard= IMG_Load("Assets/graphic/Settings/button_keyboard.png");
    textlanguage= IMG_Load("Assets/graphic/Settings/button_language.png");
    //set back button img
    backImg = IMG_Load("Assets/graphic/Settings/buton_back.png");

    //set Resolution images
    TextResolution = IMG_Load("Assets/graphic/Settings/button_resolution.png");
    right_black= IMG_Load("Assets/graphic/Settings/right_black.png");
    right_oran= IMG_Load("Assets/graphic/Settings/resolution_right.png");
    left_black= IMG_Load("Assets/graphic/Settings/left_black.png");
    left_oran= IMG_Load("Assets/graphic/Settings/resolution_left.png");
    Textwind = IMG_Load("Assets/graphic/Settings/resolution_1.png");
    Textfull = IMG_Load("Assets/graphic/Settings/resolution_2.png");

    //set setting elements positions
    volBarPos.x = 710;
    volBarPos.y = 215;

    textvolumePos.x = 0;
    textvolumePos.y = 0;

    volPlusPos.x = 842;
    volPlusPos.y = 310;

    volMinusPos.x = 0;
    volMinusPos.y = 0;

    ResolPos.x = 0;
    ResolPos.y = 0;

    WindPos.x = 550;
    WindPos.y = 190;

    fullPos.x = 750;
    fullPos.y = 190;

    mutePos.x = 500;
    mutePos.y = 500;

    TextMainSettingsPos.x = 575;
    TextMainSettingsPos.y = 30;

    SettingBgPos.x = 0;
    SettingBgPos.y = 0;

    backPos.x = 10;
    backPos.y = 10;

    //blint all settings elements
    SDL_BlitSurface(SettingsBg, NULL, screen, &SettingBgPos);
    //SDL_BlitSurface(TextMainSettings, NULL, screen, &TextMainSettingsPos);

    SDL_BlitSurface(backImg, NULL, screen, &backPos);
    SDL_BlitSurface(vol0, NULL, screen, &volBarPos);
    SDL_BlitSurface(textvolume,NULL, screen, &textvolumePos);
    SDL_BlitSurface(textkeyboard,NULL, screen, &textvolumePos);
    SDL_BlitSurface(textlanguage,NULL, screen, &textvolumePos);
    SDL_BlitSurface(volup, NULL, screen, &volPlusPos);
    SDL_BlitSurface(voldown, NULL, screen, &volMinusPos);
    SDL_BlitSurface(TextResolution, NULL, screen, &ResolPos);
    SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
    //SDL_BlitSurface(Textfull, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
   // SDL_BlitSurface(right_oran, NULL, screen, &SettingBgPos);
    //SDL_BlitSurface(left_oran, NULL, screen, &SettingBgPos);
   
    SDL_BlitSurface(muteImg, NULL, screen, &mutePos);
   
   
    //event declaration
    SDL_Event event;

    //Settings Menu loup
    while (loopCondition)
    {
        SDL_WaitEvent(&event);
        
        switch (event.type)
        {
        case SDL_QUIT:
            loopCondition = 0;
            break;

        case SDL_KEYDOWN:

            if (event.key.keysym.sym == SDLK_ESCAPE)
                loopCondition = 0;

            if (event.key.keysym.sym == SDLK_m)
            {
                if (muteCondition == 0)
                {
                    muteCondition = 1;
                    Mix_VolumeMusic(0);
                    Mix_VolumeChunk(hoverSound, 0);
                    SDL_Delay(100);
                }
                else
                {
                    muteCondition = 0;
                    Mix_VolumeMusic(100);
                    Mix_VolumeChunk(hoverSound, 100);
                    SDL_Delay(100);
                }
            }

            break;
        case SDL_MOUSEMOTION:
           
            if (event.motion.x > 910 && event.motion.y > 360 && event.motion.x < 955 && event.motion.y < 407)
                {
                    
                    SDL_BlitSurface(right_oran, NULL, screen, &SettingBgPos);
                }
             else
             {
                 SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
             }   
            if (event.motion.x > 680 && event.motion.y > 360 && event.motion.x < 720 && event.motion.y < 407)
                {
                   
                    SDL_BlitSurface(left_oran, NULL, screen, &SettingBgPos);
                }
                else{
                    SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                }
                break;
        case SDL_MOUSEBUTTONDOWN:
            
            //Return Click-------------------
            if (event.button.x > 10 && event.button.y > 10 && event.button.x < 100 && event.button.y < 60)
            {
                //SDL_free(MainMenuScreen);
                //SDL_FreeSurface(SettingsBg);
                //SDL_FreeSurface(screen);
                //SDL_Delay(200);
               // loopCondition = 0;

                mainMenu(screen, &action);
            }

            //Mute Click-------------------

            if (event.button.x > 510 && event.button.y > 275 && event.button.x < 776 && event.button.y < 360)
			{
			if(mute == 0)
			{
			mute=1;
			Mix_VolumeMusic(0); 
			SDL_Delay(100);
			}
			else
			{
			mute =0;
			Mix_VolumeMusic(100);
			SDL_Delay(100);
			}
			}

            //VolUp  Click-------------------

            if ((event.button.x > 842&& event.button.y > 310 && event.button.x < 878 && event.button.y < 338)&& (volume<=100))        {
                         volume+=20;
                          volBarPos.x = 710;
                          volBarPos.y = 215;
                        if(volume==20)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_1.png");
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos); 
                         Mix_VolumeMusic(20);
                         
                                   
                        }
                         else if(volume==40)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_2.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);   
                         Mix_VolumeMusic(40); 
                       
                                 
                        }
                       else if(volume==60)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_3.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos); 
                         Mix_VolumeMusic(60);
                        
                                    
                        }
                        else if(volume==80)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_4.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);  
                         Mix_VolumeMusic(80);                                  
                        }
                       else if(volume==100)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_5.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);
                         Mix_VolumeMusic(100);                                    
                        }
                     }

                        //VolDown Click-------------------

                        if ((event.button.x > 750 && event.button.y > 310 && event.button.x < 836 && event.button.y < 338)&& (volume>=0))
                     {
                         volume-=20;
                          volBarPos.x = 710;
                          volBarPos.y = 215;
                        if(volume==20)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_1.png");
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos); 
                         Mix_VolumeMusic(20);                                    
                        }
                       else if(volume==40)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_2.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);  
                         Mix_VolumeMusic(40);                                   
                        }
                       else if(volume==60)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_3.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);  
                         Mix_VolumeMusic(60);                                   
                        }
                        else if(volume==80)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/vol_4.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);
                         Mix_VolumeMusic(80);                                    
                        }
                       else if(volume==0)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/volume/Vol_0.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);
                         Mix_VolumeMusic(0);                                    
                        }
                     }
                     int full=0;
                     // full screen---------- attention à verefier
                     
                     if ((event.button.x > 910 && event.button.y > 360 && event.button.x < 955 && event.button.y < 407)&&(full==0))               		    
                        {
                        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_FULLSCREEN |SDL_RESIZABLE);
                        SDL_Delay(100);
full=1;
                        }
                        if ((event.button.x > 680 && event.button.y > 360 && event.button.x < 720 && event.button.y < 407)&&(full==0) )              		    
                        {
                        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_FULLSCREEN |SDL_RESIZABLE);
                        SDL_Delay(100);
                        full=1;
                        }
                       
                     if ((event.button.x > 910 && event.button.y > 360 && event.button.x < 955 && event.button.y < 407) &&(full==1))  
                        {
                        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        SDL_Delay(100);
                        full=0;
                        }
                         
                     if ((event.button.x > 680 && event.button.y > 360 && event.button.x < 720 && event.button.y < 407) &&(full==1))  
                        {
                        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_RESIZABLE);
                        SDL_Delay(100);
                        full=0;
                        
                        }
                            //blint all settings elements
                            SDL_BlitSurface(SettingsBg, NULL, screen, &SettingBgPos);
                            //SDL_BlitSurface(TextMainSettings, NULL, screen, &TextMainSettingsPos);

                            SDL_BlitSurface(backImg, NULL, screen, &backPos);
                            SDL_BlitSurface(vol0, NULL, screen, &volBarPos);
                            SDL_BlitSurface(textvolume,NULL, screen, &textvolumePos);
                            SDL_BlitSurface(textkeyboard,NULL, screen, &textvolumePos);
                            SDL_BlitSurface(textlanguage,NULL, screen, &textvolumePos);
                            SDL_BlitSurface(volup, NULL, screen, &volPlusPos);
                            SDL_BlitSurface(voldown, NULL, screen, &volMinusPos);
                            SDL_BlitSurface(TextResolution, NULL, screen, &ResolPos);
                            SDL_BlitSurface(Textfull, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                       

    
   
            break;
        }
        SDL_Flip(screen);
    }

    //free memory
    SDL_FreeSurface(SettingsBg);
    SDL_FreeSurface(screen);
}