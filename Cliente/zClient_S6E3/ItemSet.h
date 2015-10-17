#pragma once
// -------------------------------------------------------------------------------

#define ITEMSET_MAX_OPTION		6
// -------------------------------------------------------------------------------

#include <vector>

struct ItemSet_List
{
	BYTE	SetID;
	WORD	ItemType;
};

struct ItemSet_Data
{
	BYTE	SetID;
	short	OptionValue[ITEMSET_MAX_OPTION];
	std::vector<ItemSet_List> ItemList;
	// ----
	ItemSet_Data()
	{
		ZeroMemory(this, sizeof(*this));
	}
};

class ItemSet
{
public:
	ItemSet();
	~ItemSet();
	// ----
	void	Load();
	void	Read(char * File);
	// ----

	//-----
private:
	std::vector<ItemSet_Data> m_Data;
	// ----
}; extern ItemSet g_ItemSet;