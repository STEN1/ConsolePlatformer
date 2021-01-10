#include "Gfx.h"
#include "ConsoleHelp.h"
#include <string>

Gfx::Gfx()
{
}

void Gfx::DrawObject(GameObject* Object)
{
	if (!Object->DrawObject) return;
	Vector2i NewCanvasLocation;
	
	float xDecimal = Object->Location.x - (int)Object->Location.x;
	float yDecimal = Object->Location.y - (int)Object->Location.y;

	NewCanvasLocation.x = (int)Object->Location.x;
	NewCanvasLocation.y = (int)Object->Location.y;

	if (xDecimal > 0.5f) NewCanvasLocation.x += 1.f;
	if (yDecimal > 0.5f) NewCanvasLocation.y += 1.f;

	std::string S{ " " };
	S[0] = Object->GfxChar;
	ch::PutText(" ", { Object->CanvasLocation.x, ch::YToRow(Object->CanvasLocation.y, CanvasSize.y) });
	ch::PutText(S, { NewCanvasLocation.x, ch::YToRow(NewCanvasLocation.y, CanvasSize.y) });

	Object->CanvasLocation = NewCanvasLocation;
}

void Gfx::DrawBoarder()
{
	ch::SetCursorPosition({ 0,ch::YToRow(-1, CanvasSize.y) });
	for (int i = 0; i < CanvasSize.x+1; i++)
	{
		std::cout << "-";
	}
	ch::SetCursorPosition({ 0,ch::YToRow(CanvasSize.y, CanvasSize.y) });
	for (int i = 0; i < CanvasSize.x + 1; i++)
	{
		std::cout << "-";
	}
	for (int i = 1; i < CanvasSize.y + 1; i++)
	{
		ch::SetCursorPosition({ 0, i });
		std::cout << "|";
	}
	for (int i = 1; i < CanvasSize.y + 1; i++)
	{
		ch::SetCursorPosition({ CanvasSize.x, i });
		std::cout << "|";
	}
}

Vector2i Gfx::CanvasSize{ 118, 28 };

