#include "Application.h"
#include "raylib.h"
#include <stdlib.h>
#include <cmath>


Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
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

void Application::Load()
{
	// Task1:
	// Initialise all values in m_tiles array to a random
	// value between 0 and 5 exclusive;
	// -----------------------------------------------------
	for (int i = 0; i < ROWS * COLS; i++)
	{
		m_tiles[i] = rand() % 5; // Gets values between 0 to 5
	}
	// -----------------------------------------------------
}

void Application::Unload()
{

}

void Application::Update(float deltaTime)
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Vector2 mousePos = GetMousePosition();

		// Task 3:
		// TODO: Calculate row and col index based on the mouse positon
		int mX = round(mousePos.x);
		int mY = round(mousePos.y);

		int rowIndex = round(mX / m_tileWidth);
		int colIndex = round(mY / m_tileHeight);


		// TODO: calculate the index of the tile clicked on, based on the row/col index
		int tileIndex = (rowIndex * COLS) + colIndex;

		m_tiles[tileIndex] += 1;

		if (m_tiles[tileIndex] >= 5) 
			m_tiles[tileIndex] = 0;
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// Task2:
	// use a nested loop to iterate over rows and columns
	// Use raylib's DrawRect method to draw each tile in the array.
	// 
	//
	// 	   use the row and col index multipled by m_tileHeight/m_tileWidth
	// 	   to calculate the x and y position for each rectangle.
	// 
	// change the color of the rect drawn based on the value of the tile.
	// 	   We have created a helper function you can use "GetTileColor"
	// --------------------------------------------------------------------
	// write your code here

	for (int rowIndex = 0; rowIndex < ROWS; ++rowIndex)
	{

		for ( int colIndex = 0 ; colIndex < COLS; colIndex++)
		{
			float xPos = rowIndex * m_tileWidth;
			float yPos = colIndex * m_tileHeight;
			int index = (rowIndex * COLS) + colIndex;
			Color color = GetTileColor(m_tiles[index]); // pass in the tilevalue
			DrawRectangle(xPos, yPos, m_tileWidth, m_tileHeight, color);
		}

	}

	// --------------------------------------------------------------------

	EndDrawing();
}

Color Application::GetTileColor(int tileValue)
{
	switch (tileValue)
	{
	case 0: return WHITE;
	case 1: return RED;
	case 2: return GREEN;
	case 3: return BLUE;
	case 4: return YELLOW;
	}
	
	return BLACK;
}