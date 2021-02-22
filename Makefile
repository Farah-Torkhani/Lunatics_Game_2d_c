lunatics:*.c Headers/*.h
	gcc Headers/*.h *.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o lunatics -g
	./lunatics
