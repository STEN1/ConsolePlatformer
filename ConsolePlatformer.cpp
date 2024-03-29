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
#include "LevelLoader.h"

int ConsolePlatformer::IDcounter = 0;

int main()
{
	ch::ShowConsoleCursor(false);
	std::vector<GameObject*> Objects;
	Objects.push_back(new PlayerObject);

	LoadLevel(Objects, "Map.txt");

	for (auto& Object : Objects)
	{
		Object->Start();
	}

	Gfx::DrawBoarder();
	int DeltaTimeMilliseconds = 25;
	float DeltaTime = (float)DeltaTimeMilliseconds / 1000.f;
	while (true)
	{
		// Timing
		std::this_thread::sleep_for(std::chrono::milliseconds(DeltaTimeMilliseconds));
		
		// Input
		Input::GetInput();

		// DebugLog
		ch::SetCursorPosition({ 0, 0 });
		std::cout << std::boolalpha << "Key W: " << Input::W << "      " << std::endl;
		std::cout << std::boolalpha << "Key A: " << Input::A << "      " << std::endl;
		std::cout << std::boolalpha << "Key S: " << Input::S << "      " << std::endl;
		std::cout << std::boolalpha << "Key D: " << Input::D << "      " << std::endl;
		std::cout << std::boolalpha << "Key Space: " << Input::Space << "      " << std::endl;
		std::cout << Objects.at(0)->GetXSpeed() << " " << Objects.at(0)->GetYSpeed() << "      " << std::endl;
		std::cout << Objects.at(0)->GetLocation().x << " " << Objects.at(0)->GetLocation().y << "      " << std::endl;

		// Run main logic
		for (auto& Object : Objects)
		{
			Object->Update(DeltaTime);
		}

		// Physics?? :)
		for (auto& Object : Objects)
		{
			Physics::GravityToMovable(Object, DeltaTime);
			Physics::RestrictMovableToCanvas(Object, Objects);
			Physics::ResolveStaticMovable(Object, Objects);
		}

		// Draw the screen
		for (auto& Object : Objects)
		{
			Gfx::DrawObject(Object);
		}

	}
}
