#include "stdafx.h"
#include "TankObject.h"


CTankObject::CTankObject()
{
}


CTankObject::~CTankObject()
{
}

bool CTankObject::DrawObject()
{
	return false;
}

bool CTankObject::ClsObject()
{
	return false;
}

CTankObject CTankObject::getTankBirthPlace(int nType)//0为自己，1为友军
{
	CTankObject temp;
	temp.m_IsDie = false;
	if (0 == nType) {
		temp.m_Alignment = 1;
		temp.m_nPosX = 47;
		temp.m_nPosY = 24;
		temp.m_nDir = UP;
		temp.m_nType = 1;
		temp.m_nBlood = 3;
		temp.m_nScore = 0;
	}
	if (1 == nType) {
		temp.m_Alignment = 1;
		temp.m_nPosX = 47;
		temp.m_nPosY = 34;
		temp.m_nDir = UP;
		temp.m_nType = 1;
		temp.m_nBlood = 3;
		temp.m_nScore = 0;
	}
	return temp;
}

void CTankObject::setMapObj(CMapObject * pMapObject)
{
}
