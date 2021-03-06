#ifndef GAME_H
#define GAME_H

#include <map>
#include <deque>

#include "screen.h"
#include "tile.h"

enum GameMode {
    MODE_TITLE,
    MODE_START,
    MODE_TOWN,
    MODE_MAP,
    MODE_CHAT,
    MODE_FRIEND,
    MODE_INCOME,
    MODE_INVENTORY,
    MODE_BUILD,
    MODE_QUEST,
    MODE_RESOURCES,
};

enum ButtonType {
    BUTTON_LEFT,
    BUTTON_MIDDLE,
    BUTTON_RIGHT,
};

typedef std::map<int,Screen *> ScreenMap;

class Game {
public:
    int mode;
    Tile *tile;
    Tile *guiTile;

    ScreenMap screenMap;    // Displays the active one according to the current mode.

    Game();
    ~Game();

    void resetGame();
    void setMode(int newMode);
    void update(int elapsed);
    void draw();
    void handleAction(int x,int y,int id,bool down);
    void handleMotion(int x,int y,bool down);
};

extern Game game;

void D(const char *format,const char *param);
void D(const char *format,int param);
void D(const char *format,float param);

#endif
