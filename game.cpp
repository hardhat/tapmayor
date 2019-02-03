#include <SDL.h>
#include "main.h"
#include "game.h"
#include "tile.h"
#include "font.h"
#include "sound.h"


Game game;

Game::Game() {
    tile=0;
    mode=0;
}

Game::~Game() {
}

void Game::resetGame()
{
    if(!tile) {
        tile=new Tile("icons/tapmayor.png",48,48);
    }
    if(!guiTile) {
        guiTile=new Tile("main.png",52,52,0);
    }

    setMode(MODE_TOWN);
}

void Game::update(int elapsed)
{
    if(screenMap.find(mode)!=screenMap.end()) {
        Screen *screen=screenMap[mode];

        screen->update(elapsed);
    } else {
        setMode(MODE_START);
    }
}

void Game::draw()
{
    if(screenMap.find(mode)!=screenMap.end()) {
        Screen *screen=screenMap[mode];

        screen->draw();
    } else {
        setMode(MODE_START);
    }
}

void Game::handleAction(int which,int id,bool down)
{
    if(screenMap.find(mode)!=screenMap.end()) {
        Screen *screen=screenMap[mode];

        screen->handleAction(which,id,down);
    } else {
        setMode(MODE_START);
    }
}

void Game::setMode(int newMode)
{
    mode=newMode;

    if(mode==MODE_START) resetGame();
}

void D(const char *format,const char *param) {
        FILE *log=fopen("log.txt","a");
        if(log) {
            fprintf(log,format,param);
            fclose(log);
        }
}

void D(const char *format,int param) {
        FILE *log=fopen("log.txt","a");
        if(log) {
            fprintf(log,format,param);
            fclose(log);
        }
}

void D(const char *format,float param) {
        FILE *log=fopen("log.txt","a");
        if(log) {
            fprintf(log,format,param);
            fclose(log);
        }
}
