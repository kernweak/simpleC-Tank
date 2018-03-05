#pragma once
#include "BaseObject.h"
//#include "BulletObject.h"
#include "MapObject.h"
//#include "TankObject.h"
#include<Windows.h>
#include"DrawObject.h"
class CGameObject
{
public:
	CGameObject();
	~CGameObject();
public:
	bool InitSometing();//初始化一些信息
	bool WelcomeUI();//欢迎界面
//	bool InitTankInfo();//初始化坦克信息
//	bool StartGame();//开始游戏
	//通过键盘移动坦克
//	bool MoveSelfAndALLY();
	//通过A*移动敌方坦克
//	bool MoveNPC();
private:
	//地图对象（整个游戏都是使用该地图对象）
	CMapObject m_MapObject;

	//坦克向量，第一个第二一个是玩家和友军
//	vector<CTankObject> m_vecTankObject;
//	vector<CBulletObject> m_vecBulletObject;
	void ShowCursor();//隐藏光标
	 //设置控制台
	bool SetWindowSize(char* pszWindowTitle, int nX, int nY);
	//中英文切换
	bool shiftThing();
};

