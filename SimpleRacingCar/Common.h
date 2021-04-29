//Common.h xu li cac ham co ban

#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;


//Chinh size man hinh choi game
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

//Di chuyen den toa do (x,y) trong man hinh console
void gotoxy(int x, int y);

//Hien con tro chuot
void setcursor(bool visible, DWORD size);

//Ve map, man choi
void drawBorder();

void drawLine1();			// Ve lan duong o giua 1

void drawLine2();			// Ve lan duong o giua 2

void eraseLine1();			// Xoa lan duong o giua 1

void eraseLine2();			// Xoa lan duong o giua 2

void Textcolor(int color);	// Lay bang mau

void AnTroChuot();			// An cho chuot




