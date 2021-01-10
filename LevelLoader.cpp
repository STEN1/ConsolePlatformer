#include "LevelLoader.h"
#include "Gfx.h"
#include "ConsoleHelp.h"

void LoadLevel(std::vector<GameObject*> &Objects, std::string Level)
{
	std::ifstream LevelFile(Level);

	int row{ 0 };
	while (!LevelFile.eof())
	{
		std::string s;
		std::getline(LevelFile, s);

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '#')
			{
				Objects.push_back(new GameObject({ (float)i, (float)ch::RowToY(row, Gfx::CanvasSize.y) }));
			}
		}
		row++;
	}
}
