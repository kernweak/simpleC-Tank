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
	SetWindowSize("坦克大战", 140, 50);
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
	// TODO: 在此处插入 return 语句
}

void CGameObject::prints()
{	//打印得分
	int c=m_vecTankObject[0].getTankScores();
	string b = "得分是:";
	string  d= to_string(c);
	b = b + d;
	char* p = (char*)b.c_str();
	CDrawObject a;
	a.WriteChar(56, 2,p , 7);
	//打印剩余血量
	c = m_vecTankObject[0].getTankBlood();
	b = "玩家坦克剩余血量是:";
	d = to_string(c);
	b = b + d;
	p = (char*)b.c_str();
	a.WriteChar(56, 3, p, 7);

	c = tankSum;
	b = "此关剩余刷新坦克数量为:";
	d = to_string(c);
	b = b + d;
	 p = (char*)b.c_str();
	a.WriteChar(56, 4, p, 7);

//	a.WriteChar(56, 4, "3按下z键退出编辑", 7);
}

void CGameObject::printIntorduce()
{	
	CDrawObject a;
	string b = "坦克颜色:";
	char* p = (char*)b.c_str();
	a.WriteChar(56, 13, p, 7);
	a.WriteChar(61, 13, "█", 5);
	b = "坦克生命:3";
	p = (char*)b.c_str();
	a.WriteChar(56, 14, p, 7);

	b = "坦克颜色:";
	 p = (char*)b.c_str();
	a.WriteChar(56, 15, p, 7);
	a.WriteChar(61, 15, "█", 6);
	b = "坦克生命:1";
	p = (char*)b.c_str();
	a.WriteChar(56, 16, p, 7);

	b = "坦克颜色:";
	p = (char*)b.c_str();
	a.WriteChar(56, 17, p, 7);
	a.WriteChar(61, 17, "█", 7);
	b = "坦克生命:2";
	p = (char*)b.c_str();
	a.WriteChar(56, 18, p, 7);

	b = "坦克颜色:";
	p = (char*)b.c_str();
	a.WriteChar(56, 19, p, 7);
	a.WriteChar(61, 19, "█", 8);
	b = "坦克生命:2";
	p = (char*)b.c_str();
	a.WriteChar(56, 20, p, 7);

	b = "坦克颜色:";
	p = (char*)b.c_str();
	a.WriteChar(56, 21, p, 7);
	a.WriteChar(61, 21, "█", 4);
	b = "坦克生命:5";
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
		char f1[50] = "*              1.开始游戏                *";
		char f2[50] = "*              2.编辑地图                *";
		char f3[50] = "*              3.继续游戏                *";
		char f4[50] = "*              4.保存游戏                *";
		char f5[50] = "*              5.退出游戏                *";
		a.WriteChar(20, 20, "******************************************", 7);
		a.WriteChar(20, 21, "****************请选择下列选项************", 7);
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
	srand(time(NULL));//生成一个随机数
	bool pauseFlag = false;//1为暂停
	bool stopMove = true;
	char press = 0;
	char dir[4] = { 'w','s', 'a','d' };
	clock_t start, finish;//敌军坦克移动间隔
	clock_t start1, finish1;//子弹移动间隔
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
			if (press == 0x71)//发射炮弹
			{
				CBulletObject TemBulletObject;
				TemBulletObject= TemBulletObject.CreateBullet(m_vecTankObject[0], m_vecTankObject);
				m_vecBulletObject.push_back(TemBulletObject);
				//if(TemBulletObject.getBulletIsDie)
			}

			for (int i = 0;i < 6;i++) {//先将玩家坦克从地图擦除再移动
				m_MapObject.setMapValue(m_vecTankObject[0].getbody(i).Y, m_vecTankObject[0].getbody(i).X, 0);
			}
			//移动0号坦克，也就是玩家坦克
			m_vecTankObject[0].MoveTank(press);
			//把容器0位置坦克写入到地图中
			pushOneTankMap(m_MapObject, 0);
			for (int i = 0;i < m_vecTankObject.size();i++) {
				//把更新过的地图写入到每一个坦克
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
			//先将其他坦克从地图擦除再移动
			for (int i = 1;i <m_vecTankObject.size();i++) {
				for (int j = 0;j < 6;j++) {//先将其他坦克从地图擦除再移动
					m_MapObject.setMapValue(m_vecTankObject[i].getbody(j).Y, m_vecTankObject[i].getbody(j).X, 0);
				}
			}
			//移动其他坦克
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
					//把更新过的地图写入到每一个坦克
					m_vecTankObject[i].setMapObj(&m_MapObject);
					m_vecTankObject[i].DrawObject();
				}
	//		}

		}
		finish1 = clock();
		if (finish1 - start1 > 100) {
			start1 = finish1;
			for (int i = 0;i < m_vecBulletObject.size();i++) {
				//先判断子弹是否已经是死的了，死的就不移动了
				if (!m_vecBulletObject[i].getBulletIsDie()) {
					//如果子弹不是死的，先删除子弹原来所在位置
					m_vecBulletObject[i].MoveBullet(m_vecTankObject);
					getMap()=*(m_vecBulletObject[i].getMapObj());
					if (!m_vecBulletObject[i].getBulletIsDie())//移动完判断是否死了，死了就不打印了
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
