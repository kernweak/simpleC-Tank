#pragma once
class CDrawObject
{
public:
	CDrawObject();
	~CDrawObject();
public:
	//��ָ��λ�ô�ӡ��Ӧ��ͼ��
	bool DrawPatterning(int nPosX, int nPosY, int nType);
private:
	void WriteChar(int Wide, int High, Char* pszChar,WORD wArr);
};

