#include "Headers/headers.h"

//----------------------------Fonction init enigme-----------------------------------------
int Init_enigme(enigme *g ) 
{ char quest1[100],choix1[100],choix2[100],win[100],lose[100],rep1[3],line[300] , rep1hover[100] , rep2hover[100];

g->poschoix.x = 1280 ;
g->poschoix.y = 400;
g->choix= IMG_Load("Assets/graphic/enigme1/selectE.png");

int i,j;
    FILE *fichier = NULL;
    fichier= fopen("text.txt","r"); 
   i=genererEnigme();
    if(fichier!=NULL)

    {
      
      for(j=0;j<i+1;j++)
      {
         fgets(line,300,fichier) ;
      }
     
char * token = strtok(line, " "); 
 
   
    
    strcpy(choix1,token);
    token = strtok(NULL, " "); 

    strcpy(choix2,token);
    token = strtok(NULL, " ");

    strcpy(rep1,token);
    token = strtok(NULL, " ");
 
    strcpy(quest1,token);
     token = strtok(NULL, " ");

    strcpy(win,token);
    token = strtok(NULL, " ");
 
    strcpy(lose,token);
    token = strtok(NULL, " ");

    strcpy(rep1hover,token);
    token = strtok(NULL, " ");

    strcpy(rep2hover,token);


      
    }


g->pos.x=0;
g->pos.y=0;
g->reponse= IMG_Load(choix1);
g->reponse1= IMG_Load(choix2); 
g->enigme= IMG_Load(quest1);

g->reponse_pos.x = 0;
g->reponse_pos.y = 0;


g->t=IMG_Load(win);
g->h = IMG_Load(lose);
g->reponsehover = IMG_Load(rep1hover);
g->reponse1hover = IMG_Load(rep2hover);
strcpy(g->rep,rep1);

  
}

//---------------------------Fonction afficher enigme-------------------------------------------
void afficherEnigme(enigme *e )
{ 
     

    SDL_Surface * screen, *score;;
    Hero hero;
    char direction[50];
    char scoreText[100];
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Lunatics", NULL); //window title

   //declare simple variables
    bool running=true;
	int i,enigme_reponse=0;
    GameplayBg b;
    enemie f;
  
    //-------

     Input I;
     I.up=0;
  I.save=1;
    //----------
  
      TTF_Init();
    TTF_Font *police;
    police = police = TTF_OpenFont("Assets/fonts/DelaGothicOne-Regular.ttf", 25);
    SDL_Color white = {0, 0, 0};
   sprintf(scoreText, "Score: %d", hero.score);


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
				case SDLK_KP1:
                if (strcmp(e->rep,"1")==0)
                {
                    SDL_BlitSurface(e->reponsehover,NULL,screen,&e->reponse_pos); 
                    SDL_Flip(screen);
                     SDL_Delay(200);  
                     I.up=1;
                      
                       updateHeroScore(&hero, &score, police, white, scoreText, screen); 
savePose(hero.heroPos.x , f.rect.x, b.camera.x , hero.hp ,hero.score , enigme_reponse );
                        stage_1(screen) ;            
                            }
                else
                {
                    
                    SDL_BlitSurface(e->reponse1hover,NULL,screen,&e->reponse_pos);
                     SDL_Flip(screen);
                     SDL_Delay(200); 
                  updateHeroHealth(&hero, direction);
savePose(hero.heroPos.x , f.rect.x, b.camera.x , hero.hp ,hero.score , enigme_reponse );
                     stage_1(screen) ;   
                 
                }
               
                
                break;

            case SDLK_KP2:
            if (strcmp(e->rep,"2")==0)
                {

                    SDL_BlitSurface(e->reponsehover,NULL,screen,&e->reponse_pos); 
                    SDL_Flip(screen);
                     SDL_Delay(200); 
                     I.up=1;
                  
              updateHeroScore(&hero, &score, police, white, scoreText, screen);
savePose(hero.heroPos.x , f.rect.x, b.camera.x , hero.hp ,hero.score , enigme_reponse );
                 stage_1(screen) ;
              
                }
                else
                {
                     SDL_BlitSurface(e->reponse1hover,NULL,screen,&e->reponse_pos);
                     SDL_Flip(screen);
                     SDL_Delay(200); 

                  updateHeroHealth(&hero, direction);
savePose(hero.heroPos.x , f.rect.x, b.camera.x , hero.hp ,hero.score , enigme_reponse );
                 stage_1(screen) ;
                }
               
                break;



			}  
		break;

        case SDL_KEYUP:
			switch (event.key.keysym.sym) 
			{	
				
			}
		break;
	    }
    }

     SDL_BlitSurface(e->enigme,NULL,screen,&e->pos);
     SDL_BlitSurface(e->reponse,NULL,screen,&e->reponse_pos);  
     SDL_BlitSurface(e->reponse1,NULL,screen,&e->reponse_pos);
    
SDL_Flip(screen);
SDL_Delay(16); 
} 

}

//-----------------------------------Fonction generer enigme-------------------------------------------
int genererEnigme()
{
int i ;
srand(time(NULL));
i=(rand()%2);
 return i ;
}

