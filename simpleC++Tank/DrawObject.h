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
	//��ָ��λ�ô�ӡ��Ӧ��ͼ��
	bool DrawPatterning(int nPosX, int nPosY, int nType);
private:
	void WriteChar(int Wide, int High, char* pszChar,WORD wArr);
	void eraseChar(int Wide, int High, char* pszChar, WORD wArr);
	
};

