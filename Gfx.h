#pragma once
#include "GameObject.h"
#include "ConsolePlatformer.h"

class Gfx
{
public:
	Gfx();
	static void DrawObject(GameObject* Object);
	static Vector2i CanvasSize;
};



