#include "text.h"

void instructions()
{

	gotoxy(50, 17); cout << "      HUONG DAN CHOI ";
	gotoxy(50, 18); cout << "------------------------------ ";
	gotoxy(50, 20); cout << "Tranh chuong ngai vat bang cach di chuyen qua trai phai";
	gotoxy(50, 21); cout << " Bam phim 'a' de qua trai";
	gotoxy(50, 22); cout << " Bam phim 'd' de qua phai";
	gotoxy(50, 23); cout << " Bam Escape de thoat";
	gotoxy(50, 25); cout << "------------------------------";


	_getch();
}

void aboutus()
{

	gotoxy(50, 17); cout << "          NHOM 4 ";
	gotoxy(50, 18); cout << "     THONG TIN THANH VIEN ";
	gotoxy(50, 19); cout << "------------------------------";
	gotoxy(50, 20); cout << " 20127018 - PHUNG DUC HAI";
	gotoxy(50, 21); cout << " 20127250 - HO THI THANH NGAN";
	gotoxy(50, 22); cout << " 20127509 - LU PHI HUNG";
	gotoxy(50, 23); cout << " 20127668 - BUI HOANG VU";
	gotoxy(50, 24); cout << " 20127499 - PHAN LE MINH HIEU";
	gotoxy(50, 25); cout << "------------------------------";

	_getch();
}

void printduaxe()
{
	Textcolor(10);
		system("cls");
		gotoxy(2, 5);  cout << "  DDDDDDDDDDDDDD";
		gotoxy(2, 6);  cout << "  DDDDDDDDDDDDDDDD";
		gotoxy(2, 7);  cout << "  DDDD          DDDD";
		gotoxy(2, 8);  cout << "  DDDD          DDDD";
		gotoxy(2, 9);  cout << "DDDDDDDD        DDDD";
		gotoxy(2, 10); cout << "DDDDDDDD        DDDD";
		gotoxy(2, 11); cout << "  DDDD          DDDD";
		gotoxy(2, 12); cout << "  DDDD          DDDD";
		gotoxy(2, 13); cout << "  DDDDDDDDDDDDDDDD";
		gotoxy(2, 14); cout << "  DDDDDDDDDDDDDD";
	Textcolor(11);
		gotoxy(25, 5);   cout << "UUU             UUU";
		gotoxy(25, 6);  cout << "UUU             UUU";
		gotoxy(25, 7);  cout << "UUU             UUU";
		gotoxy(25, 8);  cout << "UUU             UUU";
		gotoxy(25, 9);  cout << "UUU             UUU";
		gotoxy(25, 10); cout << "UUU             UUU";
		gotoxy(25, 11); cout << "UUU             UUU";
		gotoxy(25, 12); cout << "UUU             UUU";
		gotoxy(25, 13); cout << "UUUUUUUUUUUUUUUUUUU";
		gotoxy(25, 14); cout << "  UUUUUUUUUUUUUUU";
	Textcolor(12);
		gotoxy(45, 5);  cout << "          A         ";
		gotoxy(45, 6);  cout << "         AAA        ";
		gotoxy(45, 7);  cout << "        AAAAA       ";
		gotoxy(45, 8);  cout << "       AAAAAAA      ";
		gotoxy(45, 9);  cout << "      AAAAAAAAA     ";
		gotoxy(45, 10); cout << "     AAAA   AAAA    ";
		gotoxy(45, 11); cout << "    AAAAAA AAAAAA   ";
		gotoxy(45, 12); cout << "   AAAAAAAAAAAAAAA  ";
		gotoxy(45, 13); cout << "  AAAA         AAAA ";
		gotoxy(45, 14); cout << " AAAA           AAAA";
	Textcolor(13);
		gotoxy(75, 5);  cout << " XXX           XXX";
		gotoxy(75, 6);  cout << "  XXX         XXX";
		gotoxy(75, 7);  cout << "   XXX       XXX";
		gotoxy(75, 8);  cout << "    XXX     XXX";
		gotoxy(75, 9);  cout << "       X XXX ";
		gotoxy(75, 10); cout << "       XXX X ";
		gotoxy(75, 11); cout << "    XXX     XXX";
		gotoxy(75, 12); cout << "   XXX       XXX";
		gotoxy(75, 13); cout << "  XXX         XXX";
		gotoxy(75, 14); cout << " XXX           XXX";
	Textcolor(14);
		gotoxy(98, 5);  cout << " EEEEEEEEEEEEEEE";
		gotoxy(98, 6);  cout << " EEEEEEEEEEEEEEE";
		gotoxy(98, 7);  cout << " EEEE";
		gotoxy(98, 8);  cout << " EEEE";
		gotoxy(98, 9);  cout << " EEEEEEEEEEEEEEE";
		gotoxy(98, 10); cout << " EEEEEEEEEEEEEEE";
		gotoxy(98, 11); cout << " EEEE";
		gotoxy(98, 12); cout << " EEEE";
		gotoxy(98, 13); cout << " EEEEEEEEEEEEEEE";
		gotoxy(98, 14); cout << " EEEEEEEEEEEEEEE";
		Textcolor(7);

}


