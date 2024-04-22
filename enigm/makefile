game: main.o enigme.o
	gcc main.o enigme.o -o game -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
	rm -f *.o
	./game

main.o: main.c
	gcc -c main.c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

enigme.o: enigme.c
	gcc -c enigme.c  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g



