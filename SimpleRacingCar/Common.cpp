#include "Common.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void AnTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void drawBorder()
{
	Textcolor(160);
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			gotoxy(0 + j, i);
			cout << " ";
			gotoxy(WIN_WIDTH - j, i);
			cout << " ";
		}

	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		gotoxy(SCREEN_WIDTH + 13, i);
		cout << "||";
	}
	Textcolor(7);
}

void drawLine1()
{
	for (int i = 0; i < SCREEN_HEIGHT; i = i + 2)
	{
		gotoxy(SCREEN_WIDTH / 2 - 10, i);
		cout << "|";
	}
}

void drawLine2()
{
	for (int i = 1; i < SCREEN_HEIGHT; i = i + 2)
	{
		gotoxy(SCREEN_WIDTH / 2 - 10, i);
		cout << "|";
	}
}

void eraseLine1()
{
	for (int i = 0; i < SCREEN_HEIGHT; i = i + 2)
	{
		gotoxy(SCREEN_WIDTH / 2 - 10, i);
		cout << " ";
	}
}

void eraseLine2()
{
	for (int i = 1; i < SCREEN_HEIGHT; i = i + 2)
	{
		gotoxy(SCREEN_WIDTH / 2 - 10, i);
		cout << " ";
	}
}

void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}


