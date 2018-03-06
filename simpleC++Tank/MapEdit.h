#pragma once
#include "MapObject.h"
class CMapEdit :
	public CMapObject
{public:
	void mapEdit(CMapObject& m_MapObject);//±à¼­µØÍ¼

	CMapEdit();
	~CMapEdit();
private:
	void OutPutPos(int nX, int nY);
	int KeyEventProc(KEY_EVENT_RECORD ker);
	int MessageLoop(CMapObject & m_MapObject);
	void MouseEventProc(MOUSE_EVENT_RECORD mer, CMapObject& m_MapObject);
};

