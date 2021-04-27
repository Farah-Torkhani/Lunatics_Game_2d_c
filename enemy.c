#include "Headers/headers.h"
/*
void setrects_enemie(SDL_Rect *clip)
{
	//mvt left
	clip[0].x = 0;
	clip[0].y = 0;
	clip[0].w = 170;
	clip[0].h = 300;
	int i = 1;
	for (i = 1; i < 13; i++)
	{
		clip[i].w = 170;
		clip[i].x = clip[i - 1].x + clip[i].w;
		clip[i].y = 0;
		clip[i].h = 300;
	}

	//mvt right
	clip[13].x = 0;
	clip[13].y = 300;
	clip[13].w = 170;
	clip[13].h = 300;
	i = 14;
	for (i = 14; i < 26; i++)
	{
		clip[i].w = 170;
		clip[i].x = clip[i - 1].x + clip[i].w;
		clip[i].y = 300;
		clip[i].h = 300;
	}

	//atack left
	clip[26].x = 0;
	clip[26].y = 600;
	clip[26].w = 170;
	clip[26].h = 300;
	i = 27;
	for (i = 27; i < 35	; i++)
	{
		clip[i].w = 170;
		clip[i].x = clip[i - 1].x + clip[i].w;
		clip[i].y = 600;
		clip[i].h = 300;
	}

	//attack right
	clip[35].x = 0;
	clip[35].y = 900;
	clip[35].w = 170;
	clip[35].h = 300;
	i = 37;
	for (i = 37; i < 44; i++)
	{
		clip[i].w = 170;
		clip[i].x = clip[i - 1].x + clip[i].w;
		clip[i].y = 900;
		clip[i].h = 300;
	}

	//wait left
	clip[44].x = 0;
	clip[44].y = 1200;
	clip[44].w = 170;
	clip[44].h = 300;
	i = 45;
	for (i = 45; i < 59; i++)
	{
		clip[i].w = 170;
		clip[i].x = clip[i - 1].x + clip[i].w;
		clip[i].y = 1200;
		clip[i].h = 300;
	}

	//wait right
	clip[59].x = 0;
	clip[59].y = 1500;
	clip[59].w = 170;
	clip[59].h = 300;
	i = 60;
	for (i = 60; i < 74; i++)
	{
		clip[i].w = 170;
		clip[i].x = clip[i - 1].x + clip[i].w;
		clip[i].y = 1500;
		clip[i].h = 300;
	}
}*/

void setrects_enemie(SDL_Rect* clip)
  {

//mvt left
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=170;
  clip[0].h=300;
int i=1;
for (i=1;i<7;i++)
{
  clip[i].w=170;
  clip[i].x=clip[i-1].x+clip[i].w;
  clip[i].y=0;
  clip[i].h=300;
}

//mvt right
clip[7].x=0;
clip[7].y=300;
clip[7].w=170;
clip[7].h=300;
i=8;
for (i=8 ; i<14 ;i++)
{
clip[i].w=170;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=300;
clip[i].h=300;
}

//atack left
clip[14].x=0;
clip[14].y=600;
clip[14].w=170;
clip[14].h=300;
i=15;
for (i=15; i<17 ;i++)
{
clip[i].w=170;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=600;
clip[i].h=300;
}

//attack right
clip[17].x=0;
clip[17].y=900;
clip[17].w=170;
clip[17].h=300;
i=18;
for (i=18; i<20 ;i++)
{
clip[i].w=170;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=900;
clip[i].h=300;
}

//wait left
clip[20].x=0;
clip[20].y=1200;
clip[20].w=170;
clip[20].h=300;
i=21;
for (i=21;i<31;i++)
{
clip[i].w=170;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=1200;
clip[i].h=300;
}

//wait right
clip[31].x=0;
clip[31].y=1500;
clip[31].w=170;
clip[31].h=300;
i=32;
for (i=32; i<41 ;i++)
{
clip[i].w=170;
clip[i].x=clip[i-1].x+clip[i].w;
clip[i].y=1500;
clip[i].h=300;
}
}
void inisialiser_enemie (enemie *f)
{
f->enemie=IMG_Load("Assets/graphic/enemy/ennemie.png");
f->rect.x=7000;
f->rect.y=400;
f->rect.w=170;
f->rect.h=300;
f->frame=0;
f->direction=0;
setrects_enemie(f->rects);
}

void MoveEnnemi(enemie *E)
{
	if (E->direction == 1) //left
	{
		E->rect.x -= 3;
	}
	if (E->direction == 2) //right
	{
		E->rect.x += 3;
	}
}

void afficher_enemie(enemie *f, SDL_Surface *screen, SDL_Rect pos)
{
	SDL_BlitSurface(f->enemie, &f->rects[f->frame], screen, &pos);
}

void animation(enemie *p)
{
	if (p->direction == 1) // move left
	{
		p->frame++;
		if (p->frame >= 7 || p->frame < 0)
			p->frame = 0;
	}

	if (p->direction == 2) // move right
	{
		p->frame++;
		if (p->frame <= 6 || p->frame >= 14)
			p->frame = 7;
	}

	if (p->direction == 3) //attack right
	{
		p->frame++;
		if (p->frame <= 14 || p->frame >= 17)
			p->frame = 14;
	}

	if (p->direction == 4) //attack left
	{
		p->frame++;
		if (p->frame <= 17 || p->frame >= 20)
			p->frame = 17;
	}

	if (p->direction == 5) //wait left
	{
		p->frame++;
		if (p->frame <= 20 /*|| p->frame>=31*/)
			p->frame = 20;
	}

	if (p->direction == 6) //wait right
	{
		p->frame++;
		if (p->frame <= 31 /* || p->frame>=41*/)
			p->frame = 31;
	}
}

int collision_BB(SDL_Rect pos_hero, SDL_Rect pos_e)
{
	int collision = 0;

	if (((pos_hero.x + pos_hero.w) < pos_e.x) || (pos_hero.x > (pos_e.x + pos_e.w)) || ((pos_hero.y + pos_hero.h) < pos_e.y) || (pos_hero.y > (pos_e.y + pos_e.h)))
	{
		collision = 0;
	}
	else
	{
		collision = 1;
	}

	return collision;
}

void update_ennemi(enemie *e, SDL_Surface *screen, SDL_Rect pos_hero, GameplayBg bg , Hero *hero)
{

	if (pos_hero.x - e->rect.x < -300 && pos_hero.x - e->rect.x > -450) //move left
	{
		e->direction = 1;
		MoveEnnemi(e);
		animation(e);
	}
	else if (pos_hero.x - e->rect.x <= 0 && pos_hero.x - e->rect.x >= -300) // attack left
	{
		e->direction = 3;
		animation(e);
		/*if(hero->hp<=0)
        {
            SDL_Delay(2000);  
            GameOver(screen);
        }  
		hero->heroPos.x-=150; 
		updateHeroHealth(hero, "right");*/
	}


	else if (pos_hero.x - e->rect.x < 300 && pos_hero.x - e->rect.x > 150) // move right
	{
		e->direction = 2;
		MoveEnnemi(e);
		animation(e);
	}
	else if (pos_hero.x - e->rect.x <= 150 && pos_hero.x - e->rect.x >= -150) // attack right
	{
		e->direction = 4;
		animation(e);
	}
	//***********mvt aletoire*******************************************************
	else if (pos_hero.x - e->rect.x < -350 || pos_hero.x - e->rect.x > 250) //mvt aleatoire
	{
		if (e->rect.x > 8000 - bg.camera.x)
		{
			e->direction = 1; // move left
		}
		if (e->rect.x <= 8000 - bg.camera.x && e->rect.x >= 7998 - bg.camera.x)
		{
			e->direction = 6; //wait right
		}
		if (e->rect.x < 7700 - bg.camera.x)
		{
			e->direction = 2; //move right
		}
		if (e->rect.x >= 7700 - bg.camera.x && e->rect.x <= 7702 - bg.camera.x)
		{
			e->direction = 5; //wait left
		}

		if (e->direction == 6)
		{
			animation(e);
			if (e->frame == 41)
				e->direction = 1;
		}

		if (e->direction == 1)
		{
			MoveEnnemi(e);
			animation(e);
		}

		if (e->direction == 5)
		{
			animation(e);
			if (e->frame == 31)
				e->direction = 2;
		}
		if (e->direction == 2)
		{
			MoveEnnemi(e);
			animation(e);
		}
	}
}