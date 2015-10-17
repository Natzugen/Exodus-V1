#include "stdafx.h"
#include "ItemSet.h"
#include "ScriptEncode.h"
// -------------------------------------------------------------------------------

ItemSet g_ItemSet;
// -------------------------------------------------------------------------------

ItemSet::ItemSet()
{
	this->m_Data.clear();
}
// -------------------------------------------------------------------------------

ItemSet::~ItemSet()
{

}
// ---------------------------------------------------------------------------
void ItemSet::Load()
{
	this->m_Data.clear();
	this->Read("Data\\Custom\\ItemRank.z");
}
void ItemSet::Read(char * File)
{
	int Token;
	// ----
	if( !g_ScriptEncode.ReadScript(File) )
	{
		MessageBox(NULL, "file not found", "[ItemSet]", ERROR);
		return;
	}
}


// ---------------------------------------------------------------------------