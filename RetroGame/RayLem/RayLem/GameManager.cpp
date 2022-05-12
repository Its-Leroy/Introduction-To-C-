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
	InitWindow(m_windowWidth, m_windowHeight, "Simple Tilemap");
	SetTargetFPS(60);

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
	for (int x = 0; x < ROWS; x++)
	{
		for (int i = 0; i < COLS; i++)
		{
			m_tiles[x][i] = rand() % 5; // Gets values between 0 to 5
		}
	}
}

void GameManager::Unload()
{

}

void GameManager::Update(float deltaTime)
{
	//if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	//{
	//	Vector2 mousePos = GetMousePosition();

	//	int mX = round(mousePos.x);
	//	int mY = round(mousePos.y);

	//	int rowIndex = round(mX / m_tileWidth);
	//	int colIndex = round(mY / m_tileHeight);

	//	int tileIndex = (rowIndex * COLS) + colIndex;

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
			Color color = GetBGTileColour(m_tiles[index]); // pass in the tilevalue
			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}

	}

	// --------------------------------------------------------------------

	EndDrawing();
}

Color GameManager::GetBGTileColour(int tileValue)
{
	switch (tileValue)
	{
	case 0: return BROWN;
	case 1: return BROWN;
	case 2: return DARKBROWN;
	case 3: return DARKBROWN;
	case 4: return BROWN;
	}

	return BLACK;
}