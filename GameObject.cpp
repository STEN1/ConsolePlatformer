#include "GameObject.h"

#include <thread>
#include <chrono>


GameObject::GameObject()
{
}

Vector2f* GameObject::GetLocation()
{
	return &Location;
}

void GameObject::SetLocation(Vector2f Location)
{
	this->Location = Location;
}

void GameObject::Update(float DeltaTime)
{
	printf("GameObject\n");
	std::this_thread::sleep_for(std::chrono::milliseconds((int)DeltaTime));
}