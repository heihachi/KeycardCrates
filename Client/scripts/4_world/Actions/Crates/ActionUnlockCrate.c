class ActionUnlockCrateCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
    {
        SpawnableCase_Base crate = SpawnableCase_Base.Cast(m_ActionData.m_Target.GetObject());

        if (crate)
            m_ActionData.m_ActionComponent = new CAContinuousTime(crate.GetUnlockTime());
        else
            m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.LOCK);
    }
}

class ActionUnlockCrate : ActionContinuousBase
{
    void ActionUnlockCrate()
    {
        m_CallbackClass = ActionUnlockCrateCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_HIGH;
    }

    override void CreateConditionComponents()
    {
       	m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
    }

    override string GetText()
    {
        return "#unlock";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if(!target)
			return false;
		if (!target.GetObject())
			return false;
		SpawnableCase_Base crate = SpawnableCase_Base.Cast(target.GetObject());

        if(crate)
		{
            // lets make sure its ready
            //crate.ConvertKeyItem();
            if (Math.AbsInt(item.GetType().Hash()) != crate.GetKeyItem())
                return false;
            if (crate.IsLocked())
                return true;
		}					
        return false;
    }
}