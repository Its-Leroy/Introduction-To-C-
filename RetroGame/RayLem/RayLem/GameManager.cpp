#include "GameManager.h"
#include "raylib.h"
#include <stdlib.h>
#include <cmath>

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Space Spice Trader");
	SetTargetFPS(60);
	SetWindowIcon(windowIcon);
	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	Unload();
}

void GameManager::Load()
{
	pileORocks = LoadTexture("Star1.png");
	moon = LoadTexture("moon.png");
	smallMoon = LoadTexture("smallMoon.png");

	selectF1 = LoadTexture("select1.png");
	selectF2 = LoadTexture("select2.png");


	moonLocY = rand() % 3;
	moonLocX = rand() % 3;

	smallMoonLocY = rand() % 3;
	smallMoonLocX = rand() % 3;

	pileORocksLocY = rand() % 3;
	pileORocksLocX = rand() % 3;

	int temp = 1;
	for (int x = 0; x < ROWS; x++)
	{
		for (int i = 0; i < COLS; i++)
		{
			if (temp % 2 == 1)
			{
				m_tiles[x][i] = 0;
			}
			else
			{
				m_tiles[x][i] = 1;
			}

			temp++;
		}
		temp++;
	}

	
}

void GameManager::Unload()
{

}

void GameManager::Update(float deltaTime)
{

		//Vector2 mousePos = GetMousePosition();

		//int mX = round(mousePos.x);
		//int mY = round(mousePos.y);

		//int rowIndex = round(mX / m_tileWidth);
		//int colIndex = round(mY / m_tileHeight);

		//if(IsKeyPressed(KEY_LEFT))
		//BeginDrawing();
		//DrawTexture(
		//	pileORocks,
		//	(GetPileORocksLoc(rowIndex - 1)),
		//	(GetPileORocksLoc(colIndex)),
		//	RAYWHITE);
		//EndDrawing();

	//	m_tiles[tileIndex] += 1;

	//	if (m_tiles[tileIndex] >= 5)
	//		m_tiles[tileIndex] = 0;
	//}
}

void GameManager::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	for (int rowIndex = 0; rowIndex < ROWS; ++rowIndex)
	{

		for (int colIndex = 0; colIndex < COLS; colIndex++)
		{
			float xPos = rowIndex * m_tileWidth;
			float yPos = colIndex * m_tileHeight;
			int index = (rowIndex * COLS) + colIndex;
			Color color = GetBGTileColour(m_tiles[rowIndex][colIndex]); // pass in the tilevalue
			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}

	}

	DrawTexture(
		pileORocks,
		(GetPileORocksLoc(pileORocksLocX)) * m_tileWidth,
		(GetPileORocksLoc(pileORocksLocY)) * m_tileHeight,
		RAYWHITE);

	DrawTexture(
		moon,
		(GetMoonLocationLoc(moonLocX)) * m_tileWidth,
		(GetMoonLocationLoc(moonLocY)) * m_tileHeight,
		RAYWHITE);

	DrawTexture(
		smallMoon,
		(GetSmallMoonLoc(smallMoonLocX)) * m_tileWidth,
		(GetSmallMoonLoc(smallMoonLocY)) * m_tileHeight,
		RAYWHITE);



	// --------------------------------------------------------------------

	EndDrawing();
}


Color GameManager::GetBGTileColour(int tileValue)
{
	switch (tileValue)
	{
	case 0: return GRAY;
	case 1: return DARKGRAY;
	}

}

Color GameManager::GetGroundTileColour(int tileValue)
{
	switch (tileValue)
	{
	case 0: return GREEN;
	case 1: return DARKGREEN;
	case 2: return DARKGREEN;
	}
}

int GameManager::GetPileORocksLoc(int randomGen)
{
	switch (randomGen)
	{
	case 0: return 1;
	case 1: return 4;
	case 3: return 6;
	}
}
int GameManager::GetMoonLocationLoc(int randomGen)
{
	switch (randomGen)
	{
	case 0: return 2;
	case 1: return 8;
	case 3: return 3;
	}
}
int GameManager::GetSmallMoonLoc(int randomGen)
{
	switch (randomGen)
	{
	case 0: return 7;
	case 1: return 9;
	case 3: return 5;
	}
}
