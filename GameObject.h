#pragma once

#include "ConsolePlatformer.h"

class GameObject
{
public:
	GameObject();

	Vector2f* GetLocation();
	void SetLocation(Vector2f Location);

	virtual void Update(float DeltaTime);
protected:
	Vector2f Location;
};

