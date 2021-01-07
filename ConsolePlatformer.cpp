#include <iostream>
#include <vector>

#include "PlayerObject.h"


int main()
{
	std::vector<GameObject*> Objects;
	Objects.push_back(new PlayerObject);
	Objects.push_back(new GameObject);

	while (true)
	{
		for (auto& Object : Objects)
		{
			Object->Update(500.f);
		}
	}
}
