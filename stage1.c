#include "Headers/headers.h"



void stage_1(SDL_Surface *screen)
{
    //declare simple variables
    int done = 1,run = 0 ;

    enemie f;
	
   //----------------------------------------------------------------------------------------------------------------------
    Hero hero;
    char direction[50];
    Uint32 dt, t_prev;

    //----------------------------------------------------------------------------------------------------------------------

        GameplayBg b;

    bool running=true;
	SDL_Event event;
    Input I;
    int next;
int i=0;
int act=1;

    initBg(&b);
	init_hero(&hero);
	inisialiser_enemie (&f);
    initialiser_input (&I);




SDL_EnableKeyRepeat(200,0);
while(running)
{
	        t_prev = SDL_GetTicks();

        if (hero.currentMode == 0 || hero.currentMode == 2 || hero.currentMode == 4 || hero.currentMode == 6)
        {
            strcpy(direction, "right");
        }
        else
        {
            strcpy(direction, "left");
        }

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
				SDL_Quit();
			running=false;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 0;
					// pause screen
                    break;

                case SDLK_SPACE:
                    I.jump = 1;
                    break;

                case SDLK_RIGHT:
                    I.right = 1;
                    hero.currentMode = 2;
                    break;

                case SDLK_LEFT:
                    I.left = 1;
                    hero.currentMode = 3;
                    break;

                case SDLK_x:
                    I.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 6;
                    }
                    else
                    {
                        hero.currentMode = 7;
                    }
                    break;
                case SDLK_w:
                pause(screen);
                break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    I.jump = 0;
                     hero.heroPos.y = Ground;
                    if (I.right == 1)
                    {
                        hero.currentMode = 2;
                    }
                    else if (I.left == 1)
                    {
                        hero.currentMode = 3;
                    }
                    else
                    {
                        if (strcmp(direction, "right") == 0)
                        {
                            hero.currentMode = 0;
                        }
                        else
                        {
                            hero.currentMode = 1;
                        }
                    }

                    break;

                case SDLK_RIGHT:
                    I.right = 0;
                    hero.currentMode = 0;
                    run = 0;
                    break;

                case SDLK_LEFT:
                    I.left = 0;
                    hero.currentMode = 1;
                    run = 0;
                    break;
                case SDLK_x:
                    I.attack = 0;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 0;
                    }
                    else
                    {
                        hero.currentMode = 1;
                    }
                    break;
                }
                break;
            }
            dt = SDL_GetTicks() - t_prev;
        }

afficher_background(screen, &b);
        //run left and right
        leftAndRightHeroMvtR(&hero, I, dt);
        

        //run left and right

        //jump movement
        jumpHeroMvt(&hero, I, &run);
        //jump movement

	
        idleAnimation(&hero);
        runAnimation(&hero);
        jumpAnimation(&hero, screen,run);
        attackAnimation(&hero, screen);
        scrolling_right(&b, hero.velocity, screen, I ,&hero ,&f);
        scrolling_left(&b, hero.velocity, screen, I ,&hero ,&f);
        afficher_Hero(&hero, screen);



		// pos ennemi
SDL_Rect relcoord={f.rect.x , f.rect.y};
//
SDL_Rect relcoord1={f.rect.x , f.rect.y , f.rect.h , f.rect.w};

/*


int collision=0;
collision = collision_BB(heropos ,relcoord1 );
if(collision == 1)
{
heropos.y+=10;
}
*/
 update_ennemi(&f , screen , hero.heroPos ,b );

//MoveEnnemi(&f);

afficher_enemie (&f,screen ,relcoord);







        SDL_Flip(screen);
        SDL_Delay(20);
 
}

}



void pause(SDL_Surface *screen)
{
    int *action=0;

     int english,done=1;
     int resInputHover = 0, savInputHover = 0, setInputHover = 0, quiInputHover = 0;
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

   


    SDL_Surface *BACKGROUND,*RESUMER_b[2],*SAVE_b[2],*SETTINGS_b[2],*QUITE_b[2];
    SDL_Surface *BACKGROUND_FR,*RESUMER_b_FR[2],*SAVE_b_FR[2],*SETTINGS_b_FR[2],*QUITE_b_FR[2];
    BACKGROUND    = IMG_Load("Assets/graphic/stages/bg.jpg");     
    RESUMER_b[0]  = IMG_Load("Assets/graphic/stages/resume0.png");
    RESUMER_b[1]  = IMG_Load("Assets/graphic/stages/resume1.png");
    SAVE_b[0]     = IMG_Load("Assets/graphic/stages/save0.png");
    SAVE_b[1]     = IMG_Load("Assets/graphic/stages/save1.png");
    SETTINGS_b[0] = IMG_Load("Assets/graphic/stages/settings0.png");
    SETTINGS_b[1] = IMG_Load("Assets/graphic/stages/settings1.png");
    QUITE_b[0]    = IMG_Load("Assets/graphic/stages/exit0.png");
    QUITE_b[1]    = IMG_Load("Assets/graphic/stages/exit1.png");

    BACKGROUND_FR    = IMG_Load("Assets/graphic/stages/bg.jpg");
    RESUMER_b_FR[0]  = IMG_Load("Assets/graphic/stages/resumefr0.png");
    RESUMER_b_FR[1]  = IMG_Load("Assets/graphic/stages/resumefr1.png");
    SAVE_b_FR[0]     = IMG_Load("Assets/graphic/stages/savefr0.png");
    SAVE_b_FR[1]     = IMG_Load("Assets/graphic/stages/savefr1.png");
    SETTINGS_b_FR[0] = IMG_Load("Assets/graphic/stages/parametre0.png");
    SETTINGS_b_FR[1] = IMG_Load("Assets/graphic/stages/parametre1.png");
    QUITE_b_FR[0]    = IMG_Load("Assets/graphic/stages/quitter0.png");
    QUITE_b_FR[1]    = IMG_Load("Assets/graphic/stages/quitter1.png");


SDL_Rect pos;

pos.x=0;
pos.y=0;
 SDL_Event event;

    while (done)
    {
        if(english == 0)
        {
            SDL_BlitSurface(BACKGROUND, NULL, screen, &pos);
            SDL_BlitSurface(RESUMER_b[resInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SAVE_b[savInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SETTINGS_b[setInputHover], NULL, screen, &pos);
            SDL_BlitSurface(QUITE_b[quiInputHover], NULL, screen, &pos);
        }
        else if( english == 1 )
        {
            SDL_BlitSurface(BACKGROUND_FR, NULL, screen, &pos);
            SDL_BlitSurface(RESUMER_b_FR[resInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SAVE_b_FR[savInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SETTINGS_b_FR[setInputHover], NULL, screen, &pos);
            SDL_BlitSurface(QUITE_b_FR[quiInputHover], NULL, screen, &pos);

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
                    if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0 )
                    {
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 1 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 0;
                        quiInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 1)
                    {
                        quiInputHover = 0;
                        savInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 1 && setInputHover == 0 && quiInputHover == 0)
                    {
                        savInputHover = 0;
                        setInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 1 && quiInputHover == 0)
                    {
                        setInputHover = 0;
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                   
                    break;

                case SDLK_DOWN:
                    if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 1 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
                    {
                        resInputHover = 0;
                        setInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 1 && quiInputHover == 0)
                    {
                        setInputHover = 0;
                        savInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 1 && setInputHover == 0 && quiInputHover == 0)
                    {
                        savInputHover = 0;
                        quiInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                    else if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 1)
                    {
                        quiInputHover = 0;
                        resInputHover = 1;
                        Mix_PlayChannel(1, hoverSound, 0);
                    }
                
                    break;
                    case SDLK_RETURN:
                     if(resInputHover==1)
                    {
                     stage_1(screen);
                    }
                    else if(setInputHover==1)
                    {
                        settingsMenu(screen);
                    }
                     else if(quiInputHover==1)
                    {
                        mainMenu(screen,&action);
                    }
                    break;
                }
                }
        }       
    }

    SDL_FreeSurface(screen);
    SDL_Quit();
}
































/*
if (I.right==1)
{
p.xvelocity+=1;

	animation_right(&p);
	if (I.jump==0) mouvementright (&p);
	else if (I.jump==1) jumpright (&p);
scrolling_right (&b,&p,screen);
}else if (I.left==1)
{
	p.xvelocity+=1;
	animation_left(&p);
	if (I.jump==0) mouvementleft (&p);
	else if (I.jump==1) jumpleft (&p);
		scrolling_left (&b,&p,screen);

}else if (I.left==0 && I.down==0 && I.jump==0 && I.right==0 && I.attack==0)
{
	animation_stable(&p);
}else if (I.attack==1 )
{
	p.attack=1;
	animation_attack_r(&p);
}

*/


//SDL_Rect relcoord_perssonage={p.rect.x+b.x_relative,p.rect.y,p.rect.w,p.rect.h};
//SDL_Rect relcoord={f.rect.x-b.x_relative,f.rect.y};

//afficher_background (screen,&b);
//if (I.attack==0 ) afficher_perssonage (&p,screen);
 //else afficher_attack (p,screen);

//ennemi

/*
if(f.rect.x >= 800)
{
	f.direction =1;
}
if(f.rect.x< 400)
{
	f.direction=2;
}			

if (f.direction == 1)
{
			MoveEnnemi(&f);
			animation (&f);
}

if(f.direction == 2)
{
			MoveEnnemi(&f);
			animation (&f);
}			
*/
//int collision;
//collision = collision_BB(&p ,&f );
//if(collision = 1)
//p.rect.y+=10;



//MoveEnnemi(&f);
//afficher_enemie (&f,screen ,relcoord);


//SDL_Flip(screen);
//SDL_Delay(16);



