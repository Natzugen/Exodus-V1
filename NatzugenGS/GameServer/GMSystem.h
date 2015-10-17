#include "StdAfx.h"
#include "user.h"

class cGMSystem
{
public:

	cGMSystem();
	virtual ~cGMSystem();

	void Load(LPBYTE lpdata, int aIndex);

};
extern cGMSystem g_GMSystem;