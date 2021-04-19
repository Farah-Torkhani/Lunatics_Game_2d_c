#ifndef struct_H_INCLUDED
#define struct_H_INCLUDED

typedef struct
{
	SDL_Rect pos, reponse_pos, poschoix;

	SDL_Surface *enigme, *choix;
	SDL_Surface *reponse, *reponsehover, *reponse1hover, *reponse1, *t, *h;

	char rep[3];

} enigme;

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
} enemie;

typedef struct Input
{
	int left, right, left2, right2, jump, attack, down, e, up, test, save;

} Input;

typedef struct
{
	SDL_Surface *allMvt;
	SDL_Surface *hpBars[5];
	SDL_Surface *scoreImg;
	SDL_Rect heroPos, scoreImgPos, heroPos_relative;
	SDL_Rect rects[100];
	SDL_Rect hpBarPos;

	int frame;
	float xStep, yStep;
	float velocity, speed;
	int currentMode;
	int hp;
	int score;

} Hero;

typedef struct
{
	SDL_Rect pos, reponse_pos, posechoix;

	SDL_Surface *enigme[3];
	SDL_Surface *reponse[5], *reponse1[5], *t, *h, *choiix;

} enigmee;

#endif // DS_H_INCLUDED