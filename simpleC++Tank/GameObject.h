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
	bool InitSometing();//��ʼ��һЩ��Ϣ
	bool WelcomeUI();//��ӭ����
	void menu();
	bool InitTankInfo();//��ʼ��̹����Ϣ
	bool StartGame();//��ʼ��Ϸ
	//ͨ�������ƶ�̹��
//	bool MoveSelfAndALLY();
	//ͨ��A*�ƶ��з�̹��
//	bool MoveNPC();
	CMapObject& getMap();
	void prints();
private:
	//��ͼ����������Ϸ����ʹ�øõ�ͼ����
	CMapObject m_MapObject;
	CMapObject pushMap(CMapObject& mapadd);
	CMapObject pushOneTankMap(CMapObject & mapadd,int i);
	//̹����������һ���ڶ�һ������Һ��Ѿ�
	vector<CTankObject> m_vecTankObject;
	vector<CBulletObject> m_vecBulletObject;
	void ShowCursor();//���ع��
	 //���ÿ���̨
	bool SetWindowSize(char* pszWindowTitle, int nX, int nY);
	//��Ӣ���л�
	bool shiftThing();

};

