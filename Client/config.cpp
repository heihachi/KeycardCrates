class CfgPatches
{
	class KeycardCratesClient
	{
		units[] = {"MilitaryCrate","WeaponCrate","BuildingCrate","DrugCrate","MedicalCrate","ConsumableCrate","MiningCrate","Hidden_Stash","Computer_Tower","Duffle_Bag","Medical_Bag","Safe","Toolbox"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","JM_CF_Scripts"};
	};
};
class CfgMods
{
	class KeycardCratesClient
	{
		dir = "KeycardCratesClient";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "KeycardCratesClient";
		credits = "Scarabyte";
		author = "Scarabyte";
		authorID = "0";
		version = "1.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"KeycardCrates/Client/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"KeycardCrates/Client/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"KeycardCrates/Client/scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class WoodenCrate;
	class PlasticBarrelStash;
	class Barrel_Green;
	class SpawnableCase_Base: WoodenCrate
	{
		scope = 0;
		itemSize[] = {10,4};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000000000;
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,15};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		hiddenSelections[] = {"zbytek"};
	};
	class SpawnableCase_Openable_Base: Barrel_Green
	{
		scope = 0;
		itemSize[] = {10,4};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000000000;
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,15};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		hiddenSelections[] = {"zbytek"};
	};
	class MilitaryCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Military Crate";
		descriptionShort = "High Tier Helmets and Armor";
	};
	
	class WeaponCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Weapons Crate";
		descriptionShort = "High Tier Weapons";
	};
	
	class BuildingCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Building Crate";
		descriptionShort = "High Tier Building Items";
	};
	
	class DrugCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Drug Crate";
		descriptionShort = "Drug Stash";
	};
	
	class MedicalCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Medical Crate";
		descriptionShort = "High Tier Medical Items";
	};
	
	class ConsumableCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Consumable Crate";
		descriptionShort = "High Tier Barter Items";
	};
	
	class MiningCrate : SpawnableCase_Base
	{
		scope=2;
		displayName = "Mining Crate";
		descriptionShort = "Mining Stash";
	};
	class OilBarrel : SpawnableCase_Openable_Base
	{
		scope=2;
		displayName = "Oil Barrel";
		descriptionShort = "Can be used to store things.";
	};

	class Paper;
	class Scarabyte_KeyCard: Paper
	{

	};
	class ExampleKeyCard: Scarabyte_KeyCard {};
};
