class Scarabyte_KeyCard: Inventory_Base 
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionScaraUnlockKeyCardDoor);
	}
};