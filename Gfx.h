#pragma once
#include "GameObject.h"
#include "ConsolePlatformer.h"

class Gfx
{
public:
	Gfx();
	static void DrawObject(GameObject* Object);
	static void DrawBoarder();
	static Vector2i CanvasSize;
};



