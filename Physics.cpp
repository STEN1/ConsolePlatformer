#include "Physics.h"
#include "Gfx.h"


float Physics::GravityConstant = 9.81f;

void Physics::RestrictMovableToCanvas(GameObject* Object, std::vector<GameObject*> Objects)
{
	if (Object->ObjectPhysicsType != PhysicsType::Movable) return;

	if (Object->Location.y < 0.f) 
	{ 
		Object->Location.y = 0.f;
		Object->ySpeed = 0.f;
		Object->TouchFloor(); 
	}
	if (Object->Location.y > Gfx::CanvasSize.y - 1) Object->Location.y = Gfx::CanvasSize.y - 1;
	if (Object->Location.x < 1.f) 
	{
		Object->Location.x = 1.f;
		Object->TouchWall();
	}
	if (Object->Location.x > Gfx::CanvasSize.x - 1)
	{
		Object->Location.x = Gfx::CanvasSize.x - 1;
		Object->TouchWall();
	}
}

void Physics::ResolveStaticMovable(GameObject* Object, std::vector<GameObject*> Objects)
{
	if (Object->ObjectPhysicsType != PhysicsType::Static) return;

	for (auto& MovableObject : Objects)
	{
		if (Object->GetObjectID() == MovableObject->GetObjectID()) continue;
		if (MovableObject->ObjectPhysicsType != PhysicsType::Movable) continue;

		float PosXDelta = MovableObject->Location.x - Object->Location.x;
		float PosYDelta = MovableObject->Location.y - Object->Location.y;

		float ObjectSize = 0.8f;
		if (abs(PosXDelta) > ObjectSize || abs(PosYDelta) > ObjectSize) continue;

		if (abs(PosXDelta) > abs(PosYDelta)) // Move x out
		{
			MovableObject->TouchWall();
			if (PosXDelta < 0.f) // Move x left
			{
				MovableObject->Location.x = Object->Location.x - ObjectSize;
			}
			else // Move x Right
			{
				MovableObject->Location.x = Object->Location.x + ObjectSize;
			}
			MovableObject->xSpeed = 0.f;
		}
		else // Move y out
		{
			if (PosYDelta < 0.f) // Move y down
			{
				MovableObject->Location.y = Object->Location.y - ObjectSize;
			}
			else // Move y up
			{
				MovableObject->TouchFloor();
				MovableObject->Location.y = Object->Location.y + ObjectSize;
			}
			MovableObject->ySpeed = 0.f;
		}

	}
}

void Physics::GravityToMovable(GameObject* Object, float DeltaTime)
{
	if (Object->ObjectPhysicsType != PhysicsType::Movable) return;

	Object->ySpeed -= GravityConstant * DeltaTime;

}
