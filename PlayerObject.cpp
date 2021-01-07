#include "PlayerObject.h"

#include <thread>
#include <chrono>


void PlayerObject::Movement()
{
	
}

PlayerObject::PlayerObject()
{

}

void PlayerObject::Update(float DeltaTime)
{
	Movement();
	printf("PlayerObject\n");
	std::this_thread::sleep_for(std::chrono::milliseconds((int)DeltaTime));
}