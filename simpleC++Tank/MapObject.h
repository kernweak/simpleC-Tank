#pragma once
class CMapObject
{
public:
	CMapObject();
	~CMapObject();
public:
	//设置地图中指定位置的数据
	bool setMapValue(int nPosX, int nPosY, int nValue);
	int getMapValue(int nPosX, int nPosY);
	bool DrawMap();
private:
	int m_nArrMap[40][40] = {};
};

