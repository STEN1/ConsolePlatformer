#pragma once

#include "ConsolePlatformer.h"

class GameObject
{
public:
	friend class Gfx;
	friend class Physics;

	GameObject();
	GameObject(Vector2f Location);

	Vector2f GetLocation();
	void SetLocation(Vector2f Location);
	
	char GetGfx();
	float GetXSpeed()
	{
		return xSpeed;
	}
	float GetYSpeed()
	{
		return ySpeed;
	}

	virtual void Update(float DeltaTime);
	virtual void Start();

	virtual void TouchFloor();
	virtual void TouchWall();

	int GetObjectID();
protected:
	int ObjectID;

	float xSpeed{ 0 };
	float ySpeed{ 0 };

	Vector2f Location;
	Vector2i CanvasLocation;
	bool DrawObject;
	char GfxChar;
	PhysicsType ObjectPhysicsType;
};

