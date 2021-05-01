#ifndef option_H_INCLUDED
#define option_H_INCLUDED

void settingsMenu(SDL_Surface *screen);
void saveVolume(int music);
void savelanguge(int english);
void controllersScreen(SDL_Surface *screen);
void ControllersScreenTable(SDL_Surface *screen , int Player );
void SaveInput( char jump[] ,char mouveR[] ,char mouveL[] ,char run[] ,char attack[] ,char *nomfichier);
void getInput(char *jump ,char *mouveR ,char *mouveL ,char *run ,char *attack ,char *nomfichier);


#endif