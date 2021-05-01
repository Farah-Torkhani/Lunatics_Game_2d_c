#include "Headers/headers.h"

void initBg(GameplayBg *b)
{
    b->bg = NULL;
    b->BgPos.x = 0;
    b->BgPos.y = 0;

    b->camera.x = 0;
    b->camera.y = 0;

    b->camera.w = 639;
    b->camera.h = 720;

    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 639;
    b->camera2.h = 720;

    b->bg = IMG_Load("Assets/graphic/stages/bg1.jpg");
}

void afficher_background(SDL_Surface *screen, GameplayBg *b)
{
    SDL_Rect test;
    test.x = 641;
    test.y = 0;
    SDL_BlitSurface(b->bg, &b->camera, screen, &b->BgPos);
    SDL_BlitSurface(b->bg, &b->camera2, screen, &test);
}

void scrolling_right2(GameplayBg *b, float velocity, float velocity2, SDL_Surface *screen, Input I, Hero *hero, enemie *e, enigme *enigme1, enigmee *enigme2)
{
    if (I.right == 1)
    {
        if (b->camera.x < 10000 - 639)
        {
            b->camera.x += velocity;
            hero->heroPos_relative.x += velocity;
            e->rect.x -= velocity;
            enigme1->poschoix.x -= velocity;
            enigme2->posechoix.x -= velocity;
        }
    }

    if (I.right2 == 1)
    {
        if (b->camera2.x < 10000 - 639)
        {
            b->camera2.x += velocity2;
        }
    }
}

void scrolling_left2(GameplayBg *b, float velocity, float velocity2, SDL_Surface *screen, Input I, Hero *h, enemie *e, enigme *enigme1, enigmee *enigme2)
{
    if (I.left == 1)
    {
        if (b->camera.x > 0)
        {
            b->camera.x -= velocity;
            h->heroPos_relative.x -= velocity;
            e->rect.x += velocity;
            enigme1->poschoix.x += velocity;
            enigme2->posechoix.x += velocity;
        }
    }

    if (I.left2 == 1)
    {
        if (b->camera2.x > 0)
        {
            b->camera2.x -= velocity2;
        }
    }
}