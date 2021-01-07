#include "ConsoleHelp.h"
#include <Windows.h>

namespace ch {

	int ch::RowToY(int row, int mapSize)
	{
		return mapSize - (row + 1);
	}

	void SetCursorPosition(Pos pos)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = { (SHORT)pos.col, (SHORT)pos.row };
		SetConsoleCursorPosition(hOut, coord);
	}

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	void PutText(std::string s, Pos pos)
	{
		SetCursorPosition(pos);
		std::cout << s;
	}

	std::string setPrecision(double d, int precision)
	{
		std::string sin = std::to_string(d);
		std::string sout{ "" };
		bool countdown{ false };
		for (auto& c : sin)
		{
			sout += c;
			if (countdown) precision--;
			if (c == '.') countdown = true;
			if (precision == 0) break;
		}
		return sout;
	}

	int letterToNumber(char letter)
	{
		int i = static_cast<int>(letter);
		if (i > 64 && i < 91)
			i -= 64;
		else if (i > 96 && i < 123)
			i -= 96;
		else if (i > 47 && i < 58)
			i -= 48;
		else
			i = 0;
		return i;
	}

	std::string getString() {
		std::string s;
		do {
			std::cin.clear();
			if (std::cin.peek() == static_cast<int>('\n') || std::cin.peek() == static_cast<int>(' ')) {
				std::cin.ignore(32767, '\n');
			}
			std::getline(std::cin, s);
		} while (std::cin.fail());
		return s;
	}

	int getInt() {
		int i;
		std::cin >> i;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cin >> i;
		}
		return i;
	}

	long getLong() {
		long l;
		std::cin >> l;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cin >> l;
		}
		return l;
	}

	std::string colorText(std::string text, int textColor) {

		// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

		return "\033[" + std::to_string(textColor) + 'm' + text + "\033[0m";
	}

	std::string colorText(char text, int textColor) {

		// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors

		return "\033[" + std::to_string(textColor) + 'm' + text + "\033[0m";
	}
}
