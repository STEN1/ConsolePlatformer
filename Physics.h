#pragma once
#include "GameObject.h"
#include <vector>

class Physics
{
public:
	static void Resolve(GameObject* Object, std::vector<GameObject*> Objects);


};

