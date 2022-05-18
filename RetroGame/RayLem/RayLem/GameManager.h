#pragma once

#include "raylib.h"
#include <cmath>

class GameManager
{
public:
	
	GameManager();
	~GameManager();

	void Run();

private:

	void Load();

	void Update(float deltaTime);

	void Draw();

	void Unload();

	Color GetBGTileColour(int titleValue);
	Color GetGroundTileColour(int titleValue);




	int GetPileORocksLoc(int randomGen);
	int GetMoonLocationLoc(int randomGen);
	int GetSmallMoonLoc(int randomGen);


private:

	Texture2D pileORocks;
	Texture2D moon;
	Texture2D smallMoon;
	Texture2D selectF1;
	Texture2D selectF2;


	int moonLocY;
	int moonLocX;

	int smallMoonLocY;
	int smallMoonLocX;

	int pileORocksLocY;
	int pileORocksLocX;


	int m_windowWidth = 500;
	int m_windowHeight = 500;
	Image windowIcon = LoadImage("flamie.png");

	static const int ROWS = 10;
	static const int COLS = 10;

	int m_tiles[ROWS][COLS];

	int m_tileWidth = 50;
	int m_tileHeight = 50;
};

