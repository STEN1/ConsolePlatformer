#pragma once

#include <Windows.h>


class Input
{
public:
	static bool Space;
	static bool W;
	static bool A;
	static bool S;
	static bool D;

	static void GetInput()
	{
		// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

		(GetAsyncKeyState(0x20)) ? Space = true : Space = false;
		(GetAsyncKeyState(0x57)) ? W = true : W = false;
		(GetAsyncKeyState(0x53)) ? S = true : S = false;
		(GetAsyncKeyState(0x41)) ? A = true : A = false;
		(GetAsyncKeyState(0x44)) ? D = true : D = false;
	}
};


