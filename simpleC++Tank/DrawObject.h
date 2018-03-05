#pragma once
#include <windows.h>
#include<iostream>
using namespace std;
class CDrawObject
{
public:
	CDrawObject();
	~CDrawObject();
public:
	//在指定位置打印对应的图案
	bool DrawPatterning(int nPosX, int nPosY, int nType);
private:
	void WriteChar(int Wide, int High, char* pszChar,WORD wArr);
	void eraseChar(int Wide, int High, char* pszChar, WORD wArr);
	
};

