#pragma once

class ConsolePlatformer
{
public:
	static int GetUniqueID()
	{
		IDcounter++;
		return IDcounter;
	}
private:
	static int IDcounter;
};

struct Vector2f
{
	float x;
	float y;
};

struct Vector2i
{
	int x;
	int y;
};

enum class PhysicsType
{
	Static,
	Kinetic,
	Movable
};
