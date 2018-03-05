#pragma once
#include "DrawObject.h"
class CMapObject:public CDrawObject
{
public:
	CMapObject();
	~CMapObject();
public:
	//设置地图中指定位置的数据
	void initMap();
	bool setMapValue(int nPosX, int nPosY, int nValue);
	int getMapValue(int nPosX, int nPosY);
	bool DrawMap();
private:
	int m_nArrMap[50][70] = {};

};

