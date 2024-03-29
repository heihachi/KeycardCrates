class ActionCrateOpenClose: ActionInteractBase
{
    string m_ActionText = "#open";
	void ActionCrateOpenClose()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

    override string GetText()
	{
		return m_ActionText;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		string selection = target.GetObject().GetActionComponentName(target.GetComponentIndex());

		Container_Base crate = Container_Base.Cast(target.GetObject());

		if (crate.IsLocked())
			return false;

        if(crate.IsOpen())
		{
			m_ActionText = "#close";
			return true;
		}
		else
		{
			m_ActionText = "#open";
			return true;
		}

		return false;
	}
};