CFLAGS=-g $(shell sdl2-config --cflags) -I/opt/local/include
CXXFLAGS=-DMAC -std=c++11 $(shell sdl2-config --cflags) -I/opt/local/include
LIBS=$(shell sdl2-config --libs) -lSDL2_image -lSDL2_mixer -lSDL2_ttf
OBJ=game.o main.o sound.o font.o sprite.o tile.o screen.o

dragonbattle: $(OBJ)
	g++ -o tapmayor $(OBJ) $(LIBS)

clean:
	-rm $(OBJ)

