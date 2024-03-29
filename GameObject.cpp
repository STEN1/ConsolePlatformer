#include "GameObject.h"

#include <thread>
#include <chrono>


GameObject::GameObject()
{
	DrawObject = false;
	GfxChar = '#';
	Location = { 0, 0 };
	CanvasLocation = { (int)Location.x, (int)Location.y };
	ObjectPhysicsType = PhysicsType::Static;
	ObjectID = ConsolePlatformer::GetUniqueID();
}

GameObject::GameObject(Vector2f Location)
{
	DrawObject = true;
	GfxChar = '#';
	this->Location = Location;
	CanvasLocation = { (int)Location.x, (int)Location.y };
	ObjectPhysicsType = PhysicsType::Static;
	ObjectID = ConsolePlatformer::GetUniqueID();

}

Vector2f GameObject::GetLocation()
{
	return Location;
}

void GameObject::SetLocation(Vector2f Location)
{
	this->Location = Location;
}

char GameObject::GetGfx()
{
	return GfxChar;
}

void GameObject::Update(float DeltaTime)
{
	//printf("GameObject\n");
	//std::this_thread::sleep_for(std::chrono::milliseconds((int)DeltaTime));
}

void GameObject::Start()
{
}

void GameObject::TouchFloor()
{
}

void GameObject::TouchWall()
{
}

int GameObject::GetObjectID()
{
	return ObjectID;
}
