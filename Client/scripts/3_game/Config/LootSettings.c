class ListLootConfig
{
	string TableName;
	int MaxLoot = 10;
	int MinSpawn = 10;
	ref array<ref LootConfig> LootTable;
	
	void ListLootConfig(string name)
	{
		LootTable = new array<ref LootConfig>;
		TableName = name;
	}
	
	void AddLootConfig(string lootname, float probtospawn)
	{
		LootTable.Insert(new LootConfig(lootname,probtospawn));
	}
}

class LootConfig
{
	string ItemName;
	float  SpawnProb;
	ref array<ref LootAttachmentConfig> ItemAttachments;
	
	void LootConfig(string lootname, float probtospawn)
	{
		ItemName = lootname;
		SpawnProb = probtospawn;
		ItemAttachments = new array<ref LootAttachmentConfig>;
	}
	
	void AddAttachmentsToSlot(LootAttachmentConfig slot)
	{
		ItemAttachments.Insert(slot);
	}
}

class LootAttachmentConfig
{
	string slot;
	bool counted;
	int spawnamount;
	ref array<ref AttachmentConfig> items;

	void  LootAttachmentConfig(string _slot, bool _counted, int _amounts)
	{
		slot = _slot;
		counted = _counted;
		spawnamount = _amounts;
		items = new array<ref AttachmentConfig>;
	}

	void AddAttachments(string name, float prob)
	{
		items.Insert(new AttachmentConfig(name,prob));
	}
}

class AttachmentConfig
{
	string AttachName;
	float  AttachProb;
	
	void  AttachmentConfig(string attachname, float probattachtospawn)
	{
		AttachName = attachname;
		AttachProb = probattachtospawn;
	}
}