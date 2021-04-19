#include "Headers/headers.h"
//#include "struct.h"
int frameNb = 10;

void init_hero(Hero *h)
{
    h->allMvt = IMG_Load("Assets/graphic/hero/test.png");

    h->hpBars[0] = IMG_Load("Assets/graphic/hero/hp_bars/hp_0.png");
    h->hpBars[1] = IMG_Load("Assets/graphic/hero/hp_bars/hp_1.png");
    h->hpBars[2] = IMG_Load("Assets/graphic/hero/hp_bars/hp_2.png");
    h->hpBars[3] = IMG_Load("Assets/graphic/hero/hp_bars/hp_3.png");
    h->hpBars[4] = IMG_Load("Assets/graphic/hero/hp_bars/hp_4.png");

    h->heroPos_relative.x = 0;

    h->frame = 0;
    h->currentMode = 0;

    h->heroPos.x = 100;
    h->heroPos.y = Ground;

    h->hpBarPos.x = 0;
    h->hpBarPos.y = 0;

    h->scoreImgPos.x = 1050;
    h->scoreImgPos.y = 30;

    h->velocity = 0;
    h->speed = 5;

    h->hp = 4;
    h->score = 0;

    h->xStep = 20;
    h->yStep = 10;

    setrects(h->rects);
}

void setrects(SDL_Rect *crop)
{
    int i;

    //idle right
    crop[0].x = 0;
    crop[0].y = 0;

    crop[0].w = 300;
    crop[0].h = 300;

    for (i = 1; i < frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 0;
    }

    //idle left
    crop[10].x = 0;
    crop[10].y = 300;

    crop[10].w = 300;
    crop[10].h = 300;

    for (i = 11; i < 2 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 300;
    }

    //run right
    crop[20].x = 0;
    crop[20].y = 600;

    crop[20].w = 300;
    crop[20].h = 300;

    for (i = 21; i < 3 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 600;
    }

    //run left
    crop[30].x = 0;
    crop[30].y = 900;

    crop[30].w = 300;
    crop[30].h = 300;

    for (i = 31; i < 4 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 900;
    }

    //jump right
    crop[40].x = 0;
    crop[40].y = 1200;

    crop[40].w = 300;
    crop[40].h = 300;

    for (i = 41; i < 5 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1200;
    }

    //jump left
    crop[50].x = 0;
    crop[50].y = 1500;

    crop[50].w = 300;
    crop[50].h = 300;

    for (i = 51; i < 6 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1500;
    }

    //attack right
    crop[60].x = 0;
    crop[60].y = 1800;

    crop[60].w = 300;
    crop[60].h = 300;

    for (i = 61; i < 7 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 1800;
    }

    //attack left
    crop[70].x = 0;
    crop[70].y = 2100;

    crop[70].w = 300;
    crop[70].h = 300;

    for (i = 71; i < 8 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 2100;
    }

    //dead right
    crop[80].x = 0;
    crop[80].y = 2400;

    crop[80].w = 300;
    crop[80].h = 300;

    for (i = 81; i < 9 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 2400;
    }

    //dead left
    crop[90].x = 0;
    crop[90].y = 2700;

    crop[90].w = 300;
    crop[90].h = 300;

    for (i = 91; i < 10 * frameNb; i++)
    {
        crop[i].w = 300;
        crop[i].h = 300;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 2700;
    }
}

void afficher_Hero(Hero *h, SDL_Surface *screen)
{
    SDL_BlitSurface(h->hpBars[h->hp], NULL, screen, &h->hpBarPos);
    SDL_BlitSurface(h->scoreImg, NULL, screen, &h->scoreImgPos);
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

void walkAnimation(Hero *h)
{
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

void jumpAnimation(Hero *h, SDL_Surface *screen, GameplayBg *b, enemie f, int run, Input I)
{
    int i;
    if (h->currentMode == 4 && I.jump == 1)
    {
        for (i = 40; i < 50; i++)
        {
            h->frame = i;

            if (i > 44)
            {
                h->heroPos.y += 50;
            }
            else
            {
                h->heroPos.y -= 50;
            }
            if (run == 1)
            {
                if (h->heroPos_relative.x < 2500)
                {
                    //h->heroPos.x += 40;
                    h->heroPos_relative.x += 20;
                    b->camera.x += 20;
                }
                else
                {
                    if (h->heroPos.x < 1000)
                        h->heroPos.x += 20;
                }
            }
            afficher_background(screen, b);
            afficher_Hero(h, screen);

            update_ennemi(&f, screen, h->hpBarPos, *b);
            afficher_enemie(&f, screen, f.rect);

            SDL_Flip(screen);
            SDL_Delay(20);
        }
    }
    else if (h->currentMode == 5 && I.jump == 1)
    {
        for (i = 50; i < 60; i++)
        {
            h->frame = i;

            if (i > 54)
            {
                h->heroPos.y += 50;
            }
            else
            {
                h->heroPos.y -= 50;
            }

            if (run == 1)
            {
                //h->heroPos.x -= 20;
                if (h->heroPos_relative.x > 100)
                {
                    h->heroPos_relative.x -= 20;
                    b->camera.x -= 20;
                }
            }
            afficher_background(screen, b);
            afficher_Hero(h, screen);

            update_ennemi(&f, screen, h->hpBarPos, *b);
            afficher_enemie(&f, screen, f.rect);

            SDL_Flip(screen);
            SDL_Delay(20);
        }
    }
}

void attackAnimation(Hero *h, SDL_Surface *screen, GameplayBg *b, enemie f, Input I)
{
    int i;

    if (h->currentMode == 4 && I.attack == 1)
    {
        for (i = 40; i < 49; i++)
        {
            h->frame = i;

            afficher_background(screen, b);
            afficher_Hero(h, screen);

            update_ennemi(&f, screen, h->hpBarPos, *b);
            afficher_enemie(&f, screen, f.rect);

            SDL_Flip(screen);
            SDL_Delay(15);
        }
    }
    else if (h->currentMode == 5 && I.attack == 1)
    {
        for (i = 50; i < 59; i++)
        {
            h->frame = i;

            afficher_background(screen, b);
            afficher_Hero(h, screen);

            update_ennemi(&f, screen, h->hpBarPos, *b);
            afficher_enemie(&f, screen, f.rect);

            SDL_Flip(screen);
            SDL_Delay(15);
        }
    }
}

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
/*
void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt)
{
    if (hero->currentMode == 2 || hero->currentMode == 3)
    {
        if (I.right == 1 && (hero->heroPos.x <= 360 || (hero->heroPos_relative.x >= 1280 && hero->heroPos.x <= 800)))
        {
            if (I.right == 1)
            {
                hero->xStep = 0.5 * hero->velocity * 2 * 2 + hero->speed * 2;

                hero->heroPos.x += hero->xStep;

                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
            }
        }
        if (I.left == 1)
        {
            hero->xStep = 0.5 * hero->velocity * 2 * 2 + hero->speed * 2;
            hero->heroPos.x -= hero->xStep;
            if (hero->velocity < 8)
            {
                hero->velocity += 0.5;
            }
        }
    }
    else if (hero->currentMode == 6 || hero->currentMode == 7)
    {
        if (I.right == 1 && (hero->heroPos.x <= 360 || (hero->heroPos_relative.x >= 1280 && hero->heroPos.x <= 800)))
        {

            if (I.right == 1)
            {
                hero->xStep = 0.5 * hero->velocity * 1 * 1 + hero->speed * 1;

                hero->heroPos.x += hero->xStep;

                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
            }
        }
        if (I.left == 1 && hero->heroPos.x > 5)
        {
            hero->xStep = 0.5 * hero->velocity * 1 * 1 + hero->speed * 1;
            hero->heroPos.x -= hero->xStep;
            if (hero->velocity < 8)
            {
                hero->velocity += 0.5;
            }
        }
    }

    if (I.right == 0 && I.left == 0)
    {
        //hero->velocity = 0;
    }
}
*/

void leftAndRightHeroMvtR(Hero *hero, Input I, Uint32 dt)
{
    if (hero->currentMode == 2 || hero->currentMode == 3)
    {
        if (I.right == 1 && (hero->heroPos.x <= 360 || (hero->heroPos_relative.x >= 2500 && hero->heroPos.x <= 1000)))
        //if (hero->heroPos.x <= 360)
        {
            if (I.right == 1)
            {
                hero->xStep = 0.5 * hero->velocity * 2 * 2 + hero->speed * 2;

                hero->heroPos.x += hero->xStep;

                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
            }
        }
        if (I.left == 1 && hero->heroPos.x > 70)
        {
            hero->xStep = 0.5 * hero->velocity * 2 * 2 + hero->speed * 2;
            hero->heroPos.x -= hero->xStep;
            if (hero->velocity < 8)
            {
                hero->velocity += 0.5;
            }
        }
    }
    else if (hero->currentMode == 6 || hero->currentMode == 7)
    {
        if (I.right == 1 && (hero->heroPos.x <= 360 || (hero->heroPos_relative.x >= 2500 && hero->heroPos.x <= 1000)))
        //if (hero->heroPos.x <= 360)
        {

            if (I.right == 1)
            {
                hero->xStep = 0.5 * hero->velocity * 1 * 1 + hero->speed * 1;

                hero->heroPos.x += hero->xStep;

                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
            }
        }
        if (I.left == 1 && hero->heroPos.x > 50)
        {
            hero->xStep = 0.5 * hero->velocity * 1 * 1 + hero->speed * 1;
            hero->heroPos.x -= hero->xStep;
            if (hero->velocity < 8)
            {
                hero->velocity += 0.5;
            }
        }
    }

    if (I.right == 0 && I.left == 0)
    {
        //hero->velocity = 0;
    }
}

void deadAnimation(Hero *h, SDL_Surface *screen, GameplayBg *b, enemie f)
{
    int i;

    if (h->currentMode == 8)
    {
        for (i = 80; i < 89; i++)
        {
            h->frame = i;

            afficher_background(screen, b);
            afficher_Hero(h, screen);
            afficher_enemie(&f, screen, f.rect);

            SDL_Flip(screen);
            SDL_Delay(15);
        }
        h->currentMode = -1;
    }
    else if (h->currentMode == 9)
    {
        for (i = 90; i < 99; i++)
        {
            h->frame = i;

            afficher_background(screen, b);
            afficher_Hero(h, screen);
            afficher_enemie(&f, screen, f.rect);

            SDL_Flip(screen);
            SDL_Delay(15);
        }
        h->currentMode = -1;
    }
}

void updateHeroHealth(Hero *h, char *direction)
{
    if (h->hp > 0)
    {
        h->hp = h->hp - 1;
        if (h->hp == 0)
        {
            if (strcmp(direction, "right") == 0)
            {
                h->currentMode = 8;
            }
            else
            {
                h->currentMode = 9;
            }
        }
    }
}

void updateHeroScore(Hero *h, TTF_Font *police, SDL_Color color, char *scoreText, SDL_Surface *screen)
{
    h->score = h->score + 10;
    sprintf(scoreText, "Score: %d", h->score);
    h->scoreImg = TTF_RenderText_Blended(police, scoreText, color);
}
//--