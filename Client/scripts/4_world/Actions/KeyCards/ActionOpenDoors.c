modded class ActionOpenDoors: ActionInteractBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) 
			return false;
		//if ( IsDamageDestroyed(action_data.m_Target) ) return false;
		if ( !IsBuilding(target) ) 
			return false;

		Building building;
		if ( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) 
					return false;
				return ( !building.IsDoorOpen(doorIndex) && !building.IsDoorLocked(doorIndex) );
			}
		}
		return false;
	}
};