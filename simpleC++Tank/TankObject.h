#pragma once
#include "BaseObject.h"
#include "MapObject.h"
#include "DrawObject.h"
enum DIRE {
	UP, DOWN, RIGHT, LEFT,
};
class CTankObject
	:virtual public CBaseObject
{
public:
	CTankObject();
	~CTankObject();
	bool DrawObject();//��̹��
	bool ClsObject();//��̹��
public:
	//�������ͻ�ȡ̹�˳����أ����ض�Ӧ��̹�ˣ�����������
	CTankObject getTankBirthPlace(int nType);
	bool MoveTank(char nDir);//�ƶ�̹��
	bool TankCollision(CTankObject TankObject, char nDir);//��ײ�ж�
	bool TankCollisionTurn(CTankObject& TankObject, char nDir);//ת����ײ�ж�
	void setMapObj(CMapObject* pMapObject);//���õ�ͼ�Ķ���ÿ��̹�˶����е�ͼ�ĵ�ַ
	CMapObject* getMapObj();
	int initp(DIRE dir,CTankObject& temp);
	COORD getbody(int i);
	int getm_nType();

//
//	/////////////////////
//	//��һ�麯�����ڷ���̹�����ԣ��ڴ����ӵ����õ�
	bool getTankIsDie();
	int getAlignment();
	int getTankPosX();
	int getTankPosY();
	int getTankDir();
	int getTankType();
	int getTankBlood();
	int putTankBlood(int x);
	int getTankScores();
private:
	bool m_IsDie;//̹���Ƿ�����
	int m_Alignment;//������Ӫ
	int m_nPosX;  //̹��X������
	int m_nPosY; //̹��Y����
	int m_nDir;  //̹�˵�ǰ����
	int m_nType;  //̹������
	int m_nBlood;  //̹��Ѫ��
	int m_nScore;  //̹��ɱ�з���
	CMapObject* m_pMapObject;  //��ͼ����ָ��
	COORD body[6] = {};
	
};

