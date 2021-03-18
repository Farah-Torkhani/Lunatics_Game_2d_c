#include "Headers/headers.h"


#define Ground 400;
#define SPEED 5
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 25

int frameNb = 10;

void setrects(SDL_Rect *crop)
{
    int i;

    //idle right
    crop[0].x = 0;
    crop[0].y = 0;

    crop[0].w = 124;
    crop[0].h = 234;

    for (i = 1; i < frameNb; i++)
    {
        crop[i].w = 124;
        crop[i].h = 234;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 0;
    }

    //idle left
    crop[10].x = 0;
    crop[10].y = 234;

    crop[10].w = 124;
    crop[10].h = 234;

    for (i = 11; i < 2 * frameNb; i++)
    {
        crop[i].w = 124;
        crop[i].h = 234;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 234;
    }

    //run right
    crop[20].x = 0;
    crop[20].y = 468;

    crop[20].w = 222;
    crop[20].h = 280;

    for (i = 21; i < 3 * frameNb; i++)
    {
        crop[i].w = 222;
        crop[i].h = 280;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 468;
    }

    //run left
    crop[30].x = 0;
    crop[30].y = 748;

    crop[30].w = 222;
    crop[30].h = 280;

    for (i = 31; i < 4 * frameNb; i++)
    {
        crop[i].w = 222;
        crop[i].h = 280;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 748;
    }

    //jump right
    crop[40].x = 0;
    crop[40].y = 1030;

    crop[40].w = 221;
    crop[40].h = 295;

    for (i = 41; i < 5 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 295;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1030;
    }

    //jump left
    crop[50].x = 0;
    crop[50].y = 1325;

    crop[50].w = 221;
    crop[50].h = 295;

    for (i = 51; i < 6 * frameNb; i++)
    {
        crop[i].w = 221;
        crop[i].h = 295;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1325;
    }

    //attack right
    crop[60].x = 0;
    crop[60].y = 1620;

    crop[60].w = 352;
    crop[60].h = 325;

    for (i = 61; i < 7 * frameNb; i++)
    {
        crop[i].w = 352;
        crop[i].h = 325;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1620;
    }

    //attack left
    crop[70].x = 0;
    crop[70].y = 1945;

    crop[70].w = 352;
    crop[70].h = 325;

    for (i = 71; i < 8 * frameNb; i++)
    {
        crop[i].w = 352;
        crop[i].h = 325;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1945;
    }
}

void init_hero(Hero *h)
{

    h->allMvt = IMG_Load("Assets/graphic/hero/sprite.png");

    h->frame = 0;
    h->currentMode = 0;

    h->heroPos.x = 0;
    h->heroPos.y = Ground;

    h->heroPos_relative.x = 0;

    h->velocity = 0;
    h->speed = 5;

    h->xStep = 20;
    h->yStep = 10;

    setrects(h->rects);
}

void afficher_Hero(Hero *h, SDL_Surface *screen)
{
    SDL_BlitSurface(h->allMvt, &h->rects[h->frame], screen, &h->heroPos);
}

void idleAnimation(Hero *h)
{
    if (h->currentMode == 0)
    {
        if (h->frame < 0 || h->frame > 9)
        {
            h->frame = 0;
        }
        h->frame++;

        if (h->frame > frameNb - 1)
        {
            h->frame = 0;
        }
    }
    else if (h->currentMode == 1)
    {

        if (h->frame < 10 || h->frame > 19)
        {
            h->frame = 10;
        }
        h->frame++;

        if (h->frame > 19)
        {
            h->frame = 10;
        }
    }
}

void runAnimation(Hero *h)
{
    if (h->currentMode == 2)
    {
        if (h->frame < 20 || h->frame > 29)
        {
            h->frame = 20;
        }
        h->frame++;
        if (h->frame > 29)
        {
            h->frame = 20;
        }
    }
    else if (h->currentMode == 3)
    {
        if (h->frame < 30 || h->frame > 39)
        {
            h->frame = 30;
        }
        h->frame++;
        if (h->frame > 39)
        {
            h->frame = 30;
        }
    }
}

void jumpAnimation(Hero *h, SDL_Surface *screen, int run)
{

    if (h->currentMode == 4)
    {
        if (h->frame < 40 || h->frame > 49)
        {
            h->frame = 40;
        }
        h->frame++;
        if (h->frame > 49)
        {
            h->frame = 40;
        } 
       if (h->frame > 44)
            {
                h->heroPos.y += 25;
            }
            else
            {
                h->heroPos.y -= 25;
            }
            if ((run == 1 )&& (h->heroPos.x <= 360 ||  ( h->heroPos_relative.x>= 1280  && h->heroPos.x<= 800 )) )
            {
                h->heroPos.x += 15;
            }
       
        }//left
        else if(h->currentMode == 5 )
        {
        if (h->frame < 50 || h->frame > 59)
        {
            h->frame = 50;
        }
        h->frame++;
        if (h->frame > 59)
        {
            h->frame = 50;
        } 
       if (h->frame > 54)
            {
                h->heroPos.y += 25;
            }
            else
            {
                h->heroPos.y -= 25;
            }
            if (run == 1 && h->heroPos.x >= 160)
            {
                h->heroPos.x -= 15;
            }
       
        }
    
}

void attackAnimation(Hero *h, SDL_Surface *screen)
{
    int i;

    if (h->currentMode == 6)
    {
        if (h->frame < 60 || h->frame > 69)
        {
            h->frame = 60;
        }
        h->frame++;
        if (h->frame > 69)
        {
            h->frame = 60;
        } 

    }
    else if (h->currentMode == 7)
    {
        if (h->frame < 70 || h->frame > 79)
        {
            h->frame = 70;
        }
        h->frame++;
        if (h->frame > 79)
        {
            h->frame = 70;
        } 
    }
}
/*
void leftAndRightHeroMvt(Hero *hero, Input I)
{
    if (hero->currentMode == 2 || hero->currentMode == 3)
    {
        if (I.right == 1)
        {
            hero->heroPos.x += hero->xStep;
        }

        if (I.left == 1)
        {
            hero->heroPos.x -= hero->xStep;
        }
    }
}*/

void jumpHeroMvt(Hero *hero, Input I, int *run)
{
    if (I.jump == 1)
    {
        if (I.right == 1)
        {
            hero->currentMode = 4;
            *run = 1;
        }
        else if (I.left == 1)
        {
            hero->currentMode = 5;
            *run = 1;
        }
        else
        {
            if (hero->currentMode == 0)
            {
                hero->currentMode = 4;
                *run = 0;
            }
            else if (hero->currentMode == 1)
            {
                hero->currentMode = 5;
                *run = 0;
            }
        }
    }
}

void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt)
{
    if ( (hero->currentMode == 2 || hero->currentMode == 3)  )
    {
        if (I.right == 1  && (hero->heroPos.x <= 360 || (hero->heroPos_relative.x>= 1280 && hero->heroPos.x<= 800 )))
        {
            hero->xStep = 0.5 * hero->velocity * 2.2 * 2.2 + hero->speed * 2.2;
            hero->heroPos.x += hero->xStep;
            if (hero->velocity < 8)
            {
                hero->velocity += 0.5;
            }
        }

        if (I.left == 1 && hero->heroPos.x >= 160)
        {
            hero->xStep = 0.5 * hero->velocity * 2.2 * 2.2 + hero->speed * 2.2;
            hero->heroPos.x -= hero->xStep;
            if (hero->velocity < 8)
            {
                hero->velocity += 0.5;
            }
        }
    }
  //  if (I.right == 0 && I.left == 0)
    //{
      //  hero->velocity = 0;
  //  }
}