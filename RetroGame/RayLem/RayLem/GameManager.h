#pragma once

#include "raylib.h"

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

private:

	int m_windowWidth = 1000;
	int m_windowHeight = 1000;

	static const int ROWS = 200;
	static const int COLS = 200;

	int m_tiles[ROWS][COLS];

	int m_tileWidth = 15;
	int m_tileHeight = 15;
};

