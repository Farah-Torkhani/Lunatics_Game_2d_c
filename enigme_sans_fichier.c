#include "Headers/headers.h"


//----------------------------Fonction init enigme-----------------------------------------
int Init_enigmee(enigmee *g ) 
{
g->enigme[0]= IMG_Load("Assets/graphic/enigme 2/1.png");
g->enigme[1]= IMG_Load("Assets/graphic/enigme 2/2.png");
g->enigme[2]= IMG_Load("Assets/graphic/enigme 2/3.png");

g->pos.x=0;
g->pos.y=0;

g->reponse[0]= IMG_Load("Assets/graphic/enigme 2/nonormal.png");
g->reponse[1]= IMG_Load("Assets/graphic/enigme 2/nohover.png");
g->reponse[2]= IMG_Load("Assets/graphic/enigme 2/noclicked.png");
g->reponse[3]= IMG_Load("Assets/graphic/enigme 2/nogreen.png");
g->reponse[4]= IMG_Load("Assets/graphic/enigme 2/nored.png");



g->reponse1[0]= IMG_Load("Assets/graphic/enigme 2/yesnormal.png");
g->reponse1[1]= IMG_Load("Assets/graphic/enigme 2/yeshover.png");
g->reponse1[2]= IMG_Load("Assets/graphic/enigme 2/yesclicked.png");
g->reponse1[3]= IMG_Load("Assets/graphic/enigme 2/yesgreen.png");
g->reponse1[4]= IMG_Load("Assets/graphic/enigme 2/yesred.png");


g->reponse_pos.x = 0;
g->reponse_pos.y = 0;


g->t=IMG_Load("Assets/graphic/win.jpg");
g->h = IMG_Load("Assets/graphic/lose.jpg");

g->posechoix.x = 2080 ;
g->posechoix.y = 400;
g->choiix= IMG_Load("Assets/graphic/enigme1/selectE.png");
  
}

//---------------------------Fonction afficher enigme-------------------------------------------
void afficherEnigmee(enigmee *e)
{ 

    SDL_Surface * screen;
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Lunatics", NULL); //window title

   //declare simple variables
    bool running=true;
	int i;
	int yesIndex = 0, noIndex = 0;
     Input I;
    //----------
    i=genererEnigmee(&e , screen );
    //----------

   //declare the event
	SDL_Event event;

SDL_EnableKeyRepeat(200,0);
while(running)
{

while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
        SDL_Quit();
			running=false;
		break; 
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
              
                if(i==0)
			{
              if (yesIndex == 1 && noIndex == 0)
                {
                    yesIndex = 2;
                    noIndex = 0;
                    SDL_Delay(700);
                    yesIndex=3;
                    SDL_Delay(700);
                    stage_1(screen);
				}

                else if (yesIndex == 0 && noIndex == 1)
                {
                    noIndex = 2;
                    yesIndex = 0;
                    SDL_Delay(700);
                    noIndex=4;
                    SDL_Delay(700);
                    stage_1(screen);
                }

            }
                if(i==1)
			{
              if (yesIndex == 1 && noIndex == 0)
                {
                    yesIndex = 2;
                    noIndex = 0;
                    SDL_Delay(700);
                    yesIndex=3;
                    SDL_Delay(700);
                    stage_1(screen);
				}

                else if (yesIndex == 0 && noIndex == 1)
                {
                    noIndex = 2;
                    yesIndex = 0;
                    SDL_Delay(700);
                    noIndex=4;
                    SDL_Delay(700);
                    stage_1(screen);
                }

            }
                if(i==2)
			{
              if (yesIndex == 1 && noIndex == 0)
                {
                    yesIndex = 2;
                    noIndex = 0;
                    SDL_Delay(700);
                    yesIndex=4;
                    SDL_Delay(700);
                    stage_1(screen);
				}
                else if (yesIndex == 0 && noIndex == 1)
                {
                    noIndex = 2;
                    yesIndex = 0;
                    SDL_Delay(700);
                    noIndex=3;
                    SDL_Delay(700);
                    stage_1(screen);
                }
            }
                break; 
			}  
		break;
	    }
    }
    SDL_BlitSurface(e->enigme[i],NULL,screen,&e->pos);
    SDL_BlitSurface(e->reponse[noIndex],NULL,screen,&e->reponse_pos);  
    SDL_BlitSurface(e->reponse1[yesIndex],NULL,screen,&e->reponse_pos);
    SDL_Flip(screen);
    SDL_Delay(16); 
} 
}


//-----------------------------------Fonction generer enigme-------------------------------------------
int genererEnigmee(enigmee *e ,SDL_Surface * screen )
{
int i ;
srand(time(NULL));
i=(rand()%3);
 return i ;
}
