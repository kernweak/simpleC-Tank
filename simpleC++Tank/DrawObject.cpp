#include "stdafx.h"
#include "DrawObject.h"
#include<Windows.h>

CDrawObject::CDrawObject()
{
}


CDrawObject::~CDrawObject()
{
}

bool CDrawObject::DrawPatterning(int nPosX, int nPosY, int nType)
{
	if(nType == 1)
		WriteChar(nPosX, nPosY, "█", 7);
	if(nType == 2)
		WriteChar(nPosX, nPosY, "▓", 4);
	if (nType == 3)
		WriteChar(nPosX, nPosY, "★", 9);
	return true;
}

bool CDrawObject::DrawWelcome()
{
	char f1[42] = "           ▄■▄                       ";
	char f2[42] = "	    ■■■■■         ▲▲▲          ";
	char f3[42] = " ■■■■■■■■■■■■■■■■■■■ ";
	char f4[42] = " ■■■■■■■■■■■■■             ";
	char f5[42] = "■■■■■■■■■■■■■■            ";
	char f6[42] = " ■■■■■■■■■■■■■             ";
	char f7[42] = "   ●●●          ●●●               ";
	char f8[42] = "    ●●            ●●                ";
	for (int i = 0;i < 30;i++) {
		WriteChar(i+1, 10, f1, 4);
		WriteChar(i, 11, f2, 4);
		WriteChar(i, 12, f3, 4);
		WriteChar(i, 13, f4, 4);
		WriteChar(i, 14, f5, 4);
		WriteChar(i, 15, f6, 4);
		WriteChar(i, 16, f7, 4);
		WriteChar(i, 17, f8, 4);
		Sleep(1);
		if (i == 29)break;
		eraseChar(i, 10, f1, 0);
		eraseChar(i, 11, f2, 0);
		eraseChar(i, 12, f3, 0);
		eraseChar(i, 13, f4, 0);
		eraseChar(i, 14, f5, 0);
		eraseChar(i, 15, f6, 0);
		eraseChar(i, 16, f7, 0);
		eraseChar(i, 17, f8, 0);
	}
	WriteChar(30, 40, "欢迎来到坦克大战，按任意键开始游戏", 5);
//	cout << "欢迎来到坦克大战，按任意键开始游戏" << endl;
	char i=getchar();
	system("cls");
	return true;
}

void CDrawObject::WriteChar(int Wide, int High, char * pszChar, WORD wArr)
{
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleCursorPosition(hOutStd, loc);
	SetConsoleTextAttribute(hOutStd, wArr);
	cout << pszChar;
}

void CDrawObject::eraseChar(int Wide, int High, char * pszChar, WORD wArr)
{
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleCursorPosition(hOutStd, loc);
	SetConsoleTextAttribute(hOutStd, wArr);
	printf("  ");
}

bool CDrawObject::DrawGame()
{
	return false;
}


