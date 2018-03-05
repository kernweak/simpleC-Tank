#pragma once
#include <vector>
using namespace std;

class CBaseObject
{
public:
	CBaseObject();
	virtual ~CBaseObject();
public:
	virtual bool DrawObject() = 0;
	virtual bool ClsObject() = 0;
};

