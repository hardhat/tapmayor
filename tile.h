#ifndef TILE_H
#define TILE_H

class Tile {
public:
	int tileWidth,tileHeight,spacing;
	int imageId;

	Tile(const char *filename,int tileWidth,int tileHeight,int spacing=0);
	~Tile();
	void draw(int id,int col,int row);
};

#endif
