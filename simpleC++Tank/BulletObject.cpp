#include "stdafx.h"
#include "BulletObject.h"


CBulletObject::CBulletObject()
{
}


CBulletObject::~CBulletObject()
{
}

bool CBulletObject::DrawObject()
{
	return false;
}

bool CBulletObject::DrawObject(int nPosX, int nPosY, int nType)
{
	CDrawObject a;
	a.WriteChar(nPosX, nPosY,"●", nType);
	return true;
}

bool CBulletObject::ClsObject()
{
	CDrawObject a;
	a.WriteChar(this->m_nPosX, this->m_nPosY, "  ", 0);
	return true;
}

CBulletObject CBulletObject::CreateBullet(CTankObject TankObject, vector<CTankObject>& vecTankObject)
{
	*this = TankObject;
	//判断碰撞
	if (BulletCollision(*this, vecTankObject)) {//如果发生碰撞
		m_nIsDie = true;//isDie为true，意思是子弹死了
	}

	return *this;
}

bool CBulletObject::MoveBullet(vector<CTankObject>& vecTankObject)
{
	ClsObject();
	switch (m_nDir) {
	case UP:
		m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		m_nPosY -= 1;
		BulletCollision(*this, vecTankObject);
		break;
	case DOWN: 
		m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		m_nPosY += 1;
		BulletCollision(*this, vecTankObject);
		break;
	case LEFT:
		m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		m_nPosX -= 1;
		BulletCollision(*this, vecTankObject);
		break;
	case RIGHT:
		m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		m_nPosX += 1;
		BulletCollision(*this, vecTankObject);
		break;
	default:
		break;
	}
	return false;
}

bool CBulletObject::BulletCollision(CBulletObject & BulletObject, vector<CTankObject>& vecTankObject)
{
	
	int tempN = 0;
	int nType = m_pMapObject->getMapValue(m_nPosX, m_nPosY);
	CDrawObject a;
	switch (nType) {
	case 0:
		//擦除原来的子弹
		//m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		//ClsObject();
		//画新的子弹
		//COORD next=getNextCoord(BulletObject);
		getMapObj()->setMapValue(m_nPosY, m_nPosX, BulletObject.m_nType);
		DrawObject(m_nPosX, m_nPosY, nType);
		break;
	case 1:
		//擦除原来的子弹
		//m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		//ClsObject();
		BulletObject.m_nIsDie = true;
		tempN = 1;
		break;
	case 2:
		//擦除原来的子弹
		//m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);
		//ClsObject();
		//擦除原来的土墙
		//COORD next = getNextCoord(BulletObject);
		//getMapObj()->setMapValue(m_nPosY, m_nPosX, 0);
		m_pMapObject->setMapValue(m_nPosY, m_nPosX, 0);

		a.eraseChar(m_nPosX, m_nPosY, "  ", 0);
		BulletObject.m_nIsDie = true;
		tempN = 1;
		break;
	case 4:case 5: 
		BulletObject.m_nIsDie = true;
		if (BulletObject.m_nType == 4 || BulletObject.m_nType == 5);		
		else {
				for (int i = 0;i < vecTankObject.size();i++) {
				if (BulletObject == vecTankObject[i]) {
					if (vecTankObject[i].getTankBlood() - 1 > 0)
						vecTankObject[i].putTankBlood(vecTankObject[i].getTankBlood() - 1);
					
					else {
						int num = vecTankObject[i].getTankType();
						vecTankObject[i].ClsObject();
						for (int j = 0;j < 6;j++) {
							m_pMapObject->setMapValue(vecTankObject[i].getbody(j).Y, vecTankObject[i].getbody(j).X, 0);
						}
						vecTankObject.erase(vecTankObject.begin() + i);
						if (tankSum > 0);
						//getTankBirthPlace();
					}
				}
			}
		}
		tempN = 1;
		break;
	case 6:case 7:case 8:
		BulletObject.m_nIsDie = true;
		if (BulletObject.m_nType == 4 || BulletObject.m_nType == 5) {
			for (int i = 0;i < vecTankObject.size();i++) {
				if (BulletObject == vecTankObject[i]) {
					if (vecTankObject[i].getTankBlood() - 1 > 0)
						vecTankObject[i].putTankBlood(vecTankObject[i].getTankBlood() - 1);
					else {
						int num = vecTankObject[i].getTankType();
						vecTankObject[0].putTankScore(vecTankObject[0].getTankScores() + 10);
						vecTankObject[i].ClsObject();
						for (int j = 0;j < 6;j++) {
							m_pMapObject->setMapValue(vecTankObject[i].getbody(j).Y, vecTankObject[i].getbody(j).X, 0);
						}
						vecTankObject.erase(vecTankObject.begin() + i);
						if(tankSum>0)
						tankSum = tankSum - 1;
						if (tankSum > 0) {
							//当坦克被击毁是生成一个新坦克
							CTankObject TemTankObject;
							TemTankObject = TemTankObject.getTankBirthPlace(num);
							vecTankObject.push_back(TemTankObject);
							for (int j = 0;j < 6;j++) {

								m_pMapObject->setMapValue(TemTankObject.getbody(j).Y, TemTankObject.getbody(j).X, TemTankObject.getm_nType());
							}
							for (int i = 0;i <vecTankObject.size();i++) {
								vecTankObject[i].setMapObj(m_pMapObject);
								vecTankObject[i].DrawObject();
							}
						}
						//getTankBirthPlace();
					}
					break;
				}
			}
		}
		tempN = 1;
		break;
	}
	if (1 == tempN)
		return true;
	else 
		return false;
}

COORD CBulletObject::getNextCoord(CBulletObject BulletObject)
{
	COORD a;
	switch (m_nDir) {
	case UP:
		 a.X = m_nPosX;
		a.Y = m_nPosY - 1;
		break;
	case DOWN:
		a.X = m_nPosX;
		a.Y = m_nPosY + 1;
		break;
	case LEFT:
		a.X = m_nPosX-1;
		 a.Y = m_nPosY;
		break;
	case RIGHT:
		a.X = m_nPosX + 1;
		a.Y = m_nPosY;
		break;
	}
	return a;
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
		m_nPosY = m_nPosY - 2;break;

	case DOWN:
		m_nPosY = m_nPosY +2;break;
	case LEFT:
		m_nPosX = m_nPosX-2;break;
	case RIGHT:
		m_nPosX = m_nPosX + 2;break;
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
			if ((TankObject.getbody(i).X == m_nPosX) &&(TankObject.getbody(i).Y == m_nPosY))
				return true;
		}
	}
	return false;
}

bool CBulletObject::getBulletIsDie()
{
	return m_nIsDie;
}

int CBulletObject::getBulletPosX()
{
	return m_nPosX;
}

int CBulletObject::getBulletPosY()
{
	return m_nPosY;
}

int CBulletObject::getBulletDir()
{
	return m_nDir;
}

int CBulletObject::getBulletType()
{
	return m_nType;
}

int CBulletObject::getBulletATK()
{
	return m_nATK;
}

CMapObject*  CBulletObject::getMapObj()
{
	return m_pMapObject;
}
