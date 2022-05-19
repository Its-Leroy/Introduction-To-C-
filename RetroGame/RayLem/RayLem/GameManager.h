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


private:
	int year = 3045;
	int money = 0;
	int spice = 1000;

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
	Texture2D blastdoor[8] = {};
	
	Texture2D currentDoor;
	int doorTemp = 0;

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

