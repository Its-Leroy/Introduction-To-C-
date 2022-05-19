#pragma once
#include "raylib.h"
#include <cmath>
class SpeechWindow
{
	
	public:

		SpeechWindow();
		~SpeechWindow();

		void Run();

	private:

		void Load();

		void Update(float deltaTime);

		void Draw();

		void Unload();

		Color GetBGTileColour(int titleValue);
		Color GetGroundTileColour(int titleValue);

	private:
		int m_windowWidth = 400;
		int m_windowHeight = 400;
		Image windowIcon = LoadImage("flamie.png");

	

};

