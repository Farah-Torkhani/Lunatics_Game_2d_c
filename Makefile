lunatics:main.o menu.o settings.o gameMode.o credits.o gamedifficulty.o selectchamp.o stage1.o background.o perso.o input.o enemy.o enigme_avec_fichier.o enigme_sans_fichier.o new_or_load_game.o gameover.o
	gcc main.o menu.o settings.o gameMode.o credits.o gamedifficulty.o selectchamp.o stage1.o background.o perso.o input.o enemy.o enigme_avec_fichier.o enigme_sans_fichier.o new_or_load_game.o gameover.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o lunatics -g; ./lunatics
main.o:main.c
	gcc -c main.c -g
menu.o:menu.c
	gcc -c menu.c -g
settings.o:settings.c
	gcc -c settings.c -g
gameMode.o:gameMode.c
	gcc -c gameMode.c -g
credits.o:credits.c
	gcc -c credits.c -g 
gamedifficulty.o:gamedifficulty.c
	gcc -c gamedifficulty.c -g 
selectchamp.o:selectchamp.c
	gcc -c selectchamp.c -g 



