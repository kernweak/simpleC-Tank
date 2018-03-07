#pragma once
#include "BaseObject.h"
#include "MapObject.h"
#include "DrawObject.h"
enum DIRE {
	UP, DOWN, RIGHT, LEFT,
};
class CTankObject
	:virtual public CBaseObject
{
public:
	CTankObject();
	~CTankObject();
	bool DrawObject();//画坦克
	bool ClsObject();//擦坦克
public:
	//根据类型获取坦克出生地，返回对应的坦克（用于重生）
	CTankObject getTankBirthPlace(int nType);
	bool MoveTank(char nDir);//移动坦克
	bool TankCollision(CTankObject TankObject, char nDir);//碰撞判断
	bool TankCollisionTurn(CTankObject& TankObject, char nDir);//转向碰撞判断
	void setMapObj(CMapObject* pMapObject);//设置地图的对象，每个坦克对象都有地图的地址
	CMapObject* getMapObj();
	int initp(DIRE dir,CTankObject& temp);
	COORD getbody(int i);
	int getm_nType();

//
//	/////////////////////
//	//这一组函数用于返回坦克属性，在创建子弹是用到
	bool getTankIsDie();
	int getAlignment();
	int getTankPosX();
	int getTankPosY();
	int getTankDir();
	int getTankType();
	int getTankBlood();
	int putTankBlood(int x);
	int getTankScores();
private:
	bool m_IsDie;//坦克是否死亡
	int m_Alignment;//所属阵营
	int m_nPosX;  //坦克X轴坐标
	int m_nPosY; //坦克Y坐标
	int m_nDir;  //坦克当前方向
	int m_nType;  //坦克类型
	int m_nBlood;  //坦克血量
	int m_nScore;  //坦克杀敌分数
	CMapObject* m_pMapObject;  //地图对象指针
	COORD body[6] = {};
	
};

