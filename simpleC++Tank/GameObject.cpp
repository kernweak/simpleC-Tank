#include "stdafx.h"
#include "GameObject.h"


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

bool CGameObject::InitTankInfo()
{
	CTankObject TemTankObject;
	TemTankObject = TemTankObject.getTankBirthPlace(PALY_MY);
	m_vecTankObject.push_back(TemTankObject);
	for (int i = 0;i < m_vecTankObject.size();i++) {
		m_vecTankObject[i].setMapObj(&m_MapObject);
		m_vecTankObject[i].DrawObject();
	}
	return true;
}

bool CGameObject::StartGame()
{

	return false;
}
