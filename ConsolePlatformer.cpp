#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "PlayerObject.h"
#include "Input.h"
#include "Gfx.h"
#include "Physics.h"
#include "ConsoleHelp.h"
#include "ConsolePlatformer.h"

int ConsolePlatformer::IDcounter = 0;

int main()
{
	ch::ShowConsoleCursor(false);
	std::vector<GameObject*> Objects;
	Objects.push_back(new GameObject);
	Objects.push_back(new PlayerObject);

	for (auto& Object : Objects)
	{
		Object->Start();
	}

	Gfx::DrawBoarder();

	while (true)
	{
		// Timing
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
		// Input
		Input::GetInput();

		// DebugLog
		ch::SetCursorPosition({ 0, 0 });
		std::cout << std::boolalpha << "Key W: " << Input::W << std::endl;
		std::cout << std::boolalpha << "Key A: " << Input::A << std::endl;
		std::cout << std::boolalpha << "Key S: " << Input::S << std::endl;
		std::cout << std::boolalpha << "Key D: " << Input::D << std::endl;
		std::cout << std::boolalpha << "Key Space: " << Input::Space << std::endl;
		std::cout << Gfx::CanvasSize.x << " " << Gfx::CanvasSize.y << std::endl;

		// Run main logic
		for (auto& Object : Objects)
		{
			Object->Update(100.f);
		}

		// Physics?? :)
		for (auto& Object : Objects)
		{
			Physics::Resolve(Object, Objects);
		}

		// Draw the screen
		for (auto& Object : Objects)
		{
			Gfx::DrawObject(Object);
		}

	}
}
