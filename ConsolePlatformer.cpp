#include <iostream>
#include <vector>

#include "PlayerObject.h"
#include "Input.h"
#include "Gfx.h"

int main()
{
	std::vector<GameObject*> Objects;
	Objects.push_back(new PlayerObject);
	Objects.push_back(new GameObject);

	while (true)
	{
		system("cls");

		Input::GetInput();

		if (Input::W) std::cout << std::boolalpha << "Key W: " << std::endl;
		if (Input::A) std::cout << std::boolalpha << "Key A: " << std::endl;
		if (Input::S) std::cout << std::boolalpha << "Key S: " << std::endl;
		if (Input::D) std::cout << std::boolalpha << "Key D: " << std::endl;
		if (Input::Space) std::cout << std::boolalpha << "Key Space: " << std::endl;
		std::cout << Gfx::CanvasSize.x << " " << Gfx::CanvasSize.y << std::endl;

		for (auto& Object : Objects)
		{
			Object->Update(100.f);
		}

		for (auto& Object : Objects)
		{
			Gfx::DrawObject(Object);
		}

	}
}
