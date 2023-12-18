#include <Windows.h>

void noCursor()
{
	CONSOLE_CURSOR_INFO info;
	HANDLE  out;

	info.bVisible = 0;
	info.dwSize = 1;

	out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(out, &info);
}