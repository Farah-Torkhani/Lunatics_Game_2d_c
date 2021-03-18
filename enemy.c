#include "Headers/headers.h"


			int nb_frames_e=15;

void setrects_enemie(SDL_Rect* clip)
  {
//mvt left
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=150;
  clip[0].h=150;
int i=1;
for (i=1;i<nb_frames_e;i++)
{
  clip[i].w=150;
  clip[i].x=clip[i-1].x+clip[i].w;
  clip[i].y=0;
  clip[i].h=150;
}

//mvt right
clip[15].x=0;
clip[15].y=150;
clip[15].w=150;
clip[15].h=150;
i=16;
for (i=16;i<(2*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=150;
clip[i].h=150;
}

//atack right
clip[30].x=0;
clip[30].y=300;
clip[30].w=150;
clip[30].h=150;
i=31;
for (i=31;i<(3*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=300;
clip[i].h=150;
}

//attack left
clip[45].x=0;
clip[45].y=450;
clip[45].w=150;
clip[45].h=150;
i=46;
for (i=46;i<(4*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=450;
clip[i].h=150;
}

//wait left
clip[60].x=0;
clip[60].y=600;
clip[60].w=150;
clip[60].h=150;
i=61;
for (i=61;i<(5*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=600;
clip[i].h=150;
}

//wait right
clip[75].x=0;
clip[75].y=750;
clip[75].w=150;
clip[75].h=150;
i=76;
for (i=76;i<(6*nb_frames_e);i++)
{
clip[i].w=150;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=750;
clip[i].h=150;
}

  }

void inisialiser_enemie (enemie *f)
{
f->enemie=IMG_Load("Assets/graphic/enemy/ground-guy.png");
f->rect.x=400;
f->rect.y=530;
f->rect.w=150;
f->rect.h=150;
f->frame=74;
f->direction=0;
setrects_enemie(f->rects);
}

void MoveEnnemi(enemie *E)
{
          if (E->direction==1)//left
          {
            E->rect.x -=3;

          }
          if(E->direction==2)//right
          {
            E->rect.x +=3;
          }

}

	void afficher_enemie (enemie *f,SDL_Surface *screen, SDL_Rect pos)
	{
        SDL_BlitSurface(f->enemie,&f->rects[f->frame],screen,&pos);
	}

	void animation (enemie *p)
	{  
		if (p->direction==1) // move left
		{
		p->frame++;
			if(p->frame>=15 ||p->frame<0 ) p->frame=0;
        }

if (p->direction==2) // move right
{
p->frame++;
	if(p->frame<=14 || p->frame>=30)  p->frame=15;				
}

if(p->direction==3) //attack right
{
  p->frame++;
  if(p->frame<=30 || p->frame>=45)  p->frame=30;
}

if(p->direction==4) //attack left
{
  p->frame++;
  if(p->frame<=45 || p->frame>=60)  p->frame=45;
}

if(p->direction==5) //wait left
{
  p->frame++;
  if(p->frame<=60 /*|| p->frame>=75*/)  p->frame=60;
}

if(p->direction==6) //wait right
{
  p->frame++;
  if(p->frame<=75/* || p->frame>=90*/)  p->frame=75;
}

	}



int collision_BB(SDL_Rect pos_hero , SDL_Rect pos_e )
{
	 int collision = 0;


    if( ((pos_hero.x + pos_hero.w) < pos_e.x ) ||  (pos_hero.x > (pos_e.x + pos_e.w)) || ((pos_hero.y + pos_hero.h) < pos_e.y) || (pos_hero.y > (pos_e.y + pos_e.h)) )
	{
		collision = 0 ;
	}
	else
	{
		collision = 1 ;
	}
	
  return collision;
}

void update_ennemi(enemie *e , SDL_Surface *screen , SDL_Rect pos_hero ,GameplayBg bg)
{

	if(pos_hero.x - e->rect.x  < -180  && pos_hero.x - e->rect.x >-350 ) //move left
	{
		e->direction=1;
		MoveEnnemi(e);
		animation (e);
	}
	else if(pos_hero.x - e->rect.x  <= 0  && pos_hero.x - e->rect.x >=-180 ) // attack left
	{
		e->direction=3;
		animation (e);
	}

	else if(pos_hero.x - e->rect.x  < 250  && pos_hero.x - e->rect.x >100 )// move right
	{
		e->direction=2;
		MoveEnnemi(e);
		animation (e);
	}
	else if(pos_hero.x - e->rect.x  <= 100  && pos_hero.x - e->rect.x >=-150 ) // attack right
	{
		e->direction=4;
		animation (e);
	}
	//***********mvt aletoire*******************************************************
	else if (pos_hero.x - e->rect.x <-350 || pos_hero.x - e->rect.x  > 250)//mvt aleatoire
	{
		if(e->rect.x  > 400 - bg.camera.x )
{
	e->direction =1; // move left
}
if(e->rect.x <= 400- bg.camera.x && e->rect.x>=398 - bg.camera.x )
{
	e->direction =6;//wait right 
}
if(e->rect.x < 300 - bg.camera.x)
{
	e->direction =2;//move right
}
if(e->rect.x >= 300 - bg.camera.x && e->rect.x <=302 - bg.camera.x)
{
	e->direction=5;//wait left
}			

if (e->direction == 6)
{
			animation (e);
			if (e->frame==90) e->direction=1;
}

if(e->direction == 1)
{
			MoveEnnemi(e);
			animation (e);
}

if (e->direction == 5)
{	
			animation (e);
			if (e->frame==75) e->direction=2;
}			
if(e->direction == 2)
{
			MoveEnnemi(e);
			animation (e);
}

	}
	
}