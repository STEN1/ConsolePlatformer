#include "Physics.h"
#include "Gfx.h"

void Physics::Resolve(GameObject* Object, std::vector<GameObject*> Objects)
{
	if (Object->ObjectPhysicsType == PhysicsType::Movable)
	{
		if (Object->Location.y < 0.f) Object->Location.y = 0.f;
		if (Object->Location.y > Gfx::CanvasSize.y - 1) Object->Location.y = Gfx::CanvasSize.y - 1;
		if (Object->Location.x < 1.f) Object->Location.x = 1.f;
		if (Object->Location.x > Gfx::CanvasSize.x - 1) Object->Location.x = Gfx::CanvasSize.x - 1;
	}
}
