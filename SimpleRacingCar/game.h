//Game.h xu li cac van de ve game

#pragma once
#pragma comment (lib, "winmm.lib")

#include "Common.h"
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;


void genEnemy(int ind);		//Tao ra chuong ngai vat

void drawEnemy(int ind);	//Ve chuong ngai vat

void eraseEnemy(int ind);	//Xoa chuong ngai vat ( khi di het map )

void resetEnemy(int ind);	//Reset chuong ngai vat

void drawCar1();			//Ve hinh xe 1	

void drawCar2();			//Ve hinh xe 2

void drawCar3();			//Ve hinh xe 3

void drawCar4();			//Ve hinh xe 4

void chooseCar();			// chon. xe

void eraseCar();			//Xoa xe cua player

int collision();			//Ham xu li va cham

void updateScore();			//Ham tu dong cap nhat diem

void gameover();			// Ham in ra màn hình Game Over

void chooseLevel();			// Ham chon Level

void play();				//Ham xu li game

void batdau(int n);			//Ham Menu

void gethighscore();		// Ham lay diem cao nhat