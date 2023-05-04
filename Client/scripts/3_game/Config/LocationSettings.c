class SpawnableLocation
{
	int Randomize;
	bool IsLootActive;
	ref array<ref SpawnableCrateLocation> CrateData;
    
    void SpawnableLocation(bool islootactive, int ncpt)
	{
		IsLootActive = islootactive;
		Randomize = ncpt;
		CrateData = new array<ref SpawnableCrateLocation>;
    }
	
	void AddCratePosition(string lName, string name, string ContainerName, vector pos, vector ori, bool floating, int timer, bool active)
	{
		CrateData.Insert(new SpawnableCrateLocation(lName, name, ContainerName, pos, ori, floating, timer, active));
	}
}

class SpawnableCrateLocation
{
    string LocationName;
    string LootTable;
    string ContainerName;
    vector POS, ORI;
    bool ExactPlacing;
    bool ContainerToggleable;
    int ResetTimer = 120;
    bool ResetPlayerCheck = true;
	bool IsActive = true;
    int ActionID;
    string KeyItem;
    int UnlockTime;
    
    void SpawnableCrateLocation(string lName, string name, string cname, vector pos, vector ori, bool floating, int _timer, bool _playerCheck=true, bool _active=true, bool _toggle=false, int _actionId=-1, string _keyitem="", int _unlockTime=300)
	{
        LocationName = lName;
        LootTable = name;
        ContainerName = cname;
        POS = pos;
        ORI = ori;
        ExactPlacing = floating;
        ContainerToggleable = _toggle;
        ResetTimer = _timer;
        ResetPlayerCheck = _playerCheck;
        IsActive = _active;
        ActionID = _actionId;
        KeyItem = _keyitem;
        UnlockTime = _unlockTime;
    }
}