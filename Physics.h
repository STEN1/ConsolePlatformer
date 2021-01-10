#pragma once
#include "GameObject.h"
#include <vector>

class Physics
{
public:
	static void RestrictMovableToCanvas(GameObject* Object, std::vector<GameObject*> Objects);
	static void ResolveStaticMovable(GameObject* Object, std::vector<GameObject*> Objects);
	static void GravityToMovable(GameObject* Object, float DeltaTime);
	
	static float GravityConstant;
private:

};

