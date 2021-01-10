#include "PlayerObject.h"
#include "Input.h"

#include <thread>
#include <chrono>


PlayerObject::PlayerObject()
{
	DrawObject = true;
	GfxChar = '@';
	Location = { 30.f, 15.f };
	CanvasLocation = { (int)Location.x, (int)Location.y };
	ObjectPhysicsType = PhysicsType::Movable;
	ObjectID = ConsolePlatformer::GetUniqueID();
}

void PlayerObject::Movement()
{
	if (Input::W) Location.y += 0.1f;
	if (Input::A) Location.x -= 0.2f;
	if (Input::S) Location.y -= 0.1f;
	if (Input::D) Location.x += 0.2f;
}

void PlayerObject::Update(float DeltaTime)
{
	Movement();
	//printf("PlayerObject\n");
	//std::this_thread::sleep_for(std::chrono::milliseconds((int)DeltaTime));
}

void PlayerObject::Start()
{
}
