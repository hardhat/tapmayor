#include <SDL.h>
#include "main.h"
#include "game.h"
#include "tile.h"
#include "font.h"
#include "sound.h"
#include "sprite.h"

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
        tile=new Tile("icons/tapmayor.png",48,48,10);
    }
    if(!guiTile) {
        guiTile=new Tile("main.png",52,52,0);
    }
    if(screenMap.find(MODE_START)==screenMap.end()) screenMap[MODE_START]=new Screen();
    if(screenMap.find(MODE_TOWN)==screenMap.end()) screenMap[MODE_TOWN]=new Screen();
	screenMap[MODE_START]->resetGame();
	screenMap[MODE_TOWN]->resetGame();

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
	drawMessage(FONT_HEADLINE,"Tap Mayor",0,0);
	drawMessage(FONT_BODY,"Build city. Trade goods. Keep citizens happy.",0,30);

	char buf[256];
	sprintf(buf,"Mode %d",mode);
	drawMessage(FONT_LABEL,buf,0,150);
	
	Sprite sprite("main.png");
	sprite.draw();

    if(screenMap.find(mode)!=screenMap.end()) {
        Screen *screen=screenMap[mode];

        screen->draw();
    } else {
        setMode(MODE_START);
    }
}

void Game::handleAction(int x,int y,int id,bool down)
{
    if(screenMap.find(mode)!=screenMap.end()) {
        Screen *screen=screenMap[mode];

        screen->handleAction(x,y,id,down);
    } else {
        setMode(MODE_START);
    }
}

void Game::handleMotion(int x,int y,bool down)
{
    if(screenMap.find(mode)!=screenMap.end()) {
        Screen *screen=screenMap[mode];

        screen->handleMotion(x,y,down);
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
