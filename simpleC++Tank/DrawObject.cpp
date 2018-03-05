#include "stdafx.h"
#include "DrawObject.h"


CDrawObject::CDrawObject()
{
}


CDrawObject::~CDrawObject()
{
}

bool CDrawObject::DrawPatterning(int nPosX, int nPosY, int nType)
{
	if(nType == 1)
		WriteChar(nPosX, nPosY, "¨€", 7);
	if(nType == 2)
		WriteChar(nPosX, nPosY, "¨ˆ", 4);
	if (nType == 2)
		WriteChar(nPosX, nPosY, "¡ï", 9);
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


