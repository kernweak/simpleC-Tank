#include "stdafx.h"
#include "MapEdit.h"
#include <Windows.h>


void CMapEdit::OutPutPos(int nX, int nY) {
	char szBuf[100] = { 0 };
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d ", nX / 2, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(56, 1, szBuf, 7);
}

int CMapEdit::KeyEventProc(KEY_EVENT_RECORD ker) {
	int temp = 0;
	if (ker.bKeyDown)
		WriteChar(56, 1, "键盘 按下", 7);
	else
		WriteChar(56, 1, "键盘 弹起", 7);
	if (0x5A == ker.wVirtualKeyCode)
		temp = 1;
	return temp;
}

void CMapEdit::MouseEventProc(MOUSE_EVENT_RECORD mer, CMapObject& m_MapObject) {
	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			m_MapObject.setMapValue(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y,1);
			WriteChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "█", 7);
			WriteChar(56, 1, "左键 单击", 7);
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			m_MapObject.setMapValue(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, 2);
			WriteChar(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y, "▓", 4);
			WriteChar(56, 1, "右键 单击", 7);
		}
		break;
	case DOUBLE_CLICK:
		WriteChar(56, 1, "双     击", 7);
		break;
	case MOUSE_MOVED:
		OutPutPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
		break;
	}
}


int CMapEdit::MessageLoop(CMapObject & m_MapObject){
	WriteChar(56, 2, "1左键是添加不可摧毁的障碍物", 7);
	WriteChar(56, 3, "2右键添加可摧毁的障碍物", 7);
	WriteChar(56, 4, "3按下z键退出编辑", 7);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_INSERT_MODE | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		if (stcRecord.EventType == KEY_EVENT) {

			int temp = 0;
			temp = KeyEventProc(stcRecord.Event.KeyEvent);
			if (temp == 1)break;

		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent, m_MapObject);
		}
	}
	return 0;
}




void CMapEdit::mapEdit(CMapObject & m_MapObject)
{
	m_MapObject.DrawMap();

	MessageLoop(m_MapObject);

}

CMapEdit::CMapEdit()
{
}


CMapEdit::~CMapEdit()
{
}
