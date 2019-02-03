#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
	Screen();
	virtual ~Screen();

	virtual void resetGame();
	virtual void update(int elapsed);
	virtual void draw();
	virtual void handleAction(int x,int y,int id,bool down);
	virtual void handleMotion(int x,int y,bool down);
};

#endif
