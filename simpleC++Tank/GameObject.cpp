#include "stdafx.h"
#include "GameObject.h"
#include <conio.h>
#include <time.h>  

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
	char dir[4] = { 'w','s', 'd','a' };
	clock_t start, finish;//敌军坦克移动间隔
	start = clock();
	while (press != 0X1b && stopMove) {
		if (_kbhit()) {
			press = _getch();
			if (press == 0x20) {
				pauseFlag = !pauseFlag;
			}
			if (press == 0x71)//发射炮弹
			{
			}

			for (int i = 0;i < 6;i++) {//先将玩家坦克从地图擦除再移动
				m_MapObject.setMapValue(m_vecTankObject[0].getbody(i).Y, m_vecTankObject[0].getbody(i).X, 0);
			}
			//移动0号坦克，也就是玩家坦克
			m_vecTankObject[0].MoveTank(press);
			//把容器0位置坦克写入到地图中
			pushOneTankMap(m_MapObject, 0);
			for (int i = 0;i < m_vecTankObject.size();i++) {
				//把更新过的地图写入到没一个坦克
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
				}
				for (int i = 0;i < m_vecTankObject.size();i++) {
					//把更新过的地图写入到没一个坦克
					m_vecTankObject[i].setMapObj(&m_MapObject);
					m_vecTankObject[i].DrawObject();
				}
	//		}

		}

	}

	return true;
}
