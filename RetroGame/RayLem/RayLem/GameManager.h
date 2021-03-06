#pragma once
#include "SpeechWindow.h"
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

	bool IsSomeoneThere(int x, int y);
	void WhosThere(int x, int y);
	int GetPrice(int alienRef);
	int currentAlien = 0;

private:
	int year = 3045;
	int money = 5;
	int spice = 150;
	bool trading = false;
	


	int moonDemand;
	int moonFlux;


	int moonAlienSellPrice = 12;
	int invaderSellPrice = 20;
	int alfSellPrice = 50;
	int tempPrice;

	int spiceB;
	Texture2D Nova;

	Texture2D pileORocks;
	Texture2D moon;
	Texture2D smallMoon;
	Texture2D selectF1;
	Texture2D selectF2;

	Texture2D port;
	Texture2D alienPC;
	Texture2D alienRace;
	Texture2D spaceShip;

	Texture2D HUD1;
	Texture2D HUD2;
	Texture2D HUD3;

	Texture2D FRAME1;
	Texture2D FRAME2;
	Texture2D FRAME3;
	Texture2D FRAME4;
	Texture2D FRAME5;
	Texture2D FRAME6;
	Texture2D FRAME7;


	Texture2D blastdoorF1;
	Texture2D blastdoorF2;
	Texture2D blastdoorF3;
	Texture2D blastdoorF4;
	Texture2D blastdoorF5;
	Texture2D blastdoorF6;
	Texture2D blastdoorF7;
	Texture2D blastdoorF8;
	
	Texture2D currentDoor;

	Texture2D invaderF1;
	Texture2D invaderF2;
	Texture2D invaderF3;
	Texture2D invaderF4;

	Texture2D alfF1;
	Texture2D alfF2;
	Texture2D alfF3;
	Texture2D alfF4;
	Texture2D alfF5;
	Texture2D alfF6;

	Texture2D catF1;
	Texture2D catF2;

	Texture2D alienF1;
	Texture2D alienF2;
	Texture2D alienF3;

	int invaderTemp = 0;
	int alfTemp = 0;
	int catTemp = 0;
	int alienTemp = 0;

	int menuFlag1 = 1;
	int menuFlag2 = 0;
	int menuFlag3 = 0;

	int doorTemp = 0;

	bool ending = false;
	int scale = 0;
	int moonLocY;
	int moonLocX;

	int smallMoonLocY;
	int smallMoonLocX;

	int pileORocksLocY;
	int pileORocksLocX;


	int m_windowWidth = 500;
	int m_windowHeight = 600;
	SpeechWindow SW;
	Image windowIcon = LoadImage("flamie.png");

	static const int ROWS = 10;
	static const int COLS = 12;

	int m_tiles[ROWS][COLS];

	int m_tileWidth = 50;
	int m_tileHeight = 50;

	int tileIndexY;
	int tileIndexX;

	int spaceShipY = 5;
	int spaceShipX = 5;
	int spaceShipPathY = spaceShipY;
	int spaceShipPathX = spaceShipX;

	float timer = 0;
	float doorTimer = 0;
};

