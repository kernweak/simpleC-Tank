#pragma once
#include "BaseObject.h"
#include "TankObject.h"

class CBulletObject :
	virtual public CBaseObject
{
public:
	CBulletObject();
	~CBulletObject();
public:
	bool DrawObject();//���ӵ�
	bool DrawObject(int nPosX, int nPosY, int nType);
	bool ClsObject();
	//bool ClsObject(int nPosX, int nPosY);
	////�����ӵ������뱣��̹�˵���������Ҫ�����ӵ���̹�˵���ײ��
	CBulletObject CreateBullet(CTankObject TankObject,vector<CTankObject>& vecTankObject);  //�����ӵ���̹��
	//�ƶ��ӵ�
	bool MoveBullet(vector<CTankObject>& vecTankObject);
	//�ӵ���ײ���
	bool BulletCollision(CBulletObject& BulletObject,//�ӵ�����
		vector<CTankObject>& vecTankObject);
	COORD getNextCoord(CBulletObject BulletObject);
private:
	
	//����=������������ӵ��ǣ�̹�˶�����ӵ�����ֵ��
public:
	bool operator=(CTankObject TankObject);
	//����==��������ӵ���̹�˵���ײ���ӵ�������̹�˶���������ıȽϣ�
	bool operator==(CTankObject TankObject);
	//��ȡ�ӵ�������
	bool getBulletIsDie();
	int getBulletPosX();
	int getBulletPosY();
	int getBulletDir();
	int getBulletType();
	int getBulletATK();
	CMapObject*  getMapObj();
private:
	bool m_nIsDie; //�ӵ��Ƿ����
	int m_Alignement;//������Ӫ
	int m_nPosX;//�ӵ�x����
	int m_nPosY;//�ӵ�Y����
	int m_nDir;//�ӵ�����
	int m_nType;//�ӵ�����
	int m_nATK;//�ӵ�������
	CMapObject* m_pMapObject;//��ͼ����
};

	