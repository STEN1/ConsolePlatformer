#include "Gfx.h"
#include "ConsoleHelp.h"
#include <string>

Gfx::Gfx()
{
}

void Gfx::DrawObject(GameObject* Object)
{
	Vector2i IntLocation;

	IntLocation.x = (int)Object->GetLocation()->x;
	IntLocation.y = (int)Object->GetLocation()->y;

	std::string S{ " " };
	S[0] = Object->GetGfx();
	ch::PutText(S, { IntLocation.x, ch::YToRow(IntLocation.y, CanvasSize.y) });
}

Vector2i Gfx::CanvasSize{ 56, 28 };

