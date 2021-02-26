#include "Headers/headers.h"

int main()
{
    int action = -1;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Surface *screen;
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Lunatics", NULL); //window title

    do
    {
        mainMenu(screen, &action);

        switch (action)
        {
        case 1: //player click on play
            /*
                gameplay not available yet
            */
            break;

        case 2: //player click on settings
            settingsMenu(screen, &action);

            break;

        case 3: //player click on credits
            /*
                credits cinematics under work
            */
            break;
        }
    } while (action != 0);

    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}