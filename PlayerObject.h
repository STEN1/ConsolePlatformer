#pragma once

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject();

	virtual void Update(float DeltaTime) override;

	void Movement();
};

