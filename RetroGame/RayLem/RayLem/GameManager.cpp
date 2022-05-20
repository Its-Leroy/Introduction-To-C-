#include "GameManager.h"
#include "SpeechWindow.h"
#include "raylib.h"
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string>

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::Run()
{
	InitWindow(m_windowWidth, m_windowHeight, "Deep Space Spice Trader!");
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
	money *= rand() % 250 + 1;


	SpeechWindow SW;


	pileORocks = LoadTexture("Star1.png");
	moon = LoadTexture("moon.png");
	smallMoon = LoadTexture("smallMoon.png");

	port = LoadTexture("characterPort.png");
	HUD1 = LoadTexture("characterHUD1.png");
	HUD2 = LoadTexture("characterHUD2.png");
	HUD3 = LoadTexture("characterHUD3.png");

	FRAME1 = LoadTexture("borderFrame1.png");
	FRAME2 = LoadTexture("borderFrame2.png");
	FRAME3 = LoadTexture("borderFrame3.png");
	FRAME4 = LoadTexture("borderFrame4.png");
	FRAME5 = LoadTexture("borderFrame5.png");
	FRAME6 = LoadTexture("borderFrame6.png");
	FRAME7 = LoadTexture("borderFrame7.png");

	blastdoorF1 = LoadTexture("blastDoorF1.png");
	blastdoorF2 = LoadTexture("blastDoorF2.png");
	blastdoorF3 = LoadTexture("blastDoorF3.png");
	blastdoorF4 = LoadTexture("blastDoorF4.png");
	blastdoorF5 = LoadTexture("blastDoorF5.png");
	blastdoorF6 = LoadTexture("blastDoorF6.png");
	blastdoorF7 = LoadTexture("blastDoorF7.png");
	blastdoorF8 = LoadTexture("blastDoorF8.png");

	Texture2D blastdoor[8] = {blastdoorF1 , blastdoorF2 , blastdoorF3 , blastdoorF4 , 
								blastdoorF5 ,blastdoorF6 ,blastdoorF7 ,blastdoorF8};
	currentDoor = blastdoor[0];

	selectF1 = LoadTexture("select1.png");
	selectF2 = LoadTexture("select2.png");
	alienPC = LoadTexture("alien.png");
	spaceShip = LoadTexture("aliensShip.png");


	alienRace = LoadTexture("alienRace.png");


	moonLocY = rand() % 3;
	moonLocX = rand() % 3;

	smallMoonLocY = rand() % 3;
	smallMoonLocX = rand() % 3;

	pileORocksLocY = rand() % 3;
	pileORocksLocX = rand() % 3;

	for (int x = 0; x < ROWS; x++)
	{
		for (int i = 0; i < COLS; i++)
		{
				m_tiles[x][i] = 0;
		}
	}

	
}

void GameManager::Unload()
{

}

void GameManager::Update(float deltaTime)
{
	timer += deltaTime;
	doorTimer += deltaTime;

	Vector2 mousePos = GetMousePosition();

	int mX = round(mousePos.x);
	int mY = round(mousePos.y);

	int rowIndex = round(mX / m_tileWidth);
	int colIndex = round(mY / m_tileHeight);

	tileIndexY = (rowIndex / COLS) + colIndex;
	tileIndexX = (colIndex / ROWS) + rowIndex;
		
	if (tileIndexY > 9) { tileIndexY = 9; }
	if (tileIndexX > 9) { tileIndexX = 9; }

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		spaceShipPathX = tileIndexX;
		spaceShipPathY = tileIndexY;
		std::cout << "mouse x: " << mX << std::endl;
		std::cout << "mouse y: " << mY << std::endl;
		std::cout << "tile index Y: " << tileIndexY<< std::endl;
		std::cout << "tile index X: " << tileIndexX << std::endl;
		std::cout << GetMoonLocationLoc(moonLocX) << std::endl;
		std::cout << GetMoonLocationLoc(moonLocY) << std::endl;
	}



	if (timer > 0.09f)
	{
		if (spaceShipY != spaceShipPathY)
		{
			if (spaceShipY >= spaceShipPathY)
			{
				spaceShipY -= 1;
				year += rand() % 20 + 1;
				moonDemand = rand() % 3 + 1;
				moonFlux = rand() % 5;

				if (moonDemand = true)
				{
					moonAlienSellPrice += moonFlux;
				}

				if (moonDemand == 2 || moonDemand == 3)
				{
					if (moonAlienSellPrice - 10 > 0)
					{
						moonAlienSellPrice -= 10;
					}
				}

				spice -= 1;
			}
			else if (spaceShipY <= spaceShipPathY)
			{
				spaceShipY += 1;
				year += rand() % 20 + 1;
				spice -= 1;

				moonDemand = rand() % 3 + 1;
				moonFlux = rand() % 5;

				if (moonDemand = true)
				{
					moonAlienSellPrice += moonFlux;
				}

				if (moonDemand == 2 || moonDemand == 3)
				{
					if (moonAlienSellPrice - 10 > 0)
					{
						moonAlienSellPrice -= 10;
					}
				}
			}
		}
		if (spaceShipY == spaceShipPathY && spaceShipX != spaceShipPathX)
		{
			if (spaceShipX > spaceShipPathX)
			{
				spaceShipX -= 1;
				year += rand() % 20 + 1;
				spice -= 1;

				moonDemand = rand() % 3 + 1;
				moonFlux = rand() % 5;

				if (moonDemand = true)
				{
					moonAlienSellPrice += moonFlux;
				}

				if (moonDemand == 2 || moonDemand == 3)
				{
					if (moonAlienSellPrice - 10 > 0)
					{
						moonAlienSellPrice -= 10;
					}
				}
			}
			else if (spaceShipX < spaceShipPathX)
			{
				spaceShipX += 1;
				year += rand() % 20 + 1;
				spice -= 1;

				moonDemand = rand() % 3 + 1;
				moonFlux = rand() % 5;

				if (moonDemand == 1)
				{
					moonAlienSellPrice += moonFlux;
				}

				if (moonDemand == 2 || moonDemand == 3)
				{
					if (moonAlienSellPrice - 10 > 0)
					{
						moonAlienSellPrice -= 10;
					}
				}
			}
		}

		timer = 0;
	}

	if (doorTimer > 0.25f)
	{
		if (menuFlag3 == 1)
		{
			if (spaceShipY == (GetMoonLocationLoc(moonLocY)) && spaceShipX == (GetMoonLocationLoc(moonLocX)))
			{
				if (IsKeyPressed(KEY_F5))
				{
					if (money - moonAlienSellPrice >= 0)
					{
						spice++;
						money -= moonAlienSellPrice;
					}
				}
				if (IsKeyPressed(KEY_F6))
				{
					if (spice > 0)
					{
						spice--;
						money += moonAlienSellPrice;
					}
				}
				trading = true;
				if (doorTemp != 7)
				{
					doorTemp += 1;
				}
			}
			else
			{
				doorTemp = 0;
				trading = false;
			}
		}
		else if (menuFlag3 == 0)
		{
			
			if (spaceShipY == (GetMoonLocationLoc(moonLocY)) && spaceShipX == (GetMoonLocationLoc(moonLocX)))
			{
				menuFlag3 = 2;

				if (doorTemp != 0)
				{
					menuFlag3 = 0;
					doorTemp -= 1;
				}	
			}
			else
			{
				doorTemp = 0;
			}
		}
		else
		{
			menuFlag3 = 0;
		}

		doorTimer = 0;
	}

	if (menuFlag1 == 1)
	{
		
	}

	if (IsKeyPressed(KEY_F1))
	{
		menuFlag1 = 1;
		menuFlag2 = 0;
		menuFlag3 = 0;
	}
	else if (IsKeyPressed(KEY_F2))
	{
		menuFlag1 = 0;
		menuFlag2 = 1;
		menuFlag3 = 0;
	}
	else if (IsKeyPressed(KEY_F3))
	{
		menuFlag1 = 0;
		menuFlag2 = 0;
		menuFlag3 = 1;
	}
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

	// CHARACTER DRAW
	DrawTexture(
		spaceShip,
		spaceShipX * m_tileWidth,
		spaceShipY * m_tileHeight,
		RAYWHITE);
	

	DrawRectangle(0, 10 * m_tileHeight, m_tileWidth * 2, m_tileHeight * 2, BLACK);
	
	DrawTexture(
		alienPC,
		0 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);

	DrawTexture(
		port,
		0 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);

	// under the HUD

	std::string notyear = std::to_string(year);
	DrawText("MOM OS", 2.5 * m_tileWidth, 10.2f * m_tileHeight, 3, GREEN);
	DrawText("Current Year: ", 2.5 * m_tileWidth + 125, 10.2f * m_tileHeight, 3, GREEN);
	DrawText(notyear.c_str(), 4 * m_tileWidth + 125, 10.2f * m_tileHeight, 3, GREEN);

	DrawText("_________________________________________", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 5, 3, GREEN);

	/*std::string notMoney = std::to_string(money);*/
	if (menuFlag1 == 1)
	{
		DrawText("[Credits F1] ", 2.5 * m_tileWidth + 10, 10.2f * m_tileHeight + 15, 3, BLUE);
		std::string notMoney = std::to_string(money);

		if (money <= 100)
		{
			DrawText("Consider bankrupty...", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 35, 3, GREEN);
		}
		else if  (money > 100 && money <= 1000)
		{
			DrawText("It's not much but it's enough to keep going.", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 35, 3, GREEN);
		}
		else if (money > 1000 && spice <= 25000)
		{
			DrawText("Continue growing the empire, we need more money.", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 35, 3, GREEN);
		}
		else if (spice < 25000)
		{
			DrawText("BUY! BUY! SELL! SELL! You know the drill.", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 40, 3, GREEN);
		}
		DrawText("Credits: ", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 50, 20, GREEN);
		DrawText(notMoney.c_str(), 2.5 * m_tileWidth + 85, 10.2f * m_tileHeight + 50, 20, BLUE);
	}
	else if (menuFlag1 == 0)
	{
		DrawText("[Credits F1] ", 2.5 * m_tileWidth + 10, 10.2f * m_tileHeight + 15, 3, GREEN);
	}


	if (menuFlag2 == 1)
	{
		DrawText("[Storage F2] ", 2.5 * m_tileWidth + 72, 10.2f * m_tileHeight + 15, 3, BLUE);
		std::string notSpice = std::to_string(spice);
		if (spice <= 1000)
		{
			DrawText("Space empires have to start somewhere... right? ", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 35, 3, GREEN);
		}
		else if (spice > 1000 && spice <= 5000)
		{
			DrawText("It's starting to get a little crowded in here..", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 35, 3, GREEN);
		}
		else if (spice > 5000 && spice <= 25000)
		{
			DrawText("Expansions to the cargo bay are complete.", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 35, 3, GREEN);
		}
		DrawText("Your spice: ", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 50, 20, GREEN);
		DrawText(notSpice.c_str(), 2.5 * m_tileWidth + 120, 10.2f * m_tileHeight + 50, 20, BLUE);
	}
	else if (menuFlag2 == 0)
	{
		DrawText("[Storage F2] ", 2.5 * m_tileWidth + 72, 10.2f * m_tileHeight + 15, 5, GREEN);
	}


	if (menuFlag3 == 1)
	{
		DrawText("[Communication F3] ", 2.5 * m_tileWidth + 142, 10.2f * m_tileHeight + 15, 3, BLUE);
		if (trading == true)
		{
			DrawText("Greetings Captain, we're selling & buying for: ", 2.5 * m_tileWidth + 5, 10.2f * m_tileHeight + 30, 3, GREEN);

			std::string notSelling = std::to_string(moonAlienSellPrice);
			DrawText("Price: ", 2.5 * m_tileWidth + 5, 10.2f * m_tileHeight + 40, 20, GREEN);
			DrawText(notSelling.c_str(), 2.5 * m_tileWidth + 70, 10.2f * m_tileHeight + 40, 20, BLUE);

			DrawText("[Buy  F5] ", 2.8 * m_tileWidth + 51, 10.2f * m_tileHeight + 65, 3, GREEN);
			DrawText("[Sell F6] ", 2.8 * m_tileWidth + 102, 10.2f * m_tileHeight + 65, 3, GREEN);
		}

	}
	else if (menuFlag3 == 0)
	{
		DrawText("[Communication F3] ", 2.5 * m_tileWidth + 142, 10.2f * m_tileHeight + 15, 3, GREEN);
	}
	else if (menuFlag3 == 2)
	{
		DrawText("[Communication F3] ", 2.5 * m_tileWidth + 142, 10.2f * m_tileHeight + 15, 3, DARKGREEN);
	}




	//DrawText(notMoney.c_str(), 2.5 * m_tileWidth + 90, 10.2f * m_tileHeight + 10, 3, BLUE);
;

	DrawText("_________________________________________", 2.5 * m_tileWidth, 10.2f * m_tileHeight + 19, 3, GREEN);


	

	
	// HUD
	DrawTexture(
		HUD1,
		2 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);

	DrawTexture(
		HUD2,
		4 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);

	DrawTexture(
		HUD3,
		6 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);

	// other alien

	DrawTexture(
		alienPC,
		8 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);


	if (doorTemp == 0)
	{
		DrawTexture(
			blastdoorF1,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 1)
	{
		DrawTexture(
			blastdoorF2,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 2)
	{
		DrawTexture(
			blastdoorF3,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 3)
	{
		DrawTexture(
			blastdoorF4,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 4)
	{
		DrawTexture(
			blastdoorF5,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 5)
	{
		DrawTexture(
			blastdoorF6,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 6)
	{
		DrawTexture(
			blastdoorF7,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}
	else if (doorTemp == 7)
	{
		DrawTexture(
			blastdoorF8,
			8 * m_tileWidth,
			10 * m_tileHeight,
			RAYWHITE);
	}



	DrawTexture(
		port,
		8 * m_tileWidth,
		10 * m_tileHeight,
		RAYWHITE);

	DrawTexture(
		FRAME1,
		9 * m_tileWidth,
		9 * m_tileHeight,
		RAYWHITE);
	
	for (int i = 1; i < 9; i++)
	{
		DrawTexture(
			FRAME2,
			9 * m_tileWidth,
			i * m_tileHeight,
			RAYWHITE);
	}

	DrawTexture(
		FRAME3,
		9 * m_tileWidth,
		0 * m_tileHeight,
		RAYWHITE);

	for (int i = 1; i < 9; i++)
	{
		DrawTexture(
			FRAME5,
			i * m_tileWidth,
			0 * m_tileHeight,
			RAYWHITE);
	}

	DrawTexture(
		FRAME4,
		0 * m_tileWidth,
		0 * m_tileHeight,
		RAYWHITE);

	for (int i = 1; i < 9; i++)
	{
		DrawTexture(
			FRAME7,
			0 * m_tileWidth,
			i * m_tileHeight,
			RAYWHITE);
	}

	DrawTexture(
		FRAME6,
		0 * m_tileWidth,
		9 * m_tileHeight,
		RAYWHITE);

	// SELECT
	DrawTexture(
		selectF1,
		tileIndexX * m_tileWidth,
		tileIndexY * m_tileHeight,
		RAYWHITE);


	// --------------------------------------------------------------------

	EndDrawing();
}


Color GameManager::GetBGTileColour(int tileValue)
{
	switch (tileValue)
	{
	case 0: return BLACK;
	case 1: return DARKGRAY;
	case 2: return BLACK;
	}

}

Color GameManager::GetGroundTileColour(int tileValue)
{
	switch (tileValue)
	{
	case 0: return GRAY;
	case 1: return GRAY;
	}
}

int GameManager::GetPileORocksLoc(int randomGen)
{
	switch (randomGen)
	{
	case 0: return 0;
	case 1: return 3;
	case 3: return 6;
	}
}
int GameManager::GetMoonLocationLoc(int randomGen)
{
	switch (randomGen)
	{
	case 0: return 1;
	case 1: return 4;
	case 3: return 7;
	}
}
int GameManager::GetSmallMoonLoc(int randomGen)
{
	switch (randomGen)
	{
	case 0: return 2;
	case 1: return 5;
	case 3: return 8;
	}
}
