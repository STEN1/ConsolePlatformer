#pragma once
#include <string>
#include <iostream>
#include "ConsolePlatformer.h"

struct Pos
{
	int row{ 0 };
	int col{ 0 };
};

namespace ch {

	int RowToY(int row, int mapSize);

	void PutText(std::string s, Vector2i pos);

	void SetCursorPosition(Vector2i pos);

	void ShowConsoleCursor(bool showFlag);

	std::string setPrecision(double d, int precision);

	int letterToNumber(char letter);

	std::string getString();

	int getInt();

	long getLong();

	std::string colorText(std::string text, int textColor);

	std::string colorText(char text, int textColor);
}

//#include <Windows.h>
//
//void ShowConsoleCursor(bool showFlag)
//{
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	CONSOLE_CURSOR_INFO     cursorInfo;
//
//	GetConsoleCursorInfo(out, &cursorInfo);
//	cursorInfo.bVisible = showFlag; // set the cursor visibility
//	SetConsoleCursorInfo(out, &cursorInfo);
//}
