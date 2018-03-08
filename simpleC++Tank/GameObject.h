#pragma once
#include "BaseObject.h"
#include "BulletObject.h"
#include "MapObject.h"
#include "MapEdit.h"
#include "TankObject.h"
#include<Windows.h>
#include"DrawObject.h"
#define PALY_MY 0
#define PALY_FRIEND 1
#define PALY_ANAMY1 2
#define PALY_ANAMY2 3
#define PALY_ANAMY3 4

class CGameObject
{
public:
	CGameObject();
	~CGameObject();
public:
	bool InitSometing();//初始化一些信息
	bool WelcomeUI();//欢迎界面
	void menu();
	bool InitTankInfo();//初始化坦克信息
	bool StartGame();//开始游戏
	//通过键盘移动坦克
//	bool MoveSelfAndALLY();
	//通过A*移动敌方坦克
//	bool MoveNPC();
	CMapObject& getMap();
	void prints();
private:
	//地图对象（整个游戏都是使用该地图对象）
	CMapObject m_MapObject;
	CMapObject pushMap(CMapObject& mapadd);
	CMapObject pushOneTankMap(CMapObject & mapadd,int i);
	//坦克向量，第一个第二一个是玩家和友军
	vector<CTankObject> m_vecTankObject;
	vector<CBulletObject> m_vecBulletObject;
	void ShowCursor();//隐藏光标
	 //设置控制台
	bool SetWindowSize(char* pszWindowTitle, int nX, int nY);
	//中英文切换
	bool shiftThing();

};

