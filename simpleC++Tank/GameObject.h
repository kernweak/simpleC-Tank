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
	bool InitSometing();//��ʼ��һЩ��Ϣ
	bool WelcomeUI();//��ӭ����
//	bool InitTankInfo();//��ʼ��̹����Ϣ
//	bool StartGame();//��ʼ��Ϸ
	//ͨ�������ƶ�̹��
//	bool MoveSelfAndALLY();
	//ͨ��A*�ƶ��з�̹��
//	bool MoveNPC();
private:
	//��ͼ����������Ϸ����ʹ�øõ�ͼ����
	CMapObject m_MapObject;

	//̹����������һ���ڶ�һ������Һ��Ѿ�
//	vector<CTankObject> m_vecTankObject;
//	vector<CBulletObject> m_vecBulletObject;
	void ShowCursor();//���ع��
	 //���ÿ���̨
	bool SetWindowSize(char* pszWindowTitle, int nX, int nY);
	//��Ӣ���л�
	bool shiftThing();
};

