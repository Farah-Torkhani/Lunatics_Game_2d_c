#include "Headers/headers.h"

void stage_1(SDL_Surface *screen)
{
    //declare simple variables
    int done = 1, run = 0;

    SDL_Surface *top_bg, *score;

    enemie f;
    enigme  enigme_avec_fichier;
    enigmee enigme_sans_fichier;

    //----------------------------------------------------------------------------------------------------------------------
    Hero hero;
    char direction[50];
    char scoreText[100];
    Uint32 dt, t_prev;

    //----------------------------------------------------------------------------------------------------------------------

    GameplayBg b;

    bool running = true;
    SDL_Event event;
    Input I;
    int next;
    int i = 0;
    int act = 1;
    int enigme_reponse = 0;

    initBg(&b);
    init_hero(&hero);
    Init_enigme(&enigme_avec_fichier);
     Init_enigmee(&enigme_sans_fichier);
    inisialiser_enemie(&f);
    initialiser_input(&I);
   

getpose(&hero.heroPos.x ,&hero.heroPos.y,&f.rect.y, &f.rect.x,& b.camera.x , &hero.hp ,&hero.score , &enigme_reponse );



    SDL_Rect top_bgPos;
    top_bgPos.x = 0;
    top_bgPos.y = 0;

    TTF_Init();
    TTF_Font *police;
    police = police = TTF_OpenFont("Assets/fonts/DelaGothicOne-Regular.ttf", 25);
    SDL_Color white = {0, 0, 0};
    sprintf(scoreText, "Score: %d", hero.score);
    score = TTF_RenderText_Blended(police, scoreText, white);

    top_bg = IMG_Load("Assets/graphic/hero/top_bg.jpg");

    SDL_EnableKeyRepeat(200, 0);
    while (done)
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

                SDL_Quit();
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    //done = 0;
                    pause(screen);
                    break;

                case SDLK_SPACE:
                    I.jump = 1;

                    break;

                case SDLK_RIGHT:
                    I.right = 1;
                    //hero.currentMode = 2;
                    hero.currentMode = 6;
                    break;

                case SDLK_LEFT:
                    I.left = 1;
                    hero.currentMode = 7;
                    //hero.currentMode = 3;
                    break;

                case SDLK_x:
                    //I.jump = 0;
                    I.attack = 1;
                    if (strcmp(direction, "right") == 0)
                    {
                        hero.currentMode = 4;
                    }
                    else
                    {
                        hero.currentMode = 5;
                    }
                    break;
                case SDLK_a:
                    if (hero.currentMode == 6)
                    {
                        hero.currentMode = 2;
                    }
                    else if (hero.currentMode == 7)
                    {
                        hero.currentMode = 3;
                    }
                    break;

                case SDLK_p:
                    updateHeroHealth(&hero, direction);
                    break;

                case SDLK_o:
                    updateHeroScore(&hero, &score, police, white, scoreText, screen);
                    break;
                case SDLK_e:
				    I.e=1;
                    I.test=1;
				 break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    I.jump = 0;
                    if (I.right == 1)
                    {
                        hero.currentMode = 6;
                    }
                    else if (I.left == 1)
                    {
                        hero.currentMode = 7;
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

                case SDLK_a:
                    if (hero.currentMode == 2)
                    {
                        hero.currentMode = 6;
                    }
                    else if (hero.currentMode == 3)
                    {
                        hero.currentMode = 7;
                    }
                }
                break;
            }
            dt = SDL_GetTicks() - t_prev;
        }
        

        //run left and right
        leftAndRightHeroMvtR(&hero, I, dt);
        //run left and right

        //jump movement
        jumpHeroMvt(&hero, I, &run);
        //jump movement

        SDL_BlitSurface(b.bg, NULL, screen, &b.BgPos);
        idleAnimation(&hero);
        runAnimation(&hero);
        walkAnimation(&hero);
        jumpAnimation(&hero, screen, b.bg, b.BgPos, run, I);
        attackAnimation(&hero, screen, b.bg, b.BgPos, I);
        deadAnimation(&hero, screen, b.bg, b.BgPos);

        afficher_background(screen, &b);

        afficher_Hero(&hero, screen, b.bg, score);

        // pos ennemi
        SDL_Rect relcoord = {f.rect.x, f.rect.y};
        //
        SDL_Rect relcoord1 = {f.rect.x, f.rect.y, f.rect.h, f.rect.w};

                        /*


        int collision=0;
        collision = collision_BB(heropos ,relcoord1 );
        if(collision == 1)
        {
            heropos.y+=10;
        }
                            */

        update_ennemi(&f, screen, hero.heroPos, b);

        //MoveEnnemi(&f);

        scrolling_right(&b, hero.velocity, screen, I, &hero, &f,&enigme_avec_fichier,&enigme_sans_fichier);
        scrolling_left(&b, hero.velocity, screen, I, &hero, &f,&enigme_avec_fichier,&enigme_sans_fichier);

        afficher_enemie(&f, screen, relcoord);
        
        
      
      //afficher enigme 1
if(hero.heroPos.x>1000 - b.camera.x &&hero.heroPos.x<=1500 - b.camera.x && enigme_reponse==0) 
{
SDL_BlitSurface(enigme_avec_fichier.choix,NULL,screen,&enigme_avec_fichier.poschoix);



}
if(hero.heroPos.x>1000 - b.camera.x &&hero.heroPos.x<=1500 - b.camera.x &&I.e==1 && enigme_reponse ==0)
{
    
    
	afficherEnigme(&enigme_avec_fichier); 
    
     
}
else
{
	I.e=0;
}
        //afficher enigme 2
if(hero.heroPos.x>2000 - b.camera.x &&hero.heroPos.x<=2500 - b.camera.x && enigme_reponse==0) 
{
SDL_BlitSurface(enigme_sans_fichier.choiix,NULL,screen,&enigme_sans_fichier.posechoix);




}
if(hero.heroPos.x>2000 - b.camera.x &&hero.heroPos.x<=2500- b.camera.x && I.test==1 && enigme_reponse ==0)
{
   //  savePose(hero.heroPos , f.rect, b.camera , hero.hp ,hero.score , enigme_reponse );

	afficherEnigmee(&enigme_sans_fichier);
    
     
}
else
{
	I.test=0;
}
if(I.up==1)
{
updateHeroScore(&hero, &score, police, white, scoreText, screen);
}
else if(I.up==2)
{
updateHeroHealth(&hero, direction);
}
 savescovie(hero.hp , hero.score );
 savePose(hero.heroPos.x , f.rect.x, b.camera.x , hero.hp ,hero.score , enigme_reponse );
        SDL_Flip(screen);
        SDL_Delay(20);
    }
}


void pause(SDL_Surface *screen)
{
    int english, done = 1;
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

    SDL_Surface *BACKGROUND, *RESUMER_b[2], *SAVE_b[2], *SETTINGS_b[2], *QUITE_b[2];
    SDL_Surface *BACKGROUND_FR, *RESUMER_b_FR[2], *SAVE_b_FR[2], *SETTINGS_b_FR[2], *QUITE_b_FR[2];
    BACKGROUND = IMG_Load("Assets/graphic/stages/bg.jpg");
    RESUMER_b[0] = IMG_Load("Assets/graphic/stages/resume0.png");
    RESUMER_b[1] = IMG_Load("Assets/graphic/stages/resume1.png");
    SAVE_b[0] = IMG_Load("Assets/graphic/stages/save0.png");
    SAVE_b[1] = IMG_Load("Assets/graphic/stages/save1.png");
    SETTINGS_b[0] = IMG_Load("Assets/graphic/stages/settings0.png");
    SETTINGS_b[1] = IMG_Load("Assets/graphic/stages/settings1.png");
    QUITE_b[0] = IMG_Load("Assets/graphic/stages/exit0.png");
    QUITE_b[1] = IMG_Load("Assets/graphic/stages/exit1.png");

    BACKGROUND_FR = IMG_Load("Assets/graphic/stages/bg.jpg");
    RESUMER_b_FR[0] = IMG_Load("Assets/graphic/stages/resumefr0.png");
    RESUMER_b_FR[1] = IMG_Load("Assets/graphic/stages/resumefr1.png");
    SAVE_b_FR[0] = IMG_Load("Assets/graphic/stages/savefr0.png");
    SAVE_b_FR[1] = IMG_Load("Assets/graphic/stages/savefr1.png");
    SETTINGS_b_FR[0] = IMG_Load("Assets/graphic/stages/parametre0.png");
    SETTINGS_b_FR[1] = IMG_Load("Assets/graphic/stages/parametre1.png");
    QUITE_b_FR[0] = IMG_Load("Assets/graphic/stages/quitter0.png");
    QUITE_b_FR[1] = IMG_Load("Assets/graphic/stages/quitter1.png");

    SDL_Rect pos;

    pos.x = 0;
    pos.y = 0;
    SDL_Event event;

    while (done)
    {
        if (english == 0)
        {
            SDL_BlitSurface(BACKGROUND, NULL, screen, &pos);
            SDL_BlitSurface(RESUMER_b[resInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SAVE_b[savInputHover], NULL, screen, &pos);
            SDL_BlitSurface(SETTINGS_b[setInputHover], NULL, screen, &pos);
            SDL_BlitSurface(QUITE_b[quiInputHover], NULL, screen, &pos);
        }
        else if (english == 1)
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
                    if (resInputHover == 0 && savInputHover == 0 && setInputHover == 0 && quiInputHover == 0)
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
                    if (resInputHover == 1)
                    {
                        stage_1(screen);
                    }
                    else if (setInputHover == 1)
                    {
                        settingsMenu(screen);
                    }
                    else if (quiInputHover == 1)
                    {
                        done = 0;
                    }
                    break;
                }
            }
        }
    }

    SDL_FreeSurface(screen);
    SDL_Quit();

}


//save the pose  to the file "savepos.txt"
void savePose(int heropos , int enemypos,int camera ,int vie ,int score ,int enigme1 )
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/savepos.txt", "w");
    fprintf(fichier, "%d %d %d %d %d %d" ,heropos ,enemypos,camera, vie ,score ,enigme1   );
    fclose(fichier);
}

//get the pos  from the file "savepos.txt"
void getpose(int *heropos ,int *heroposy,int *recty, int *enemypos,int *camera ,int *vie ,int *score ,int *enigme1)
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/savepos.txt", "r");
    while (!feof(fichier))
        fscanf(fichier, "%d %d %d %d %d %d" ,heropos ,enemypos, camera, vie ,score ,enigme1 );
    fclose(fichier);
    heroposy=600;
    recty=600;
}

//save score and health to the file "savepos.txt"
void savescovie(int vie ,int score )
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/save-sco-vie.txt", "w");
    fprintf(fichier, "%d %d" ,vie ,score );
    fclose(fichier);
}

//get the score and health from the file "savepos.txt"
void getscovie(int *vie ,int *score)
{
    FILE *fichier = NULL;
    fichier = fopen("Fichier/save-sco-vie.txt", "r");
    while (!feof(fichier))
    fscanf(fichier, "%d %d" ,vie ,score );
    fclose(fichier);
}