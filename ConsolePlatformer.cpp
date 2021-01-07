#include <iostream>
#include <vector>

#include "PlayerObject.h"
#include "Input.h"

int main()
{
	std::vector<GameObject*> Objects;
	Objects.push_back(new PlayerObject);
	Objects.push_back(new GameObject);

	while (true)
	{
		Input::GetInput();

		std::cout << std::boolalpha << "Key W: " << Input::W << std::endl;
		std::cout << std::boolalpha << "Key A: " << Input::A << std::endl;
		std::cout << std::boolalpha << "Key S: " << Input::S << std::endl;
		std::cout << std::boolalpha << "Key D: " << Input::D << std::endl;
		std::cout << std::boolalpha << "Key Space: " << Input::Space << std::endl;

		for (auto& Object : Objects)
		{
			Object->Update(500.f);
		}
	}
}
