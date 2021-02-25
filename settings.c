#include "Headers/headers.h"
#include "Headers/settings.h"
void displaySettingMenu(SDL_Surface *screen, int *action)
{
    //simple variable
    int loopCondition = 1, muteCondition = 0, mute=0, volume=100;
    int select=-1;
    //declaration surfaces positions
    SDL_Surface *testscreen, *SettingsBg = NULL, *textvolume =NULL,*right_black=NULL,*right_lan=NULL ,*left_black=NULL,*left_lan=NULL ,*textkeyboard=NULL,*textlanguage=NULL,*vol0, *TextMainSettings = NULL, *volup, *voldown, *TextResolution = NULL, *Textfull = NULL, *Textwind = NULL, *muteImg = NULL, *backImg = NULL,*english=NULL,*frensh=NULL;
    SDL_Rect SettingBgPos,textvolumePos, TextMainSettingsPos, volBarPos, volPlusPos, volMinusPos, ResolPos, fullPos, WindPos, mutePos, backPos;

    //declaration son
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_Music *bgMusic;
    Mix_Chunk *hoverSound;

    //set setting screen
    //screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

    //set setting bg image
    SettingsBg = IMG_Load("Assets/graphic/Settings/settingsMenuBg.jpg");


    //set setting volume images
    vol0 = IMG_Load("Assets/graphic/Settings/vol5.png");
    volup = IMG_Load("Assets/graphic/Settings/nextVol_normal.png");
    voldown = IMG_Load("Assets/graphic/Settings/prevVol_normal.png");

    //set bouttons text
    textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_normal.png");
    textkeyboard= IMG_Load("Assets/graphic/Settings/controllers_normal.png");
    textlanguage= IMG_Load("Assets/graphic/Settings/languageInput_normal.png");
    TextResolution = IMG_Load("Assets/graphic/Settings/resInput_normal.png");

    //set back button img
    backImg = IMG_Load("Assets/graphic/Settings/back_normal.png");

    //set Resolution images
    right_black= IMG_Load("Assets/graphic/Settings/nextRes_normal.png");
    left_black= IMG_Load("Assets/graphic/Settings/prevRes_normal.png");
    Textwind = IMG_Load("Assets/graphic/Settings/windowed.png");
    Textfull = IMG_Load("Assets/graphic/Settings/fulScreen.png");

    //set Language images
    english=IMG_Load("Assets/graphic/Settings/english.png");
    frensh=IMG_Load("Assets/graphic/Settings/frensh.png");
    right_lan=IMG_Load("Assets/graphic/Settings/nextLanguage_normal.png");
    left_lan=IMG_Load("Assets/graphic/Settings/prevLanguage_normal.png");
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

    SDL_BlitSurface(backImg, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(textvolume,NULL, screen, &SettingBgPos);
    SDL_BlitSurface(textkeyboard,NULL, screen, &SettingBgPos);
    SDL_BlitSurface(textlanguage,NULL, screen, &SettingBgPos);
    SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(TextResolution, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(english, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(right_lan, NULL, screen, &SettingBgPos);
    SDL_BlitSurface(left_lan, NULL, screen, &SettingBgPos);
   // SDL_BlitSurface(right_oran, NULL, screen, &SettingBgPos);
    //SDL_BlitSurface(left_oran, NULL, screen, &SettingBgPos);
   
   
   
   
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
           
            if ((event.key.keysym.sym == SDLK_DOWN)&&(select<=4))
            {
                select++;
                if(select==0)
                {
                        SDL_FreeSurface(backImg);
                         backImg= IMG_Load("Assets/graphic/Settings/back_normal.png");
                         SDL_BlitSurface(backImg,NULL,screen,&SettingBgPos); 
                        SDL_FreeSurface(textvolume);
                         textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_hover.png");
                         SDL_BlitSurface(textvolume,NULL,screen,&SettingBgPos); 
                         SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
                        SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                        SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
                }
                else if(select==1)
                {
                        SDL_FreeSurface(textvolume);
                         textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_normal.png");
                         SDL_BlitSurface(textvolume,NULL,screen,&SettingBgPos); 
                          SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
                        SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                        SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
                        SDL_FreeSurface(TextResolution);
                         TextResolution= IMG_Load("Assets/graphic/Settings/resInput_hover.png");
                         SDL_BlitSurface(TextResolution,NULL,screen,&SettingBgPos); 
                          SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                }
                else if(select==2)
                {
                     SDL_FreeSurface(TextResolution);
                         TextResolution= IMG_Load("Assets/graphic/Settings/resInput_normal.png");
                         SDL_BlitSurface(TextResolution,NULL,screen,&SettingBgPos);
                          SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                     SDL_FreeSurface(textlanguage);
                         textlanguage= IMG_Load("Assets/graphic/Settings/languageInput_hover.png");
                         SDL_BlitSurface(textlanguage,NULL,screen,&SettingBgPos); 
                          SDL_BlitSurface(english, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_lan, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_lan, NULL, screen, &SettingBgPos);
                    
                  } 
                else if(select==3)
                {
                    
                         SDL_FreeSurface(textlanguage);
                         textlanguage= IMG_Load("Assets/graphic/Settings/languageInput_normal.png");
                         SDL_BlitSurface(textlanguage,NULL,screen,&SettingBgPos); 
                          SDL_BlitSurface(english, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_lan, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_lan, NULL, screen, &SettingBgPos);
                        SDL_FreeSurface(textkeyboard);
                         textkeyboard= IMG_Load("Assets/graphic/Settings/controllers_hover.png");
                         SDL_BlitSurface(textkeyboard,NULL,screen,&SettingBgPos); 
                }
                
                 else if(select==4)
                {
                    SDL_FreeSurface(textkeyboard);
                         textkeyboard= IMG_Load("Assets/graphic/Settings/controllers_normal.png");
                         SDL_BlitSurface(textkeyboard,NULL,screen,&SettingBgPos); 
                        SDL_FreeSurface(backImg);
                         backImg= IMG_Load("Assets/graphic/Settings/back_hover.png");
                         SDL_BlitSurface(backImg,NULL,screen,&SettingBgPos); 
                }


            }
            if ((event.key.keysym.sym == SDLK_UP)&&(select>=0))
            {
                select--;
                if(select==0)
                {
                     SDL_FreeSurface(TextResolution);
                         TextResolution= IMG_Load("Assets/graphic/Settings/resInput_normal.png");
                         SDL_BlitSurface(TextResolution,NULL,screen,&SettingBgPos);
                        SDL_FreeSurface(textvolume);
                        SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                         textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_hover.png");
                         SDL_BlitSurface(textvolume,NULL,screen,&SettingBgPos); 
                         SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
                         
                }
                else if(select==1)
                {
                   
                         SDL_FreeSurface(textlanguage);
                         textlanguage= IMG_Load("Assets/graphic/Settings/languageInput_normal.png");
                         SDL_BlitSurface(textlanguage,NULL,screen,&SettingBgPos);
                         SDL_BlitSurface(english, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_lan, NULL, screen, &SettingBgPos);
                                SDL_BlitSurface(left_lan, NULL, screen, &SettingBgPos);
                    SDL_FreeSurface(TextResolution);
                         TextResolution= IMG_Load("Assets/graphic/Settings/resInput_hover.png");
                         SDL_BlitSurface(TextResolution,NULL,screen,&SettingBgPos); 
                         SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                }
                else if(select==2)
                {
                    SDL_FreeSurface(textkeyboard);
                         textkeyboard= IMG_Load("Assets/graphic/Settings/controllers_normal.png");
                         SDL_BlitSurface(textkeyboard,NULL,screen,&SettingBgPos); 
                     
                   
                          SDL_FreeSurface(textlanguage);
                         textlanguage= IMG_Load("Assets/graphic/Settings/languageInput_hover.png");
                         SDL_BlitSurface(textlanguage,NULL,screen,&SettingBgPos); 
                          SDL_BlitSurface(english, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_lan, NULL, screen, &SettingBgPos);
                                SDL_BlitSurface(left_lan, NULL, screen, &SettingBgPos);
                }
                else if(select==3)
                {
                    SDL_FreeSurface(backImg);
                         backImg= IMG_Load("Assets/graphic/Settings/back_normal.png");
                         SDL_BlitSurface(backImg,NULL,screen,&SettingBgPos); 
                        SDL_FreeSurface(textkeyboard);
                         textkeyboard= IMG_Load("Assets/graphic/Settings/controllers_hover.png");
                         SDL_BlitSurface(textkeyboard,NULL,screen,&SettingBgPos); 
                }
                else if(select==4)
                {
                    SDL_FreeSurface(textvolume);
                         textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_normal.png");
                         SDL_BlitSurface(textvolume,NULL,screen,&SettingBgPos);
                          SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos); 
                        SDL_FreeSurface(backImg);
                         backImg= IMG_Load("Assets/graphic/Settings/back_hover.png");
                         SDL_BlitSurface(backImg,NULL,screen,&SettingBgPos); 
                }

            }
if ((event.key.keysym.sym == SDLK_DOWN)&&(select==4))
{
select=-1;
}
if ((event.key.keysym.sym == SDLK_UP)&&(select==0))
{
select=5;
}

if(event.key.keysym.sym == SDLK_RETURN )
{
    if(select ==4)
    {
        mainMenu(screen,&action);
    }
    
}
            break;
        case SDL_MOUSEMOTION:
          if (event.motion.x > 350 && event.motion.y > 175 && event.motion.x < 929 && event.motion.y < 240)
                {
                     SDL_FreeSurface(textvolume);
                         textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_hover.png");
                         SDL_BlitSurface(textvolume,NULL,screen,&SettingBgPos); 
                         SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
                        SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                        SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
                        

                }
             else
             {
                        SDL_FreeSurface(textvolume);
                         textvolume= IMG_Load("Assets/graphic/Settings/VolumeInput_normal.png");
                         SDL_BlitSurface(textvolume,NULL,screen,&SettingBgPos);
                          SDL_BlitSurface(vol0, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
             }  
              
           
            if (event.motion.x > 557 && event.motion.y > 190 && event.motion.x < 585 && event.motion.y < 225)
                {
                    
                   SDL_FreeSurface(voldown);
                  voldown= IMG_Load("Assets/graphic/Settings/prevVol_hover.png");
                  SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
                }
                 else
             {
                  SDL_FreeSurface(voldown);
                  voldown= IMG_Load("Assets/graphic/Settings/prevVol_normal.png");
                  SDL_BlitSurface(voldown, NULL, screen, &SettingBgPos);
             }   
            if (event.motion.x > 875 && event.motion.y > 190 && event.motion.x < 900 && event.motion.y < 225)
                {
                   
                    SDL_FreeSurface(volup);
                  volup= IMG_Load("Assets/graphic/Settings/nextVol_hover.png");
                  SDL_BlitSurface(volup, NULL, screen, &SettingBgPos);
                }
                else{
                    SDL_FreeSurface(right_black);
                  right_black= IMG_Load("Assets/graphic/Settings/nextRes_normal.png");
                  SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                }
                if (event.motion.x > 350 && event.motion.y > 275 && event.motion.x < 929 && event.motion.y < 340)
                {
                     SDL_FreeSurface(TextResolution);
                         TextResolution= IMG_Load("Assets/graphic/Settings/resInput_hover.png");
                         SDL_BlitSurface(TextResolution,NULL,screen,&SettingBgPos); 
                          SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                }
                        

                
             else
             {
                       SDL_FreeSurface(TextResolution);
                         TextResolution= IMG_Load("Assets/graphic/Settings/resInput_normal.png");
                         SDL_BlitSurface(TextResolution,NULL,screen,&SettingBgPos);
                          SDL_BlitSurface(Textwind, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
             }  
              
           
            if (event.motion.x > 628 && event.motion.y > 290 && event.motion.x < 655 && event.motion.y < 325)
                {
                    
                   SDL_FreeSurface(left_black);
                  left_black= IMG_Load("Assets/graphic/Settings/prevRes_hover.png");
                  SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                }
             else
             {
                  SDL_FreeSurface(left_black);
                  left_black= IMG_Load("Assets/graphic/Settings/prevRes_normal.png");
                  SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
             }   
            if (event.motion.x > 872 && event.motion.y > 290 && event.motion.x < 900 && event.motion.y < 325)
                {
                   
                    SDL_FreeSurface(right_black);
                  right_black= IMG_Load("Assets/graphic/Settings/nextRes_hover.png");
                  SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                }
                else{
                    SDL_FreeSurface(right_black);
                  right_black= IMG_Load("Assets/graphic/Settings/nextRes_normal.png");
                  SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                }
                break;
        case SDL_MOUSEBUTTONDOWN:
            
            //Return Click-------------------
            if (event.button.x > 10 && event.button.y > 10 && event.button.x < 100 && event.button.y < 60)
            {
                mainMenu(screen, &action);
            }

           

            //VolUp  Click-------------------

            if ((event.button.x > 873&& event.button.y > 190 && event.button.x < 900 && event.button.y < 585)&& (volume<=100))        {
                         volume+=20;
                          volBarPos.x = 0;
                          volBarPos.y = 0;
                        if(volume==20)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol1.png");
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos); 
                         Mix_VolumeMusic(20);
                         
                                   
                        }
                         else if(volume==40)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol2.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);   
                         Mix_VolumeMusic(40); 
                       
                                 
                        }
                       else if(volume==60)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol3.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos); 
                         Mix_VolumeMusic(60);
                        
                                    
                        }
                        else if(volume==80)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol4.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);  
                         Mix_VolumeMusic(80);                                  
                        }
                       else if(volume==100)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol5.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);
                         Mix_VolumeMusic(100);                                    
                        }
                     }

                        //VolDown Click-------------------

                        if ((event.button.x > 557 && event.button.y > 190 && event.button.x < 585 && event.button.y < 225)&& (volume>=0))
                     {
                         volume-=20;
                          volBarPos.x = 0;
                          volBarPos.y = 0;
                        if(volume==20)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol1.png");
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos); 
                         Mix_VolumeMusic(20);                                    
                        }
                       else if(volume==40)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol2.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);  
                         Mix_VolumeMusic(40);                                   
                        }
                       else if(volume==60)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol3.png"); 
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);  
                         Mix_VolumeMusic(60);                                   
                        }
                        else if(volume==80)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol4.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);
                         Mix_VolumeMusic(80);                                    
                        }
                       else if(volume==0)
                        {
                            SDL_FreeSurface(vol0);
                         vol0= IMG_Load("Assets/graphic/Settings/vol0.png");  
                         SDL_BlitSurface(vol0,NULL,screen,&volBarPos);
                         Mix_VolumeMusic(0);                                    
                        }
                     }
                   
                     // full screen---------- attention à verefier
                     
                     if (event.button.x > 872 && event.button.y > 290 && event.button.x < 900 && event.button.y < 325)              		    
                        {
                            screen = SDL_SetVideoMode(1280, 720, 0,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_FULLSCREEN |SDL_RESIZABLE);

                        
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
                        }
                        if (event.button.x > 628 && event.button.y > 290 && event.button.x < 655 && event.button.y < 325)             		    
                        {
                           screen = SDL_SetVideoMode(1280, 720, 0,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_RESIZABLE);                       
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
                            SDL_BlitSurface(right_black, NULL, screen, &SettingBgPos);
                            SDL_BlitSurface(left_black, NULL, screen, &SettingBgPos);
                        }
                       
                   

                       

    
   
            break;
        }
        SDL_Flip(screen);
    }

    //free memory
    SDL_FreeSurface(SettingsBg);
    SDL_FreeSurface(screen);
}