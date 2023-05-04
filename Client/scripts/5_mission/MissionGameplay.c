modded class MissionGameplay 
{	
	void MissionGameplay() 
	{
		GetRPCManager().SendRPC( "KeycardCrates", "SLCServerActions");
	}
};