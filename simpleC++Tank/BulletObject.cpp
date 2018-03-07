#include "stdafx.h"
#include "BulletObject.h"


CBulletObject::CBulletObject()
{
}


CBulletObject::~CBulletObject()
{
}

CBulletObject CBulletObject::CreateBullet(CTankObject TankObjec, vector<CTankObject>& vecTankObject)
{
	return CBulletObject();
}

bool CBulletObject::operator=(CTankObject TankObject)
{
	m_Alignement = TankObject.getAlignment();
	m_nPosX = TankObject.getTankPosX();
	m_nPosY = TankObject.getTankPosY();
	m_nDir = TankObject.getTankDir();
	m_nType = TankObject.getTankType();
	m_pMapObject = TankObject.getMapObj();
	switch (m_nType) {
	case 4:case 5:
	m_nATK = 2;
	break;
	case 6:case 7:case 8:
		m_nATK = 1;
		break;
	default:
		break;
	}
	switch(TankObject.getTankDir()){
	case UP:
		m_nPosY -= 2;
	case DOWN:
		m_nPosY += 2;
	case LEFT:
		m_nPosX -= 2;
	case RIGHT:
		m_nPosX += 2;
	}
	return true;
}

bool CBulletObject::operator==(CTankObject TankObject)
{
	int nTankPosX = TankObject.getTankPosX();
	int nTankPosY = TankObject.getTankPosY();
	if(!TankObject.getTankIsDie())
	{
		for (int i = 0;i < 6;i++) {
			if (TankObject.getbody(i).X == m_nPosX) && (TankObject.getbody(i).Y == m_nPosY)
				return true;
		}
	}
	return false;
}
