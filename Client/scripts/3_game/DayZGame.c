modded class DayZGame // TODO: Add Keycard config
{
    protected ref CrateSettings m_SLCConfig;
    
    void DayZGame()
	{
        GetRPCManager().AddRPC( "KeycardCrates", "SLCClientActions", this, SingleplayerExecutionType.Both );
        GetRPCManager().AddRPC( "KeycardCrates", "SLCServerActions", this, SingleplayerExecutionType.Both );
    }

    void SLCClientActions( CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target )
	{	
        Param1<CrateSettings> dataConfig;
        if(!ctx.Read(dataConfig))
            return;
        SetSpawnableCrateConfig(dataConfig.param1);
	}

    void SLCServerActions( CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target )
	{
		auto configParams = new Param1<CrateSettings>(GetSpawnableCrateConfig());
        GetRPCManager().SendRPC( "KeycardCrates", "SLCClientActions", configParams );
	}

    CrateSettings GetSpawnableCrateConfig()
    {
        if (!m_SLCConfig && !GetGame().IsClient())
        {
            m_SLCConfig = new CrateSettings();
            m_SLCConfig.Load();
        }
        else if(!m_SLCConfig && GetGame().IsClient())
        {
            return null;
        }
        return m_SLCConfig;
    }

    void SetSpawnableCrateConfig(CrateSettings config)
    {
        if (GetGame().IsClient())
            ClientSetSpawnableCrateConfig(config);
        else
            ServerSetSpawnableCrateConfig(config);
    }

    void ServerSetSpawnableCrateConfig(CrateSettings config)
    {
        if(GetGame().IsClient())
        {
            Error("ERROR: ServerSetSpawnableCrateConfig can only be called on server");
            return;
        }
        m_SLCConfig = config;
    }

    void ClientSetSpawnableCrateConfig(CrateSettings config)
    {
        if(!GetGame().IsClient())
        {
            Error("ERROR: ClientSetSpawnableCrateConfig can only be called on client");
            return;
        }

        m_SLCConfig = config;
    }
};