#include "Headers/headers.h"



void setrects_enemie(SDL_Rect* clip)
  {
//mvt left
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=390.75;
  clip[0].h=432;
int i=1;
for (i=1;i<10;i++)
{
  clip[i].w=390.75;
  clip[i].x=clip[i-1].x+clip[i].w;
  clip[i].y=0;
  clip[i].h=432;
}

//mvt right
clip[10].x=0;
clip[10].y=432;
clip[10].w=390.75;
clip[10].h=432;
i=11;
for (i=11 ; i<20 ;i++)
{
clip[i].w=390.75;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=432;
clip[i].h=432;
}

//atack left
clip[20].x=0;
clip[20].y=864;
clip[20].w=390.75;
clip[20].h=432;
i=21;
for (i=21; i<28 ;i++)
{
clip[i].w=390.75;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=864;
clip[i].h=432;
}

//attack right
clip[28].x=0;
clip[28].y=1296;
clip[28].w=390.75;
clip[28].h=432;
i=29;
for (i=29; i<36 ;i++)
{
clip[i].w=390.75;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=1296;
clip[i].h=432;
}

//wait left
clip[36].x=0;
clip[36].y=1728;
clip[36].w=390.75;
clip[36].h=432;
i=37;
for (i=37;i<51;i++)
{
clip[i].w=390.75;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=1728;
clip[i].h=432;
}

//wait right
clip[51].x=0;
clip[51].y=2160;
clip[51].w=390.75;
clip[51].h=432;
i=52;
for (i=52; i<66 ;i++)
{
clip[i].w=390.75;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=2160;
clip[i].h=432;
}

  }

void inisialiser_enemie (enemie *f)
{
f->enemie=IMG_Load("Assets/graphic/enemy/ennemie.png");
f->rect.x=1000;
f->rect.y=250;
f->rect.w=390.75;
f->rect.h=432;
f->frame=0;
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
			if(p->frame>=10 ||p->frame<0 ) p->frame=0;
        }

if (p->direction==2) // move right
{
p->frame++;
	if(p->frame<=9 || p->frame>=20)  p->frame=10;				
}

if(p->direction==3) //attack right
{
  p->frame++;
  if(p->frame<=20 || p->frame>=28)  p->frame=20;
}

if(p->direction==4) //attack left
{
  p->frame++;
  if(p->frame<=28 || p->frame>=36)  p->frame=28;
}

if(p->direction==5) //wait left
{
  p->frame++;
  if(p->frame<=36 /*|| p->frame>=51*/)  p->frame=36;
}

if(p->direction==6) //wait right
{
  p->frame++;
  if(p->frame<=51/* || p->frame>=66*/)  p->frame=51;
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

	else if(pos_hero.x - e->rect.x  < 500  && pos_hero.x - e->rect.x >350 )// move right
	{
		e->direction=2;
		MoveEnnemi(e);
		animation (e);
	}
	else if(pos_hero.x - e->rect.x  <= 350  && pos_hero.x - e->rect.x >=-150 ) // attack right
	{
		e->direction=4;
		animation (e);
	}
	//***********mvt aletoire*******************************************************
	else if (pos_hero.x - e->rect.x <-350 || pos_hero.x - e->rect.x  > 250)//mvt aleatoire
	{
		if(e->rect.x  > 1000 - bg.camera.x )
{
	e->direction =1; // move left
}
if(e->rect.x <= 1000- bg.camera.x && e->rect.x>=998 - bg.camera.x )
{
	e->direction =6;//wait right 
}
if(e->rect.x < 700 - bg.camera.x)
{
	e->direction =2;//move right
}
if(e->rect.x >= 700 - bg.camera.x && e->rect.x <=702 - bg.camera.x)
{
	e->direction=5;//wait left
}			

if (e->direction == 6)
{
			animation (e);
			if (e->frame==66) e->direction=1;
}

if(e->direction == 1)
{
			MoveEnnemi(e);
			animation (e);
}

if (e->direction == 5)
{	
			animation (e);
			if (e->frame==51) e->direction=2;
}			
if(e->direction == 2)
{
			MoveEnnemi(e);
			animation (e);
}

	}
	
}