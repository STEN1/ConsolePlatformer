#pragma once

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject();

	virtual void Update(float DeltaTime) override;
	virtual void Start() override;
	virtual void TouchFloor() override;
	virtual void TouchWall() override;

	void Movement(float DeltaTime);
	void Jump(float DeltaTime);
	void GroundFriction(float DeltaTime);
	void GroundAccelerate(float DeltaTime);
	void AirAccelerate(float DeltaTime);
private:
	float MaxSpeed{ 20.f };
	bool IsGrounded{ false };
	float GroundAcceleration{ 200.f };
	float Friction{ 100.f };
	float AirAcceleration{ GroundAcceleration / 4.f };

	float JumpPower{ 20.f };
};

