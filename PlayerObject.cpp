#include "PlayerObject.h"
#include "Input.h"

#include <thread>
#include <chrono>


PlayerObject::PlayerObject()
{
	DrawObject = true;
	GfxChar = '@';
	Location = { 30.f, 15.f };
}

void PlayerObject::Movement()
{
	if (Input::W) Location.y += 1;
	if (Input::A) Location.x -= 1;
	if (Input::S) Location.y -= 1;
	if (Input::D) Location.x += 1;
}

void PlayerObject::Update(float DeltaTime)
{
	Movement();
	//printf("PlayerObject\n");
	//std::this_thread::sleep_for(std::chrono::milliseconds((int)DeltaTime));
}