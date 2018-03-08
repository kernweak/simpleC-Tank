#pragma once
#include "BaseObject.h"
#include "TankObject.h"

class CBulletObject :
	virtual public CBaseObject
{
public:
	CBulletObject();
	~CBulletObject();
public:
	bool DrawObject();//画子弹
	bool DrawObject(int nPosX, int nPosY, int nType);
	bool ClsObject();
	//bool ClsObject(int nPosX, int nPosY);
	////创建子弹（传入保存坦克的向量，主要用于子弹与坦克的碰撞）
	CBulletObject CreateBullet(CTankObject TankObject,vector<CTankObject>& vecTankObject);  //发射子弹的坦克
	//移动子弹
	bool MoveBullet(vector<CTankObject>& vecTankObject);
	//子弹碰撞检测
	bool BulletCollision(CBulletObject& BulletObject,//子弹对象
		vector<CTankObject>& vecTankObject);
	COORD getNextCoord(CBulletObject BulletObject);
private:
	
	//重载=运算符（创建子弹是，坦克对象对子弹对象赋值）
public:
	bool operator=(CTankObject TankObject);
	//重载==运算符（子弹与坦克的碰撞，子弹对象与坦克对象中坐标的比较）
	bool operator==(CTankObject TankObject);
	//获取子弹的属性
	bool getBulletIsDie();
	int getBulletPosX();
	int getBulletPosY();
	int getBulletDir();
	int getBulletType();
	int getBulletATK();
	CMapObject*  getMapObj();
private:
	bool m_nIsDie; //子弹是否存在
	int m_Alignement;//所属阵营
	int m_nPosX;//子弹x坐标
	int m_nPosY;//子弹Y坐标
	int m_nDir;//子弹方向
	int m_nType;//子弹类型
	int m_nATK;//子弹攻击力
	CMapObject* m_pMapObject;//地图对象
};

	