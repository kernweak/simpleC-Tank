#include "stdafx.h"
#include "GameObject.h"
#include <conio.h>
#include <time.h>  
#include <string>
#include <iostream>
using namespace std;
#include <sstream>

CGameObject::CGameObject()
{
	CMapObject m_MapObject;
	

}


CGameObject::~CGameObject()
{
}

bool CGameObject::InitSometing()
{
	ShowCursor();
	SetWindowSize("̹�˴�ս", 140, 50);
	shiftThing();
	return true;
}

bool CGameObject::WelcomeUI()
{
	CDrawObject b;
	b.DrawWelcome();
	return true;
}



CMapObject & CGameObject::getMap()
{
	return m_MapObject;
	// TODO: �ڴ˴����� return ���
}

void CGameObject::prints()
{	//��ӡ�÷�
	int c=m_vecTankObject[0].getTankScores();
	string b = "�÷���:";
	string  d= to_string(c);
	b = b + d;
	char* p = (char*)b.c_str();
	CDrawObject a;
	a.WriteChar(56, 2,p , 7);
	//��ӡʣ��Ѫ��
	c = m_vecTankObject[0].getTankBlood();
	b = "���̹��ʣ��Ѫ����:";
	d = to_string(c);
	b = b + d;
	p = (char*)b.c_str();
	a.WriteChar(56, 3, p, 7);

	c = tankSum;
	b = "�˹�ʣ��ˢ��̹������Ϊ:";
	d = to_string(c);
	b = b + d;
	 p = (char*)b.c_str();
	a.WriteChar(56, 4, p, 7);

//	a.WriteChar(56, 4, "3����z���˳��༭", 7);
}

void CGameObject::printIntorduce()
{	
	CDrawObject a;
	string b = "̹����ɫ:";
	char* p = (char*)b.c_str();
	a.WriteChar(56, 13, p, 7);
	a.WriteChar(61, 13, "��", 5);
	b = "̹������:3";
	p = (char*)b.c_str();
	a.WriteChar(56, 14, p, 7);

	b = "̹����ɫ:";
	 p = (char*)b.c_str();
	a.WriteChar(56, 15, p, 7);
	a.WriteChar(61, 15, "��", 6);
	b = "̹������:1";
	p = (char*)b.c_str();
	a.WriteChar(56, 16, p, 7);

	b = "̹����ɫ:";
	p = (char*)b.c_str();
	a.WriteChar(56, 17, p, 7);
	a.WriteChar(61, 17, "��", 7);
	b = "̹������:2";
	p = (char*)b.c_str();
	a.WriteChar(56, 18, p, 7);

	b = "̹����ɫ:";
	p = (char*)b.c_str();
	a.WriteChar(56, 19, p, 7);
	a.WriteChar(61, 19, "��", 8);
	b = "̹������:2";
	p = (char*)b.c_str();
	a.WriteChar(56, 20, p, 7);

	b = "̹����ɫ:";
	p = (char*)b.c_str();
	a.WriteChar(56, 21, p, 7);
	a.WriteChar(61, 21, "��", 4);
	b = "̹������:5";
	p = (char*)b.c_str();
	a.WriteChar(56, 22, p, 7);
}



void CGameObject::ShowCursor()
{
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOutStd, &cci);
}

bool CGameObject::SetWindowSize(char * pszWindowTitle, int nX, int nY)
{
	SetConsoleTitleA(pszWindowTitle);
	HANDLE hStdIn, hStdOut;
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD BufferSize = { pos.X + 1,pos.Y + 1 };
	if (!SetConsoleScreenBufferSize(hStdOut, BufferSize)) {
		//cout << "buffer err(" << BufferSize.X << BufferSize.Y << "," << GetLastError() << endl;
		printf("buffer err(%d,%d)%d\n", BufferSize.X, BufferSize.Y, GetLastError());
		return false;
	}
	SMALL_RECT srctWindow = { 0,0,nX,nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)) {
		printf("size err%d\n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1,nY + 1 };
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)) {
		//cout << "buffer err(" << BufferSize.X << BufferSize.Y << "," << GetLastError() << endl;
		("buffer err(%d,%d)%d\n", BufferSize.X, BufferSize.Y, GetLastError());
		return false;
	}
	return true;
}

bool CGameObject::shiftThing()
{
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
	return true;
}

void CGameObject::menu()
{
	CDrawObject a;
	while (1) {
		system("cls");
		char f1[50] = "*              1.��ʼ��Ϸ                *";
		char f2[50] = "*              2.�༭��ͼ                *";
		char f3[50] = "*              3.������Ϸ                *";
		char f4[50] = "*              4.������Ϸ                *";
		char f5[50] = "*              5.�˳���Ϸ                *";
		a.WriteChar(20, 20, "******************************************", 7);
		a.WriteChar(20, 21, "****************��ѡ������ѡ��************", 7);
		a.WriteChar(20, 22, "******************************************", 7);
		a.WriteChar(20, 23, f1, 7);
		a.WriteChar(20, 24, f2, 7);
		a.WriteChar(20, 25, f3, 7);
		a.WriteChar(20, 26, f4, 7);
		a.WriteChar(20, 27, f5, 7);
		a.WriteChar(20, 28, "******************************************", 7);
		int i = -1;
		CMapEdit r;
		cin >> i;
		if (i == 5)break;
		switch(i) {
		case 1:
			system("cls");
			getMap().DrawMap();
			StartGame();
			break;
		case 2:
			system("cls");
			r.mapEdit(getMap());
			break;
		case 5:
			break;
		}
	}
}

CMapObject CGameObject::pushOneTankMap(CMapObject & mapadd,int i)
{
	
		for (int j = 0;j < 6;j++) {
			mapadd.setMapValue(m_vecTankObject[i].getbody(j).Y,m_vecTankObject[i].getbody(j).X,  m_vecTankObject[i].getm_nType());
	}
	return mapadd;
}

CMapObject CGameObject::pushMap(CMapObject & mapadd)
{
	for (int i = 0;i < m_vecTankObject.size();i++) {
		for(int j = 0;j < 6;j++) {
			mapadd.setMapValue(m_vecTankObject[i].getbody(j).Y,m_vecTankObject[i].getbody(j).X, m_vecTankObject[i].getm_nType());
		}
		
	}
	return mapadd;
}

bool CGameObject::InitTankInfo()
{
	CTankObject TemTankObject;
	for (int i = 4;i < 9;i++) {
		TemTankObject = TemTankObject.getTankBirthPlace(i);
		m_vecTankObject.push_back(TemTankObject);
		pushMap(m_MapObject);
	}
		for (int i = 0;i < m_vecTankObject.size();i++) {
			m_vecTankObject[i].setMapObj(&m_MapObject);
			m_vecTankObject[i].DrawObject();
		}

	
	return true;
}



bool CGameObject::StartGame()
{
	InitTankInfo();
	srand(time(NULL));//����һ�������
	bool pauseFlag = false;//1Ϊ��ͣ
	bool stopMove = true;
	char press = 0;
	char dir[4] = { 'w','s', 'a','d' };
	clock_t start, finish;//�о�̹���ƶ����
	clock_t start1, finish1;//�ӵ��ƶ����
	start = clock();
	start1 = clock();
	printIntorduce();
	while (press != 0X1b && stopMove) {
		prints();
		if (_kbhit()) {
			press = _getch();
			if (press == 0x20) {
				pauseFlag = !pauseFlag;
			}
			if (press == 0x71)//�����ڵ�
			{
				CBulletObject TemBulletObject;
				TemBulletObject= TemBulletObject.CreateBullet(m_vecTankObject[0], m_vecTankObject);
				m_vecBulletObject.push_back(TemBulletObject);
				//if(TemBulletObject.getBulletIsDie)
			}

			for (int i = 0;i < 6;i++) {//�Ƚ����̹�˴ӵ�ͼ�������ƶ�
				m_MapObject.setMapValue(m_vecTankObject[0].getbody(i).Y, m_vecTankObject[0].getbody(i).X, 0);
			}
			//�ƶ�0��̹�ˣ�Ҳ�������̹��
			m_vecTankObject[0].MoveTank(press);
			//������0λ��̹��д�뵽��ͼ��
			pushOneTankMap(m_MapObject, 0);
			for (int i = 0;i < m_vecTankObject.size();i++) {
				//�Ѹ��¹��ĵ�ͼд�뵽ÿһ��̹��
				m_vecTankObject[i].setMapObj(&m_MapObject);
				m_vecTankObject[i].DrawObject();
			}

		}
		if (pauseFlag) {
			continue;
		}
		finish = clock();
		if (finish - start > 400) {
			start = finish;
			//�Ƚ�����̹�˴ӵ�ͼ�������ƶ�
			for (int i = 1;i <m_vecTankObject.size();i++) {
				for (int j = 0;j < 6;j++) {//�Ƚ�����̹�˴ӵ�ͼ�������ƶ�
					m_MapObject.setMapValue(m_vecTankObject[i].getbody(j).Y, m_vecTankObject[i].getbody(j).X, 0);
				}
			}
			//�ƶ�����̹��
			int a, b;
			
			b = rand() % 2;
//			for (int i = 0;i < b;i++) {
				for (int j = 1;j < m_vecTankObject.size();j++) {
						a = rand() % 4;
						m_vecTankObject[j].MoveTank(dir[a]);
						pushOneTankMap(m_MapObject, j);
						if ((a = rand() % 8) % 4 == 0) {
							CBulletObject TemBulletObject;
							if (m_vecTankObject[j].getm_nType() == 5 && (m_vecTankObject[j].getTankPosX() > 25 && m_vecTankObject[j].getTankPosX() < 33) && (m_vecTankObject[j].getTankPosY() > 41)) {
								TemBulletObject = TemBulletObject.CreateBullet(m_vecTankObject[j], m_vecTankObject);
								m_vecBulletObject.push_back(TemBulletObject);
							}
						}

				}
				for (int i = 0;i < m_vecTankObject.size();i++) {
					//�Ѹ��¹��ĵ�ͼд�뵽ÿһ��̹��
					m_vecTankObject[i].setMapObj(&m_MapObject);
					m_vecTankObject[i].DrawObject();
				}
	//		}

		}
		finish1 = clock();
		if (finish1 - start1 > 100) {
			start1 = finish1;
			for (int i = 0;i < m_vecBulletObject.size();i++) {
				//���ж��ӵ��Ƿ��Ѿ��������ˣ����ľͲ��ƶ���
				if (!m_vecBulletObject[i].getBulletIsDie()) {
					//����ӵ��������ģ���ɾ���ӵ�ԭ������λ��
					m_vecBulletObject[i].MoveBullet(m_vecTankObject);
					getMap()=*(m_vecBulletObject[i].getMapObj());
					if (!m_vecBulletObject[i].getBulletIsDie())//�ƶ����ж��Ƿ����ˣ����˾Ͳ���ӡ��
					{
						m_MapObject.setMapValue(m_vecBulletObject[i].getBulletPosY(), m_vecBulletObject[i].getBulletPosX(), m_vecBulletObject[i].getBulletType());
						m_vecBulletObject[i].DrawObject(m_vecBulletObject[i].getBulletPosX(), m_vecBulletObject[i].getBulletPosY(), m_vecBulletObject[i].getBulletType());
					}
				}
				else
					m_vecBulletObject.erase(m_vecBulletObject.begin()+i);
				
			}
		}

	}

	return true;
}
