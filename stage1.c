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



