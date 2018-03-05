#pragma once
class CDrawObject
{
public:
	CDrawObject();
	~CDrawObject();
public:
	//在指定位置打印对应的图案
	bool DrawPatterning(int nPosX, int nPosY, int nType);
private:
	void WriteChar(int Wide, int High, Char* pszChar,WORD wArr);
};

