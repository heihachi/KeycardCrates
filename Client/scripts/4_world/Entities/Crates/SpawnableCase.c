class SpawnableCase_Base extends Container_Base
{
	private bool m_IsLocked = false;
	protected bool m_looted;
	protected bool m_ready;
	protected int m_keyItem;
	protected int m_keytime;
	private bool m_IsOpenable;


	void SpawnableCase_Base()
	{
		m_looted = false;
		m_ready = false;
		RegisterNetSyncVariableBool("m_IsLocked");
		RegisterNetSyncVariableBool("m_looted");
		RegisterNetSyncVariableBool("m_ready");
		RegisterNetSyncVariableInt("m_keyItem");
		RegisterNetSyncVariableInt("m_keytime");
	}

	override void EECargoOut(EntityAI item)
	{
		super.EECargoOut(item);

		if (GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).GetRemainingTime(ResetCrate))
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(ResetCrate);

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetCrate, 2*60*1000);
	}

	override bool NameOverride(out string output)
	{
		if ( IsLocked() )
		{
			GetGame().ObjectGetDisplayName(this, output);
			output = string.Format("Locked %1", output);  
			return true;
		}
		return false;
	}

	override bool CanDisplayCargo() { return !IsLocked(); }

	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}

	override void SetActions()
    {
        super.SetActions();
        
		
		//AddAction(ActionUnlockCrate);
    }

	/*
	 * Custom Functions
	 */

	void ResetCrate() // this is so we know they are still looting
	{
		SetLooted(true);
		SetReady(false);
	}

	void PrepCrate() // this is getting the crate ready for spawning loot
	{
		if (GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).GetRemainingTime(ResetCrate))
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(ResetCrate);

		// no players should be near when this is called
		SetLooted(false);
		SetReady(true);
	}

	void SetKeyItem(string value, int time)
	{
		m_keyItem = Math.AbsInt(value.Hash());
		m_keytime = time;
		SetSynchDirty();
	}

	int GetKeyItem()
	{
		return m_keyItem;
	}

	int GetUnlockTime()
	{
		return m_keytime;
	}

	void SetReady(bool value)
	{
		m_ready = value;
		SetSynchDirty();
	}

	void SetLooted(bool value)
	{
		m_looted = value;
		SetSynchDirty();
	}

	void RefreshLoot()
	{
		GetGame().ObjectDelete(this);
	}

	bool Looted() 
	{
		return m_looted;
	}

	bool IsReady() 
	{
		return m_ready;
	}

	void Unlock()
	{
		m_IsLocked = false;
		SetSynchDirty();
	}

	void Lock()
	{
		m_IsLocked = true;
		SetSynchDirty();
	}
	
	bool IsLocked()
	{
		return m_IsLocked;
	}

	void SetOpenable(bool value)
	{
		m_IsOpenable = value;
		SetSynchDirty();
	}

	bool IsOpenable() return m_IsOpenable;
}

class SpawnableCase_Openable_Base extends SpawnableCase_Base
{
	protected bool m_IsOpened;
	protected bool m_IsOpenedLocal;
	
	void SpawnableCase_Openable_Base()
	{
		SetOpenable(true);
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsOpened");
	}

	override void EEInit()
	{
		super.EEInit();		
        if(IsOpen())
            GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		else
			GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);		
	}

	override void Open()
	{
		m_IsOpened = true;
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override void Close()
	{
		m_IsOpened = false;
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override bool IsOpen()
	{
		return m_IsOpened;
	}

	void UpdateVisualState()
	{
		if ( IsOpen() )
		{
			SetAnimationPhase("Lid",1);
			SetAnimationPhase("Lid2",0);
		}
		else
		{
			SetAnimationPhase("Lid",0);
			SetAnimationPhase("Lid2",1);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( m_IsOpened != m_IsOpenedLocal )
		{		
			if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				SoundOpenPlay();
			}
			
			if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				SoundClosePlay();
			}	
			m_IsOpenedLocal = m_IsOpened;
		}
		
		UpdateVisualState();
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );		
		ctx.Write( m_IsOpened );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		if (!ctx.Read( m_IsOpened ) )
			return false;
		
		if ( m_IsOpened )
			Open();
		else
			Close();
		
		return true;
	}

	void SoundOpenPlay()
	{
	}
	
	void SoundClosePlay()
	{
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCrateOpenClose);
	}
}