#pragma once
class CMapObject
{
public:
	CMapObject();
	~CMapObject();
public:
	//���õ�ͼ��ָ��λ�õ�����
	bool setMapValue(int nPosX, int nPosY, int nValue);
	int getMapValue(int nPosX, int nPosY);
	bool DrawMap();
private:
	int m_nArrMap[40][40] = {};
};

