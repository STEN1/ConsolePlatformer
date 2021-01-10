#include "PlayerObject.h"
#include "Input.h"
#include "Physics.h"

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

void PlayerObject::Movement(float DeltaTime)
{
	if (IsGrounded)
	{
		GroundFriction(DeltaTime);
		GroundAccelerate(DeltaTime);
	}
	else
	{
		AirAccelerate(DeltaTime);
	}

	Location.x += xSpeed * DeltaTime;
	Location.y += ySpeed * DeltaTime;
}

void PlayerObject::Jump(float DeltaTime)
{
	if (!Input::Space && ySpeed > 0.f)
	{
		ySpeed -= (Physics::GravityConstant * 2.f) * DeltaTime;
	}
	if (ySpeed <= 0.f)
	{
		ySpeed -= (Physics::GravityConstant * 2.f) * DeltaTime;
	}
	if (Input::Space && IsGrounded)
	{
		ySpeed = JumpPower;
		IsGrounded = false;
	}
}

void PlayerObject::GroundFriction(float DeltaTime)
{
	if (xSpeed == 0.f) return;
	if (xSpeed < 0.f) xSpeed += Friction * DeltaTime;
	else xSpeed -= Friction * DeltaTime;
}

void PlayerObject::GroundAccelerate(float DeltaTime)
{
	if (Input::A && xSpeed > -MaxSpeed) xSpeed -= GroundAcceleration * DeltaTime;
	if (Input::D && xSpeed < MaxSpeed) xSpeed += GroundAcceleration * DeltaTime;
}

void PlayerObject::AirAccelerate(float DeltaTime)
{
	if (Input::A && xSpeed > -MaxSpeed) xSpeed -= AirAcceleration * DeltaTime;
	if (Input::D && xSpeed < MaxSpeed) xSpeed += AirAcceleration * DeltaTime;
}

void PlayerObject::Update(float DeltaTime)
{
	Jump(DeltaTime);

	Movement(DeltaTime);
	//printf("PlayerObject\n");
	//std::this_thread::sleep_for(std::chrono::milliseconds((int)DeltaTime));
}

void PlayerObject::Start()
{
}

void PlayerObject::TouchFloor()
{
	IsGrounded = true;
}

void PlayerObject::TouchWall()
{
	xSpeed = 0.f;
}
