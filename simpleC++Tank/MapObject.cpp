#include "stdafx.h"
#include "MapObject.h"


CMapObject::CMapObject()
{
	
}


CMapObject::~CMapObject()
{
}

void CMapObject::initMap()
{	
		
}

bool CMapObject::setMapValue(int nPosX, int nPosY, int nValue)
{	if(nPosX>=50||nPosX<=0||nPosY<=0||nPosY>=70)
	return false;
m_nArrMap[nPosX][nPosY] = nValue;
	return true;
}

int CMapObject::getMapValue(int nPosX, int nPosY)
{
	return m_nArrMap[nPosY][nPosX];
}

bool CMapObject::DrawMap()
{
	for (int i = 0;i < 50;i++) {
		for (int j = 0;j < 70;j++) {
			DrawPatterning(j, i, m_nArrMap[i][j]);

		}
	}
	return true;
}
