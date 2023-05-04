class KeyCardSettings: Managed
{
	bool debug_build;
    bool admin_log;

    autoptr array< autoptr KeyCardLocations > KeyCard_Locations;

	protected static ref KeyCardSettings  _singleton;
	protected bool loaded = false;

	static KeyCardSettings GetInstance()
    {
        if (!_singleton)
            _singleton = new KeyCardSettings();
        return _singleton;
    }

    void CreateConfig()
    {
	    if (!GetGame().IsServer()) return;

		if (!FileExist(SLC_CONFIG_DIR_SERVER))
        {
           CF_Directory.CreateDirectory(SLC_CONFIG_DIR_SERVER);
        }

        if (!FileExist(KEY_CONFIG))
        {
            Default();
        }
        LoadConfig();
    }

    bool LoadConfig()
    {
        if (FileExist(KEY_CONFIG))
        {
            JsonFileLoader<KeyCardSettings>.JsonLoadFile(KEY_CONFIG, this);
            return true;
        }
        return false;
    }

	void Load()
    {
		if (!loaded)
		{
			CreateConfig();
			loaded = LoadConfig();
			//GetDayZGame().SetSpawnableCrateConfig(this);
		}
    }

	void Save()
    {
        JsonFileLoader<KeyCardSettings>.JsonSaveFile(KEY_CONFIG, this);
    }
	
    void KeyCardSettings()
    {
        debug_build = false;
        admin_log = false;

        KeyCard_Locations = new array< autoptr KeyCardLocations >;
    }

    void Default()
    {	
        if (GetGame().IsServer() && !GetGame().IsClient())
        {					
            KeyCardLocations k = new KeyCardLocations(3686.741455078125, 5986.13330078125, 403.88037109375, 3686.741455078125, 5986.13330078125, 403.88037109375, 1, "Green Mountain", "Land_Mil_Barracks5", "keycard_access", true, true, 1.0, "Alarm_Military", false, 30);
            KeyCard_Locations.Insert(k);

            Print("Keycard loaded " + KeyCard_Locations.Count() + " Locations");

            Save();
        }
    }
}


class CrateSettings: Managed
{
    ref array<ref SpawnableLocation> Locations;
	ref array<ref ListLootConfig> LootTables;

	protected static ref CrateSettings  _singleton;
	protected bool loaded = false;
    
    static CrateSettings GetInstance()
    {
        if (!_singleton)
            _singleton = new CrateSettings();
        return _singleton;
    }

    void CreateConfig()
    {
	    if (!GetGame().IsServer()) return;

		if (!FileExist(SLC_CONFIG_DIR_SERVER))
        {
           CF_Directory.CreateDirectory(SLC_CONFIG_DIR_SERVER);
        }

        if (!FileExist(SLC_CONFIG))
        {
            Default();
        }
        LoadConfig();
    }

    bool LoadConfig()
    {
        if (FileExist(SLC_CONFIG))
        {
            JsonFileLoader<CrateSettings>.JsonLoadFile(SLC_CONFIG, this);
            return true;
        }
        return false;
    }

	void Load()
    {
		if (!loaded)
		{
			CreateConfig();
			loaded = LoadConfig();
			GetDayZGame().SetSpawnableCrateConfig(this);
		}
    }

	protected void Save()
    {
        JsonFileLoader<CrateSettings>.JsonSaveFile(SLC_CONFIG, this);
    }

	protected void Default()
    {
		Locations = new array<ref SpawnableLocation>;
        Locations.Insert(new SpawnableLocation(1,0));
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","WeaponCrate",Vector(1386.162231, 464.568634, 14422.077148),Vector(115.000000, 0.000000, -0.000000), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","MilitaryCrate",Vector(1694.400024, 448.402832, 14210.000000),Vector(-108.000000, 0.000000, -0.000000), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","WeaponCrate",Vector(1390.250244, 464.568634, 14428.591797),Vector(115.000000, 0.000000, -0.000000), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","MilitaryCrate",Vector(1705.524048, 456.484650, 14167.800781),Vector(-110.000000, 0.000000, 0.000000), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","WeaponCrate",Vector(1534.478516, 452.700958, 14176.821289),Vector(111.492668, 0.000000, 0.000000), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","MilitaryCrate",Vector(1678.462402, 445.741333, 13823.817383),Vector(34.000000, 0.000000, 0.000000), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","WeaponCrate",Vector(1896.774902, 448.957642, 13707.833008),Vector(-134.000000, -0.083319, -0.042664), false, 120, true);
		Locations.Get(0).AddCratePosition("Human Readable Label (Not used in code)", "Army1","MilitaryCrate",Vector(1991.667847, 450.258240, 13825.063477),Vector(-179.999985, -0.083759, 0.079992), false, 120, true);
		
		LootTables = new array<ref ListLootConfig>;
		LootTables.Insert(new ListLootConfig("Army1"));
		LootTables.Get(0).MaxLoot = 8;
		LootTables.Get(0).MinSpawn = 1;
		LootTables.Get(0).AddLootConfig("AKM",0.6);
		LootAttachmentConfig temp = new LootAttachmentConfig("magazines", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("Mag_AKM_30Rnd",0.5);
		temp.AddAttachments("Mag_AKM_30Rnd",0.5);
		temp.AddAttachments("Mag_AKM_Drum75Rnd",0.2);
		LootTables.Get(0).LootTable.Get(0).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("weaponOptics", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("PSO1Optic",0.5);
		LootTables.Get(0).LootTable.Get(0).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("weaponMuzzle", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("AK_Suppressor",0.3);
		temp.AddAttachments("AK_Bayonet",0.4);
		LootTables.Get(0).LootTable.Get(0).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("WeaponHandguard", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("AK_PlasticHndgrd",0.85);
		temp.AddAttachments("AK_RailHndgrd_Black",0.85);
		LootTables.Get(0).LootTable.Get(0).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("weaponButtstock", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("AK_FoldingBttstck_Black",0.6);
		LootTables.Get(0).LootTable.Get(0).AddAttachmentsToSlot(temp);

		LootTables.Get(0).AddLootConfig("M4A1",0.6);
		temp = new LootAttachmentConfig("magazines", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("Mag_STANAG_30Rnd",0.5);
		temp.AddAttachments("Mag_STANAGCoupled_30Rnd",0.3);
		LootTables.Get(0).LootTable.Get(1).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("weaponOptics", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("ACOGOptic",0.4);
		temp.AddAttachments("M4_CarryHandleOptic",0.6);
		LootTables.Get(0).LootTable.Get(1).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("weaponMuzzle", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("M4_Suppressor",0.4);
		LootTables.Get(0).LootTable.Get(1).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("WeaponHandguard", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("M4_MPHndgrd",0.7);
		temp.AddAttachments("M4_RISHndgrd",0.5);
		LootTables.Get(0).LootTable.Get(1).AddAttachmentsToSlot(temp);
		temp = new LootAttachmentConfig("weaponButtstock", false, 1);
		temp.AddAttachments("Nothing",0.8);
		temp.AddAttachments("M4_CQBBttstck",0.7);
		temp.AddAttachments("M4_MPBttstck",0.4);
		LootTables.Get(0).LootTable.Get(1).AddAttachmentsToSlot(temp);

		LootTables.Get(0).AddLootConfig("AmmoBox_545x39_20Rnd",0.8);
		LootTables.Get(0).AddLootConfig("AmmoBox_556x45_20Rnd",0.8);
		LootTables.Get(0).AddLootConfig("AmmoBox_762x39_20Rnd",0.8);
		LootTables.Get(0).AddLootConfig("AmmoBox_762x54_20Rnd",0.8);
		Save();
	}
};