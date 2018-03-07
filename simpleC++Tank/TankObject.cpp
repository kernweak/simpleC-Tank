#include "stdafx.h"
#include "TankObject.h"


CTankObject::CTankObject()
{
}


CTankObject::~CTankObject()
{
}

bool CTankObject::DrawObject()
{	CDrawObject a1;
for (int i = 0;i < 6;i++) {
	a1.WriteChar(body[i].X, body[i].Y, "█", m_nType);
	}
	return true;
}

bool CTankObject::ClsObject()
{
	CDrawObject a1;
	for (int i = 0;i < 6;i++) {
		a1.WriteChar(body[i].X, body[i].Y, "  ", m_nType);
	}
	return true;
}

CTankObject CTankObject::getTankBirthPlace(int nType)//4为自己，5为友军
{
	CTankObject temp;
	temp.m_IsDie = false;
	if (4 == nType) {
		temp.m_Alignment = 1;
		temp.m_nPosX = 24;
		temp.m_nPosY = 46;
		temp.m_nDir = UP;
		temp.m_nType = 4;
		temp.m_nBlood = 3;
		temp.m_nScore = 0;
		initp(UP, temp);
	}
	if (5 == nType) {
		temp.m_Alignment = 1;
		temp.m_nPosX = 34;
		temp.m_nPosY = 46;
		temp.m_nDir = UP;
		temp.m_nType = 5;
		temp.m_nBlood = 3;
		temp.m_nScore = 0;
		initp(UP, temp);
	}
	if (6 == nType) {
		temp.m_Alignment = 2;
		temp.m_nPosX = 2;
		temp.m_nPosY = 2;
		temp.m_nDir = DOWN;
		temp.m_nType = 6;
		temp.m_nBlood = 1;
		temp.m_nScore = 0;
		initp(DOWN, temp);
	}
	if (7 == nType) {
		temp.m_Alignment = 2;
		temp.m_nPosX = 29;
		temp.m_nPosY = 2;
		temp.m_nDir = DOWN;
		temp.m_nType = 7;
		temp.m_nBlood = 2;
		temp.m_nScore = 0;
		initp(DOWN, temp);
	}
	if (8 == nType) {
		temp.m_Alignment = 2;
		temp.m_nPosX = 53;
		temp.m_nPosY = 2;
		temp.m_nDir = DOWN;
		temp.m_nType =8;
		temp.m_nBlood = 3;
		temp.m_nScore = 0;
		initp(DOWN, temp);
	}
	return temp;
}

bool CTankObject::MoveTank(char nDir)
{
	ClsObject();
	CTankObject TemTankObject(*this);
	switch (nDir) {
	case 'w':
			if (this->m_nDir != UP) {
				if (!TankCollisionTurn(*this, 'w'))
					return false;
				this->m_nDir = UP;
				initp(UP, *this);
			}
			else
			{
				if(!TankCollision(*this, 'w'))return false;
				this->m_nPosY = this->m_nPosY - 1;
				for (int i = 0;i < 6;i++) {
					this->body[i].Y = this->body[i].Y - 1;
				}
			}
	break;
	case 's':
		if (this->m_nDir != DOWN) {
			if (!TankCollisionTurn(*this, 's'))
				return false;
			this->m_nDir = DOWN;
			initp(DOWN, *this);
		}
		else
		{
			if (!TankCollision(*this, 's'))return false;
			this->m_nPosY = this->m_nPosY + 1;
			for (int i = 0;i < 6;i++) {
				this->body[i].Y = this->body[i].Y + 1;
			}
		}
		break;

	case 'a':
		if (this->m_nDir != LEFT) {
			if (!TankCollisionTurn(*this, 'a'))
				return false;
			this->m_nDir = LEFT;
			initp(LEFT, *this);
		}
		else
		{
			if (!TankCollision(*this, 'a'))return false;
			this->m_nPosX = this->m_nPosX- 1;
			for (int i = 0;i < 6;i++) {
				this->body[i].X = this->body[i].X- 1;
			}
		}
		break;
	case 'd':
		if (this->m_nDir != RIGHT) {
			if (!TankCollisionTurn(*this, 'd'))
				return false;
			this->m_nDir = RIGHT;
			initp(RIGHT, *this);
		}
		else
		{
			if (!TankCollision(*this, 'd'))return false;
			this->m_nPosX = this->m_nPosX+ 1;
			for (int i = 0;i < 6;i++) {
				this->body[i].X = this->body[i].X+ 1;
			}
		}
		break;
		
	}
	DrawObject();
	return true;
}

bool CTankObject::TankCollision(CTankObject TankObject, char nDir)
{
	switch (nDir) {
	case 'w':
		if (m_pMapObject->getMapValue(TankObject.body[0].X, TankObject.body[0].Y - 1) != 0||
			m_pMapObject->getMapValue(TankObject.body[2].X, TankObject.body[2].Y - 1) != 0||
			m_pMapObject->getMapValue(TankObject.body[3].X, TankObject.body[3].Y - 1) != 0
			)
			return false;
		break;
	case 's':
		if (m_pMapObject->getMapValue(TankObject.body[0].X, TankObject.body[0].Y + 1) != 0 ||
			m_pMapObject->getMapValue(TankObject.body[2].X, TankObject.body[2].Y + 1) != 0 ||
			m_pMapObject->getMapValue(TankObject.body[3].X, TankObject.body[3].Y + 1) != 0
			)
			return false;
		break;
	case 'a':
		if (m_pMapObject->getMapValue(TankObject.body[0].X - 1, TankObject.body[0].Y) != 0 ||
			m_pMapObject->getMapValue(TankObject.body[2].X - 1, TankObject.body[2].Y) != 0 ||
			m_pMapObject->getMapValue(TankObject.body[3].X - 1, TankObject.body[3].Y) != 0
			)
			return false;
		break;
	case 'd':
		if (m_pMapObject->getMapValue(TankObject.body[0].X + 1, TankObject.body[0].Y) != 0 ||
			m_pMapObject->getMapValue(TankObject.body[2].X + 1, TankObject.body[2].Y) != 0 ||
			m_pMapObject->getMapValue(TankObject.body[3].X + 1, TankObject.body[3].Y) != 0
			)
			return false;
		break;
	default:
		break;
	}
	return true;
}

bool CTankObject::TankCollisionTurn(CTankObject& TankObject, char nDir)
{
	switch (nDir) {
	case 'w':
		if (TankObject.m_nDir == LEFT) {
			if (m_pMapObject->getMapValue(TankObject.body[2].X - 1, TankObject.body[2].Y) != 0 )
			{
				this->m_nPosY = this->m_nPosY - 1;
				initp(UP, *this);
			}
		}
		else if (TankObject.m_nDir == RIGHT) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X + 1, TankObject.body[3].Y) != 0)
			{
				this->m_nPosY = this->m_nPosY - 1;
				initp(UP, *this);
			}
		}
		else if (TankObject.m_nDir == DOWN) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X, TankObject.body[3].Y + 1) != 0 ||
				m_pMapObject->getMapValue(TankObject.body[2].X, TankObject.body[2].Y + 1) != 0
				)
			{
				this->m_nPosY = this->m_nPosY - 1;
				initp(UP, *this);
			}
		}
		break;
	case 's':
		if (TankObject.m_nDir == LEFT) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X - 1, TankObject.body[3].Y) != 0)
			{
				this->m_nPosY = this->m_nPosY + 1;
				initp(DOWN, *this);
			}
		}
		else if (TankObject.m_nDir == RIGHT) {
			if (m_pMapObject->getMapValue(TankObject.body[2].X + 1, TankObject.body[2].Y) != 0)
			{
				this->m_nPosY = this->m_nPosY + 1;
				initp(DOWN, *this);
			}
		}
		else if (TankObject.m_nDir == UP) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X, TankObject.body[3].Y - 1) != 0 ||
				m_pMapObject->getMapValue(TankObject.body[2].X, TankObject.body[2].Y - 1) != 0
				)
			{
				this->m_nPosY = this->m_nPosY + 1;
				initp(DOWN, *this);
			}
		}
		break;
		
	case 'a':
		if (TankObject.m_nDir ==UP) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X , TankObject.body[3].Y-1) != 0)
			{
				this->m_nPosX = this->m_nPosX - 1;
				initp(LEFT, *this);
			}
		}
		else if (TankObject.m_nDir == DOWN) {
			if (m_pMapObject->getMapValue(TankObject.body[2].X, TankObject.body[2].Y+1) != 0)
			{
				this->m_nPosX = this->m_nPosX - 1;
				initp(LEFT, *this);
			}
		}
		else if (TankObject.m_nDir == RIGHT) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X+1, TankObject.body[3].Y ) != 0 ||
				m_pMapObject->getMapValue(TankObject.body[2].X+1, TankObject.body[2].Y) != 0
				)
			{
				this->m_nPosX = this->m_nPosX - 1;
				initp(LEFT, *this);
			}
		}
		break;
	case 'd':
		if (TankObject.m_nDir == UP) {
			if (m_pMapObject->getMapValue(TankObject.body[2].X, TankObject.body[3].Y - 1) != 0)
			{
				this->m_nPosX = this->m_nPosX + 1;
				initp(RIGHT, *this);
			}
		}
		else if (TankObject.m_nDir == DOWN) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X, TankObject.body[2].Y + 1) != 0)
			{
				this->m_nPosX = this->m_nPosX + 1;
				initp(RIGHT, *this);
			}
		}
		else if (TankObject.m_nDir == LEFT) {
			if (m_pMapObject->getMapValue(TankObject.body[3].X - 1, TankObject.body[3].Y) != 0 ||
				m_pMapObject->getMapValue(TankObject.body[2].X - 1, TankObject.body[2].Y) != 0
				)
			{
				this->m_nPosX = this->m_nPosX + 1;
				initp(RIGHT, *this);
			}
		}
		break;
	default:
		break;
	}
	return true;
}

void CTankObject::setMapObj(CMapObject * pMapObject)
{
	m_pMapObject = pMapObject;
}

CMapObject * CTankObject::getMapObj()
{
	return m_pMapObject;
}

int CTankObject::initp(DIRE dir, CTankObject& temp)
{
	if (UP == dir) {
		temp.body[0].X = temp.m_nPosX;
		temp.body[0].Y = temp.m_nPosY - 1;
		temp.body[1].X = temp.m_nPosX;
		temp.body[1].Y = temp.m_nPosY;
		temp.body[2].X = temp.m_nPosX - 1;
		temp.body[2].Y = temp.m_nPosY;
		temp.body[3].X = temp.m_nPosX + 1;
		temp.body[3].Y = temp.m_nPosY;
		temp.body[4].X = temp.m_nPosX - 1;
		temp.body[4].Y = temp.m_nPosY + 1;
		temp.body[5].X = temp.m_nPosX + 1;
		temp.body[5].Y = temp.m_nPosY + 1;
	}
	if (DOWN == dir) {
		temp.body[0].X = temp.m_nPosX;
		temp.body[0].Y = temp.m_nPosY + 1;
		temp.body[1].X = temp.m_nPosX;
		temp.body[1].Y = temp.m_nPosY;
		temp.body[2].X = temp.m_nPosX + 1;
		temp.body[2].Y = temp.m_nPosY;
		temp.body[3].X = temp.m_nPosX - 1;
		temp.body[3].Y = temp.m_nPosY;
		temp.body[4].X = temp.m_nPosX + 1;
		temp.body[4].Y = temp.m_nPosY-1;
		temp.body[5].X = temp.m_nPosX - 1;
		temp.body[5].Y = temp.m_nPosY - 1;
	}
	if (LEFT == dir) {
		temp.body[0].X = temp.m_nPosX-1;
		temp.body[0].Y = temp.m_nPosY;
		temp.body[1].X = temp.m_nPosX;
		temp.body[1].Y = temp.m_nPosY;
		temp.body[2].X = temp.m_nPosX;
		temp.body[2].Y = temp.m_nPosY + 1;
		temp.body[3].X = temp.m_nPosX ;
		temp.body[3].Y = temp.m_nPosY - 1;
		temp.body[4].X = temp.m_nPosX + 1;
		temp.body[4].Y = temp.m_nPosY + 1;
		temp.body[5].X = temp.m_nPosX + 1;
		temp.body[5].Y = temp.m_nPosY - 1;
	}
	if (RIGHT == dir) {
		temp.body[0].X = temp.m_nPosX + 1;
		temp.body[0].Y = temp.m_nPosY;
		temp.body[1].X = temp.m_nPosX;
		temp.body[1].Y = temp.m_nPosY;
		temp.body[2].X = temp.m_nPosX;
		temp.body[2].Y = temp.m_nPosY - 1;
		temp.body[3].X = temp.m_nPosX;
		temp.body[3].Y = temp.m_nPosY + 1;
		temp.body[4].X = temp.m_nPosX - 1;
		temp.body[4].Y = temp.m_nPosY - 1;
		temp.body[5].X = temp.m_nPosX - 1;
		temp.body[5].Y = temp.m_nPosY + 1;
	}
	return 0;
}

COORD CTankObject::getbody(int i)
{
	
	return body[i];
}

int CTankObject::getm_nType()
{
	return m_nType;
}

bool CTankObject::getTankIsDie()
{
	return m_IsDie;
}

int CTankObject::getAlignment()
{
	return m_Alignment;
}

int CTankObject::getTankPosX()
{
	return m_nPosX;
}

int CTankObject::getTankPosY()
{
	return m_nPosY;
}

int CTankObject::getTankDir()
{
	return m_nDir;
}

int CTankObject::getTankType()
{
	return m_nType;
}

int CTankObject::getTankBlood()
{
	return m_nBlood;
}

int CTankObject::getTankScores()
{
	return m_nScore;
}


