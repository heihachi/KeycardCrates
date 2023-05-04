modded class BuildingBase extends EntityAI
{
    private int m_configKey;
    private bool m_isKeyCard; // sync on player side?
    private bool m_use_alarm;
    private bool m_should_relock;
    private int m_relock_time;
    private int m_buildingId;
    private bool m_using_actions;

    void BuildingBase()
    {
        RegisterNetSyncVariableInt("m_configKey");
        RegisterNetSyncVariableInt("m_relock_time");
        RegisterNetSyncVariableBool("m_isKeyCard");
        RegisterNetSyncVariableBool("m_use_alarm");
        RegisterNetSyncVariableBool("m_should_relock");
        RegisterNetSyncVariableInt("m_buildingId");
        RegisterNetSyncVariableBool("m_using_actions");
    }

    bool IsUsingActions(int door)
    {
        return m_using_actions;
    }

    bool IsKeyCardDoor()
    {
        return m_isKeyCard;
    }

    int GetAction(int door)
    {
        // TODO: This needs more work
        //return m_buildingId+door;
        return m_buildingId;
    }

    bool UseAlarm()
    {
        return m_use_alarm;
    }

    int GetConfigKey()
    {
        return m_configKey;
    }

    int GetLockTime()
    {
        return m_relock_time*1000;
    }

    void UnlockKeyCard(int index)
    {
        UnlockDoor(index);
    }
}