#ifndef struct_H_INCLUDED
#define struct_H_INCLUDED




typedef struct
{
    SDL_Surface *bg;
    SDL_Rect BgPos;

    SDL_Rect camera;
    SDL_Rect camera2;

} GameplayBg;

typedef struct 
	{

	SDL_Surface *enemie;
	SDL_Rect rect;
	SDL_Rect rects[90];
	int frame;
	int direction;
	}enemie;

typedef struct Input
{
 int left,right, left2,right2  ,jump,attack,down;

} Input;

typedef struct
{
    SDL_Surface *allMvt;
    SDL_Rect heroPos , heroPos_relative;
    SDL_Rect rects[80];

    int frame;
    float xStep, yStep;
    float velocity, speed;
    int currentMode;

} Hero;


 #endif // DS_H_INCLUDED