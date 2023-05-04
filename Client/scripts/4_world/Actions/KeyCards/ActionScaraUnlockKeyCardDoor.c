class ActionScaraUnlockKeyCardDoor: ActionContinuousBase
{
	string m_custom = "#unlock";
	BuildingBase building;
	int doorIndex;

	void ActionScaraUnlockKeyCardDoor()
	{		
		m_CallbackClass = ActionUnlockDoorsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = m_custom;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{		
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;
				
		if ( CastTo(building, target.GetObject()) )
		{
			doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			
			if ( doorIndex != -1 )
			{
				if (building.IsDoorLocked(doorIndex) && building.IsKeyCardDoor())
				{
					return true;
				}
			}
		}	
			
		return false;
	}
};
