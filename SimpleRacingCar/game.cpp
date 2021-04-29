#include "game.h"
#include "text.h"
#include <conio.h>
#include <fstream>

int enemyY[3];
int enemyX[3];
int enemyFlag[3];

int xe = 1;
int level = 1;
int score = 0;
int highscore = 0;
int carPos = WIN_WIDTH / 2;

void genEnemy(int ind)
{
	enemyX[ind] = 17 + rand() % (33);
}

void drawEnemy(int ind)
{
	if (enemyFlag[ind] == true)
	{
		Textcolor(11);
		gotoxy(enemyX[ind], enemyY[ind]);
		cout << "XXXX";
		gotoxy(enemyX[ind], enemyY[ind] + 1);
		cout << " XX";
		gotoxy(enemyX[ind], enemyY[ind] + 2);
		cout << "XXXX";
		gotoxy(enemyX[ind], enemyY[ind] + 3);
		cout << " XX";
		Textcolor(7);
	}
}

void eraseEnemy(int ind)
{
	if (enemyFlag[ind] == true)
	{
		gotoxy(enemyX[ind], enemyY[ind]);
		cout << "    ";
		gotoxy(enemyX[ind], enemyY[ind] + 1);
		cout << "    ";
		gotoxy(enemyX[ind], enemyY[ind] + 2);
		cout << "    ";
		gotoxy(enemyX[ind], enemyY[ind] + 3);
		cout << "    ";
	}
}

void resetEnemy(int ind)
{
	eraseEnemy(ind);
	enemyY[ind] = 1;
	genEnemy(ind);
}

int collision()
{
	if (enemyY[1] + 4 >= 23)
	{
		if (enemyX[1] + 4 - carPos >= 0 && enemyX[1] + 4 - carPos < 9)
			return 1;
	}

	if (enemyY[0] + 4 >= 23)
	{
		if (enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9)
		{
			return 1;
		}
	}

	return 0;
}

void drawCar1()
{
	char car[4][4] = { ' ','^','^',' '
					,'@','X', 'X','@',' ',
							'X','X',' '
				   ,'@' ,'X' ,'X' ,'@' };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(j + carPos, i + 22);
			Textcolor(12);
			cout << car[i][j];
			Textcolor(7);
		}
	}
}

void drawCar2()
{
	char car[4][4] = { ' ','M','M',' '
					,'@','H', 'H','@',' ',
							'H','H',' '
				   ,'@' ,'H' ,'H' ,'@' };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(j + carPos, i + 22);
			Textcolor(13);
			cout << car[i][j];
			Textcolor(7);
		}
	}
}

void drawCar3()
{
	char car[4][4] = { ' ','A','A',' '
				,'@','X', 'X','@',' ',
						'H','H',' '
			   ,'@' ,'X' ,'X' ,'@' };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(j + carPos, i + 22);
			Textcolor(14);
			cout << car[i][j];
			Textcolor(7);
		}
	}
}

void drawCar4()
{
	char car[4][4] = { ' ','$','$',' '
				,'@','|', '|','@',' ',
						'|','|',' '
			   ,'@' ,'|' ,'|' ,'@' };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(j + carPos, i + 22);
			Textcolor(10);
			cout << car[i][j];
			Textcolor(7);
		}
	}
}

void eraseCar()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(j + carPos, i + 22);
			cout << " ";
		}
	}
}

void updateScore()
{
	gotoxy(WIN_WIDTH + 7, 5);
	Textcolor(12);
	cout << "Diem     = " << score << endl;
	Textcolor(7);
}

void chooseCar()
{
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int n = 1;
	int check = 1;
	
	
	printduaxe();
	carPos = WIN_WIDTH / 2;
	drawCar1();
	gotoxy(50, 18); cout << "-------------------";
	Textcolor(9);
	gotoxy(50, 20); cout << "XE 1";
	Textcolor(7);
	gotoxy(50, 21); cout << "XE 2";
	gotoxy(50, 22); cout << "XE 3";
	gotoxy(50, 23); cout << "XE 4";
	gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y > 20)
				{
					y--;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					drawCar1();
					gotoxy(50, 18); cout << "-------------------";
					Textcolor(9);
					gotoxy(50, 20); cout << "XE 1";
					Textcolor(7);
					gotoxy(50, 21); cout << "XE 2";
					gotoxy(50, 22); cout << "XE 3";
					gotoxy(50, 23); cout << "XE 4";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 21)
				{
					drawCar2();
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "XE 1";
					Textcolor(9);
					gotoxy(50, 21); cout << "XE 2";
					Textcolor(7);
					gotoxy(50, 22); cout << "XE 3";
					gotoxy(50, 23); cout << "XE 4";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 22)
				{
					drawCar3();
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "XE 1";
					gotoxy(50, 21); cout << "XE 2";
					Textcolor(9);
					gotoxy(50, 22); cout << "XE 3";
					Textcolor(7);
					gotoxy(50, 23); cout << "XE 4";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 23)
				{
					drawCar4();
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "XE 1";
					gotoxy(50, 21); cout << "XE 2";
					gotoxy(50, 22); cout << "XE 3";
					Textcolor(9);
					gotoxy(50, 23); cout << "XE 4";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}

				break;
			case 's':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y < 23)
				{
					y++;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					drawCar1();
					gotoxy(50, 18); cout << "-------------------";
					Textcolor(9);
					gotoxy(50, 20); cout << "XE 1";
					Textcolor(7);
					gotoxy(50, 21); cout << "XE 2";
					gotoxy(50, 22); cout << "XE 3";
					gotoxy(50, 23); cout << "XE 4";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 21)
				{
					drawCar2();
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "XE 1";
					Textcolor(9);
					gotoxy(50, 21); cout << "XE 2";
					Textcolor(7);
					gotoxy(50, 22); cout << "XE 3";
					gotoxy(50, 23); cout << "XE 4";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 22)
				{
					drawCar3();
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "XE 1";
					gotoxy(50, 21); cout << "XE 2";
					Textcolor(9);
					gotoxy(50, 22); cout << "XE 3";
					Textcolor(7);
					gotoxy(50, 23); cout << "XE 4";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 23)
				{
					drawCar4();
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "XE 1";
					gotoxy(50, 21); cout << "XE 2";
					gotoxy(50, 22); cout << "XE 3";
					Textcolor(9);
					gotoxy(50, 23); cout << "XE 4";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y == 20)
				{
					xe = 1;
					batdau(99);
				}
				if (y == 21)
				{
					xe = 2;
					batdau(99);
				}
				if (y == 22)
				{
					xe = 3;
					batdau(99);
				}
				if (y == 23)
				{
					xe = 4;
					batdau(99);
				}
				break;
			}
		}
	}
}

void chooseLevel()
{
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int n = 1;
	int check = 1;


	printduaxe();
	carPos = WIN_WIDTH / 2;
	gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
	Textcolor(9);
	gotoxy(50, 20); cout << "EASY";
	Textcolor(7);
	gotoxy(50, 21); cout << "MEDIUM";
	gotoxy(50, 22); cout << "HARD";
	gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y > 20)
				{
					y--;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					Textcolor(9);
					gotoxy(50, 20); cout << "EASY";
					Textcolor(7);
					gotoxy(50, 21); cout << "MEDIUM";
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					Textcolor(9);
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(7);
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(9);
					gotoxy(50, 22); cout << "HARD";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}

				break;
			case 's':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y < 22)
				{
					y++;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					Textcolor(9);
					gotoxy(50, 20); cout << "EASY";
					Textcolor(7);
					gotoxy(50, 21); cout << "MEDIUM";
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					Textcolor(9);
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(7);
					gotoxy(50, 22); cout << "HARD";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "----CHOOSE LEVEL-----";
					gotoxy(50, 20); cout << "EASY";
					gotoxy(50, 21); cout << "MEDIUM";
					Textcolor(9);
					gotoxy(50, 22); cout << "HARD";
					Textcolor(7);
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}

				break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y == 20)
				{
					level = 1;
					play();
				}
				if (y == 21)
				{
					level = 2;
					play();
				}
				if (y == 22)
				{
					level = 3;
					play();
				}

				break;
			}
		}
	}
}

void gethighscore()
{
	/*ifstream fileInput("C:\\Users\\Lenovo\\Desktop\\Assignment\\New folder\\Dua xe Final\\HighScore.txt");
	if (fileInput.fail())
		cout << "fail";

	fileInput >> highscore;

	ofstream fileOutput("C:\\Users\\Lenovo\\Desktop\\Assignment\\New folder\\Dua xe Final\\HighScore.txt");
	if (fileOutput.fail())
		cout << "fail";*/

	if (highscore <= score)
		highscore = score;

	gotoxy(WIN_WIDTH + 7, 6);
	Textcolor(12);
	cout << "Diem cao = " << highscore << endl;
	Textcolor(7);
}

void gameover()
{
	system("cls");
	
	Textcolor(10);
	gotoxy(90, 8); cout << "DIEM CUA BAN LA " << score;

	Textcolor(9);
	gotoxy(1, 1);   cout << "  GGGGGGGGGGG";
	gotoxy(1, 2);   cout << " GGGGGGGGGGGG";
	gotoxy(1, 3);   cout << "GG         GG";
	gotoxy(1, 4);   cout << "GG         GG";
	gotoxy(1, 5);   cout << "GG";
	gotoxy(1, 6);   cout << "GG";
	gotoxy(1, 7);   cout << "GG       GGGG";
	gotoxy(1, 8);  cout << "GG         GG";
	gotoxy(1, 9);  cout << " GGGGGGGGGGGG";
	gotoxy(1, 10);  cout << "  GGGGGGGGGGG";

	Textcolor(10);
	gotoxy(15, 3);  cout << "         A       ";
	gotoxy(15, 4);  cout << "        AAA      ";
	gotoxy(15, 5);  cout << "       AAAAA     ";
	gotoxy(15, 6);  cout << "      AA   AA    ";
	gotoxy(15, 7);  cout << "     AAA   AAA   ";
	gotoxy(15, 8); cout << "    AAAAA AAAAA  ";
	gotoxy(15, 9); cout << "   AAA   A   AAA ";
	gotoxy(15, 10); cout << "  AAA         AAA";
	gotoxy(15, 11); cout << " AAA           AAA";
	gotoxy(15, 12); cout << "AAA             AAA";

	Textcolor(11);
	gotoxy(35, 1);  cout << "MMMMMMMMMMMMMMMMM";
	gotoxy(35, 2);  cout << "MM    MMMMM    MM";
	gotoxy(35, 3);  cout << "MM    MMMMM    MM";
	gotoxy(35, 4);  cout << "MM    MMMMM    MM";
	gotoxy(35, 5);  cout << "MM    MM MM    MM";
	gotoxy(35, 6);   cout << "MM    M   M    MM";
	gotoxy(35, 7);  cout << "MM             MM";
	gotoxy(35, 8), cout << "MM      M      MM";
	gotoxy(35, 9), cout << "MM     MMM     MM";
	gotoxy(35, 10), cout << "MM    MMMMM    MM";

	Textcolor(12);
	gotoxy(52, 3);  cout << "  EEEEEEEEEEEEE";
	gotoxy(52, 4);  cout << "  EEEEEEEEEEEEE";
	gotoxy(52, 5);  cout << "  EE";
	gotoxy(52, 6); cout << "  EE";
	gotoxy(52, 7); cout << "  EEEEEEEEEEEEE";
	gotoxy(52, 8); cout << "  EEEEEEEEEEEEE";
	gotoxy(52, 9); cout << "  EE";
	gotoxy(52, 10); cout << "  EE";
	gotoxy(52, 11); cout << "  EEEEEEEEEEEEE";
	gotoxy(52, 12); cout << "  EEEEEEEEEEEEE";


	Textcolor(13);
	gotoxy(36, 15); cout << " OOOOOOOOOOO0 ";
	gotoxy(36, 16); cout << "O0          OO";
	gotoxy(36, 17); cout << "OO          0O";
	gotoxy(36, 18); cout << "00          OO";
	gotoxy(36, 19); cout << "00          00";
	gotoxy(36, 20); cout << "OO          00";
	gotoxy(36, 21); cout << "00          OO";
	gotoxy(36, 22); cout << "OO          00";
	gotoxy(36, 23); cout << "00          00";
	gotoxy(36, 24); cout << " OOOOOOOOOOOO";

	Textcolor(14);
	gotoxy(52, 17); cout << "   VVV          VVV";
	gotoxy(52, 18); cout << " VVV  VVV    VVV VVV";
	gotoxy(52, 19); cout << "VVV     VV  VV    VVV";
	gotoxy(52, 20); cout << " VVV      V.     VVV";
	gotoxy(52, 21); cout << "  VVV           VVV";
	gotoxy(53, 22); cout << "   VVV       VVV";
	gotoxy(54, 23); cout << "    VVV   VVV";
	gotoxy(54, 24); cout << "     VVV VVV";
	gotoxy(54, 25); cout << "       VVV";
	gotoxy(54, 26), cout << "        V";

	Textcolor(15);
	gotoxy(75, 15);  cout << "  EEEEEEEEEEEEE";
	gotoxy(75, 16);  cout << "  EEEEEEEEEEEEE";
	gotoxy(75, 17);  cout << "             EE";
	gotoxy(75, 18);  cout << "             EE";
	gotoxy(75, 19);  cout << "  EEEEEEEEEEEEE";
	gotoxy(75, 20);  cout << "  EEEEEEEEEEEEE";
	gotoxy(75, 21);  cout << "             EE";
	gotoxy(75, 22); cout << "             EE";
	gotoxy(75, 23); cout << "  EEEEEEEEEEEEE";
	gotoxy(75, 24); cout << "  EEEEEEEEEEEEE";

	Textcolor(10);
	gotoxy(95, 17); cout << "RRRRRRRRRRRRRR";
	gotoxy(95, 18); cout << "RRR  R  R  RRR";
	gotoxy(95, 19); cout << "RRR   |   RRR";
	gotoxy(95, 20); cout << "RRR   |   RRR";
	gotoxy(95, 21); cout << "RRR  RRR RRR";
	gotoxy(95, 22); cout << "RRR     RRR";
	gotoxy(95, 23); cout << "RRRRRRRRRR";
	gotoxy(95, 24); cout << "RRR      RRR";
	gotoxy(95, 25); cout << "RRR       RRR";
	gotoxy(95, 26), cout << "RRR        RRR";
	Textcolor(7);

	Sleep(1500);

	_getch();
}

void play()
{
	int flag = 1;
	carPos = -1 + WIN_WIDTH / 2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;

	system("cls");

	drawBorder();
	gethighscore();
	updateScore();
	genEnemy(0);
	genEnemy(1);

	Textcolor(12);
	gotoxy(WIN_WIDTH + 7, 2);
	cout << "DUA XE NE CHUONG NGAI VAT";
	gotoxy(WIN_WIDTH + 6, 4);
	cout << "--------------------------";
	gotoxy(WIN_WIDTH + 6, 7);
	cout << "--------------------------";
	gotoxy(WIN_WIDTH + 7, 12);
	cout << "  DIEU KHIEN";
	gotoxy(WIN_WIDTH + 7, 13);
	cout << "--------------------------";
	gotoxy(WIN_WIDTH + 2, 14);
	cout << "     A - Sang trai";
	gotoxy(WIN_WIDTH + 2, 15);
	cout << "     D - Sang phai";
	Textcolor(7);


	gotoxy(18, 5);
	cout << "  ---Bam phim bat ky de bat dau---";
	_getch();
	gotoxy(18, 5);
	cout << "                                  ";

	while (1)
	{
		flag ^= 1;
		if (flag == 1)
		{
			drawLine1();
			eraseLine2();
		}
		else
		{
			drawLine2();
			eraseLine1();
		}
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'a' || ch == 'A')
			{
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (carPos > 18)
					carPos -= 4;
			}
			if (ch == 'd' || ch == 'D')
			{
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (carPos < 50)
					carPos += 4;
			}
			if (ch == 27)
			{
				break;
			}
		}
		if (xe == 1)
			drawCar1();
		if (xe == 2)
			drawCar2();
		if (xe == 3)
			drawCar3();
		if (xe == 4)
			drawCar4();

		drawEnemy(0);
		drawEnemy(1);	

		if (collision() == 1)
		{
			cout << "\a";
			gameover();
			system("cls");
			batdau(100);
			return;
		}

		if (level == 1)
			Sleep(60);
		if (level == 2)
			Sleep(40);
		if (level == 3)
			Sleep(20);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);
		


		if (enemyY[0] == 10)
			if (enemyFlag[1] == 0)
				enemyFlag[1] = 1;
		if (enemyFlag[0] == 1)
			enemyY[0] += 1;

		if (enemyFlag[1] == 1)
			enemyY[1] += 1;

		if (enemyY[0] > SCREEN_HEIGHT - 4)
		{
			resetEnemy(0);
			score++;
			updateScore();
			gethighscore();
		}

		if (enemyY[1] > SCREEN_HEIGHT - 4)
		{
			resetEnemy(1);
			score++;
			updateScore();
			gethighscore();

		}
	}
}

void batdau(int n)
{

	
	int x = 50, y = 20;
	int i;
	char s[30] = " ";
	int check = 1;

	AnTroChuot();
	printduaxe();
	gotoxy(50, 18); cout << "-------------------";
	Textcolor(9);
	gotoxy(50, 20); cout << "1. Bat Dau";
	Textcolor(7);
	gotoxy(50, 21); cout << "2. Huong dan";
	gotoxy(50, 22); cout << "3. About us";
	gotoxy(50, 23); cout << "4. Chon xe";
	gotoxy(50, 24); cout << "5. Thoat game";
	gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

	if (n == 100)
		PlaySound(TEXT("nhacnen.wav"), NULL, SND_FILENAME | SND_ASYNC);

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y > 20)
				{
					y--;
					gotoxy(x, y);
				}
				if (y == 20)
				{
					gotoxy(50, 18); cout << "-------------------";
					Textcolor(9);
					gotoxy(50, 20); cout << "1. Bat Dau";
					Textcolor(7);
					gotoxy(50, 21); cout << "2. Huong dan";
					gotoxy(50, 22); cout << "3. About us";
					gotoxy(50, 23); cout << "4. Chon xe";
					gotoxy(50, 24); cout << "5. Thoat game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 21)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "1. Bat Dau";
					Textcolor(9);
					gotoxy(50, 21); cout << "2. Huong dan";
					Textcolor(7);
					gotoxy(50, 22); cout << "3. About us";
					gotoxy(50, 23); cout << "4. Chon xe";
					gotoxy(50, 24); cout << "5. Thoat game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 22)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "1. Bat Dau";
					gotoxy(50, 21); cout << "2. Huong dan";
					Textcolor(9);
					gotoxy(50, 22); cout << "3. About us";
					Textcolor(7);
					gotoxy(50, 23); cout << "4. Chon xe";
					gotoxy(50, 24); cout << "5. Thoat game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}
				if (y == 23)
				{
					Textcolor(7);
					gotoxy(50, 18); cout << "-------------------";
					gotoxy(50, 20); cout << "1. Bat Dau";
					gotoxy(50, 21); cout << "2. Huong dan";
					gotoxy(50, 22); cout << "3. About us";
					Textcolor(9);
					gotoxy(50, 23); cout << "4. Chon xe";
					Textcolor(7);
					gotoxy(50, 24); cout << "5. Thoat game";
					gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

				}    
				if ( y == 24)
				{ 
					Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Bat Dau";
				gotoxy(50, 21); cout << "2. Huong dan";
				gotoxy(50, 22); cout << "3. About us";
				gotoxy(50, 23); cout << "4. Chon xe";
				Textcolor(9);
				gotoxy(50, 24); cout << "5. Thoat game";
				Textcolor(7);
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
				}

				break;
			case 's':
			PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (y < 24)
			{
				y++;
				gotoxy(x, y);
			}
			if (y == 20)
			{
				gotoxy(50, 18); cout << "-------------------";
				Textcolor(9);
				gotoxy(50, 20); cout << "1. Bat Dau";
				Textcolor(7);
				gotoxy(50, 21); cout << "2. Huong dan";
				gotoxy(50, 22); cout << "3. About us";
				gotoxy(50, 23); cout << "4. Chon xe";
				gotoxy(50, 24); cout << "5. Thoat game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}
			if (y == 21)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Bat Dau";
				Textcolor(9);
				gotoxy(50, 21); cout << "2. Huong dan";
				Textcolor(7);
				gotoxy(50, 22); cout << "3. About us";
				gotoxy(50, 23); cout << "4. Chon xe";
				gotoxy(50, 24); cout << "5. Thoat game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}
			if (y == 22)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Bat Dau";
				gotoxy(50, 21); cout << "2. Huong dan";
				Textcolor(9);
				gotoxy(50, 22); cout << "3. About us";
				Textcolor(7);
				gotoxy(50, 23); cout << "4. Chon xe";
				gotoxy(50, 24); cout << "5. Thoat game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";

			}
			if (y == 23)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Bat Dau";
				gotoxy(50, 21); cout << "2. Huong dan";
				gotoxy(50, 22); cout << "3. About us";
				Textcolor(9);
				gotoxy(50, 23); cout << "4. Chon xe";
				Textcolor(7);
				gotoxy(50, 24); cout << "5. Thoat game";
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}
			if (y == 24)
			{
				Textcolor(7);
				gotoxy(50, 18); cout << "-------------------";
				gotoxy(50, 20); cout << "1. Bat Dau";
				gotoxy(50, 21); cout << "2. Huong dan";
				gotoxy(50, 22); cout << "3. About us";
				gotoxy(50, 23); cout << "4. Chon xe";
				Textcolor(9);
				gotoxy(50, 24); cout << "5. Thoat game";
				Textcolor(7);
				gotoxy(50, 26); cout << "W-S de di chuyen, Enter de chon";
			}

			break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (y == 20)
				{
					chooseLevel();
				}
				if (y == 21)
				{
					printduaxe();
					instructions();
					system("cls");
					batdau(99);
				}
				if (y == 22)
				{
					printduaxe();
					aboutus();
					system("cls");
					batdau(99);
				}
				if (y == 23)
				{
					chooseCar();
					system("cls");
				}
				if (y == 24)
				{
					exit(0);
				}
				break;
			}
		}
	}

}

