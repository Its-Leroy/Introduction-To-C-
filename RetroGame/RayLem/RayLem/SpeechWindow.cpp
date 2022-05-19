#include "SpeechWindow.h"
#include "raylib.h"
#include <stdlib.h>
#include <cmath>

SpeechWindow::SpeechWindow()
{

}

SpeechWindow::~SpeechWindow()
{

}

void SpeechWindow::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Emperor Xizzle Calling!");
	SetTargetFPS(60);
	SetWindowIcon(windowIcon);
	Load();

	while (!WindowShouldClose())
	{
		Update(GetFrameTime());
		Draw();
	}

	if(WindowShouldClose() == true)
	{
		 CloseWindow();
	}

	Unload();
}
void SpeechWindow::Load()
{

}
void SpeechWindow::Unload()
{

}

void SpeechWindow::Update(float deltaTime)
{

}

void SpeechWindow::Draw()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);

	// --------------------------------------------------------------------

	EndDrawing();
}

