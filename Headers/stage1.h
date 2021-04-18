#ifndef stage1_H_INCLUDED
#define stage1_H_INCLUDED





void stage_1(SDL_Surface *screen);
//void pause(SDL_Surface *screen);
void savePose(int heropos , int enemypos,int camera ,int vie ,int score ,int enigme1 );
void getpose(int *heropos ,int *heroposy,int *recty, int *enemypos ,int *camera,int *vie ,int *score ,int *enigme1);
void savescovie(int vie ,int score );
void getscovie(int *vie ,int *score);

 #endif // DS_H_INCLUDED