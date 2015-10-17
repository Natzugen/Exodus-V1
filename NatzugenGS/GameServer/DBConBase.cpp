// DBConBase.cpp: implementation of the CDBConBase class.
// Custom Systems Database Implementation
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DBConBase.h"
#include "logproc.h"
#include "DBManager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DBManager gsDB;

CDBConBase::CDBConBase()
{

}

CDBConBase::~CDBConBase()
{

}

BOOL CDBConBase::Connect(char* szConID, char* szConPass)
{
	if (m_DBQuery.Connect(3, gsDB.ConnectDNS, szConID, szConPass) == FALSE)
	{
		LogAdd("%s DB Connect Fail", gsDB.ConnectDNS);
		return FALSE;
	}

	return TRUE;
}