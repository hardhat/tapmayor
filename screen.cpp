#include "game.h"
#include "screen.h"
#include "sprite.h"

Screen::Screen()
{
	x=0;
	y=0;
	down=false;
}

Screen::~Screen()
{

}

void Screen::resetGame()
{

}

void Screen::update(int elapsed)
{

}

void Screen::draw()
{
	for(int i=0;i<40;i++) {
		int x=(i%8)*2;
		int y=(i/8)*2+3;
		game.tile->draw(i,x,y);
	}
	
	Sprite sprite("main.png");
	sprite.x=x;
	sprite.y=y;
	
	if(this->down) sprite.draw();
}

void Screen::handleAction(int x,int y,int id,bool down)
{
	printf("action %d @ %d,%d? %s\n",id,x,y,down?"down":"up");
	this->x=x;
	this->y=y;
	this->down=down;
}

void Screen::handleMotion(int x,int y,bool down)
{
	printf("motion @ %d,%d? %s\n",x,y,down?"down":"up");
}