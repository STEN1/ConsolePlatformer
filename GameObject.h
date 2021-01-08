#pragma once

#include "ConsolePlatformer.h"

class GameObject
{
public:
	friend class Gfx;
	friend class Physics;

	GameObject();

	Vector2f GetLocation();
	void SetLocation(Vector2f Location);
	
	char GetGfx();

	virtual void Update(float DeltaTime);
	virtual void Start();

	int GetObjectID();
protected:
	int ObjectID;

	Vector2f Location;
	Vector2i CanvasLocation;
	bool DrawObject;
	char GfxChar;
	PhysicsType ObjectPhysicsType;
};

