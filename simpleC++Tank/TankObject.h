#pragma once
#include "BaseObject.h"
#include "MapObject.h"
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
	bool MoveTank(int nDir);//�ƶ�̹��
	bool TankCollision(CTankObject TankObject);//��ײ�ж�
	void setMapObj(CMapObject* pMapObject);//���õ�ͼ�Ķ���ÿ��̹�˶����е�ͼ�ĵ�ַ
	CMapObject* getMapObj();

	/////////////////////
	//��һ�麯�����ڷ���̹�����ԣ��ڴ����ӵ����õ�
	bool getTankIsDie();
	int getAlignment();
	int getTankTankPosX();
	int getTankTankPosY();
	int getTankDir();
	int getTankType();
	int getTankBlood();
	int getTankScores();
private:
	bool m_IsDie;//̹���Ƿ�����
	int m_Alignment;//������Ӫ
	int m_nPox;  //̹��X������
	int m_nPosY; //̹��Y����
	int m_nDir;  //̹�˵�ǰ����
	int m_nType;  //̹������
	int m_nBlood;  //̹��Ѫ��
	int m_nScore;  //̹��ɱ�з���
	CMapObject* m_pMapObject;  //��ͼ����ָ��
	int m_TankShape[4][3][3] = {};
};

