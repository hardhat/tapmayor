#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
	Screen();
	virtual ~Screen();

	virtual void resetGame();
	virtual void update(int elapsed);
	virtual void draw();
	virtual void handleAction(int which,int id,bool down);
};

#endif
