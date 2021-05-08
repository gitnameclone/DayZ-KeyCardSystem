class CfgPatches
{
	class Security_Doors_Mod
	{
		units[]=
		{
			"SDM_Keycard"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class Security_Doors_Mod
	{
		dir="Security_Doors_Mod";
		picture="";
		action="";
		hideName=0;
		hidePicture=1;
		name="Security_Doors_Mod";
		author="C4r1zP";
		credits="";
		authorID="0";
		version="1.0";
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"Security_Doors_Mod/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Security_Doors_Mod/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"Security_Doors_Mod/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class SDM_Keycard_Base: Inventory_Base
	{
		scope=0;
		displayName="Security Keycard Base";
		descriptionShort="Allows access to restricted areas";
		model="Security_Doors_Mod\p3d\Keycard\SDM_Keycard.p3d";
		animClass="Knife";
		rotationFlags=0;
		isMeleeWeapon=1;
		itemSize[]={1,1};
		weight=150;
		fragility=0.0099999998;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Keycard\Keycard_Lvl_1.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\Loot_CanOpener.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\Loot_CanOpener.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\Loot_CanOpener_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\Loot_CanOpener_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\Loot_CanOpener_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class SDM_Keycard_Lvl_1: SDM_Keycard_Base
	{
		scope=2;
		displayName="Security Keycard Lvl 1";
		descriptionShort="Security Keycard Lvl 1";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Keycard\Keycard_Lvl_1.paa"
		};
	};
	class SDM_Keycard_Lvl_2: SDM_Keycard_Base
	{
		scope=2;
		displayName="Security Keycard Lvl 2";
		descriptionShort="Security Keycard Lvl 2";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Keycard\Keycard_Lvl_2.paa"
		};
	};
	class SDM_Keycard_Lvl_3: SDM_Keycard_Base
	{
		scope=2;
		displayName="Security Keycard Lvl 3";
		descriptionShort="Security Keycard Lvl 3";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Keycard\Keycard_Lvl_3.paa"
		};
	};
	class SDM_Keycard_Lvl_4: SDM_Keycard_Base
	{
		scope=2;
		displayName="Security Keycard Lvl 4";
		descriptionShort="Security Keycard Lvl 4";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Keycard\Keycard_Lvl_4.paa"
		};
	};
	
	class HouseNoDestruct;
	class SDM_Security_Single_Door_Base: HouseNoDestruct
	{
		scope=0;
		displayName="Security Single Door";
		descriptionShort="Security Single Door";
		model="Security_Doors_Mod\p3d\Single_Security_Door\SDM_Single_Security_Door.p3d";
		class Doors
		{
			class Doors1
			{
				displayName="door 1";
				component="Doors1";
				soundPos="doors1_action";
				animPeriod=2.7;
				initPhase=0;
				initOpened=0;
				armor=1;
				soundOpen="SDM_Security_Move";
				soundClose="SDM_Security_Move";
				soundLocked="doorWoodRattle";
			};
		};
	};
	class SDM_Security_Single_Door_Lvl_1: SDM_Security_Single_Door_Base
	{
		scope=2;
		displayName="Security Single Door Lvl 1";
		descriptionShort="Security Single Door Lvl 1";
		hiddenSelections[]=
		{
			"zbytek",
			"Scanner",
			"Level_Sign",
			"Caution_Sign"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Single_Security_Door\MetalDoor_Base.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_01.paa",
			"Security_Doors_Mod\paa\Signs\Restriced_Area_Sign.paa",
			"Security_Doors_Mod\paa\Signs\Caution_Sign.paa"
		};
	};
	class SDM_Security_Single_Door_Lvl_2: SDM_Security_Single_Door_Base
	{
		scope=2;
		displayName="Security Single Door Lvl 2";
		descriptionShort="Security Single Door Lvl 2";
		hiddenSelections[]=
		{
			"zbytek",
			"Scanner",
			"Level_Sign",
			"Caution_Sign"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Single_Security_Door\MetalDoor_Base.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_02.paa",
			"Security_Doors_Mod\paa\Signs\Restriced_Area_Sign.paa",
			"Security_Doors_Mod\paa\Signs\Caution_Sign.paa"
		};
	};
	class SDM_Security_Single_Door_Lvl_3: SDM_Security_Single_Door_Base
	{
		scope=2;
		displayName="Security Single Door Lvl 3";
		descriptionShort="Security Single Door Lvl 3";
		hiddenSelections[]=
		{
			"zbytek",
			"Scanner",
			"Level_Sign",
			"Caution_Sign"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Single_Security_Door\MetalDoor_Base.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_03.paa",
			"Security_Doors_Mod\paa\Signs\Restriced_Area_Sign.paa",
			"Security_Doors_Mod\paa\Signs\Caution_Sign.paa"
		};
	};
	class SDM_Security_Single_Door_Lvl_4: SDM_Security_Single_Door_Base
	{
		scope=2;
		displayName="Security Single Door Lvl 4";
		descriptionShort="Security Single Door Lvl 4";
		hiddenSelections[]=
		{
			"zbytek",
			"Scanner",
			"Level_Sign",
			"Caution_Sign"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Single_Security_Door\MetalDoor_Base.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_04.paa",
			"Security_Doors_Mod\paa\Signs\Restriced_Area_Sign.paa",
			"Security_Doors_Mod\paa\Signs\Caution_Sign.paa"
		};
	};


	class SDM_Security_Double_Door_Base: HouseNoDestruct
	{
		scope=0;
		model="Security_Doors_Mod\p3d\Double_Security_Door\SDM_Double_Security_Door.p3d";
		class Doors
		{
			class DoorsTwin1
            {
                displayName = "Twin Doors 1";
                component = "doorsTwin1";
                soundPos = "doorsTwin1_action";
				animPeriod=2.7;
				initPhase=0;
				initOpened=0;
				armor=1;
				soundOpen="SDM_Security_Move";
				soundClose="SDM_Security_Move";
				soundLocked="doorWoodRattle";
				soundOpenABit = "doorMetalTwinBigOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
			class DamageZones
			{
				class DoorsTwin1
				{
					class Health
					{
						hitpoints=2000;
						transferToGlobalCoef=0;
					};
					componentNames[]=
					{
						"doorsTwin1"
					};
					fatalInjuryCoef=-1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class Melee
						{
							class Health
							{
								damage=2.5;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
				};
			};
		};
	};
	class SDM_Security_Double_Door_Lvl_1: SDM_Security_Double_Door_Base
	{
		scope=2;
		displayName="Security Double Door Lvl 1";
		descriptionShort="Security Double Door Lvl 1";
		hiddenSelections[]=
		{
			"door1",
			"door1_glass",
			"door2",
			"door2_glass",
			"frame",
			"scanner"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_frame_BaseColor.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_01.paa"
		};
	};
	class SDM_Security_Double_Door_Lvl_2: SDM_Security_Double_Door_Base
	{
		scope=2;
		displayName="Security Double Door Lvl 2";
		descriptionShort="Security Double Door Lvl 2";
		hiddenSelections[]=
		{
			"door1",
			"door1_glass",
			"door2",
			"door2_glass",
			"frame",
			"scanner"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_frame_BaseColor.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_02.paa"
		};
	};
	class SDM_Security_Double_Door_Lvl_3: SDM_Security_Double_Door_Base
	{
		scope=2;
		displayName="Security Double Door Lvl 3";
		descriptionShort="Security Double Door Lvl 3";
		hiddenSelections[]=
		{
			"door1",
			"door1_glass",
			"door2",
			"door2_glass",
			"frame",
			"scanner"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_frame_BaseColor.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_03.paa"
		};
	};
	class SDM_Security_Double_Door_Lvl_4: SDM_Security_Double_Door_Base
	{
		scope=2;
		displayName="Security Double Door Lvl 4";
		descriptionShort="Security Double Door Lvl 4";
		hiddenSelections[]=
		{
			"door1",
			"door1_glass",
			"door2",
			"door2_glass",
			"frame",
			"scanner"
		};
		hiddenSelectionsTextures[]=
		{
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_BaseColor.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\glass_Metallic.paa",
			"Security_Doors_Mod\paa\Double_Security_Door\doubledoor_frame_BaseColor.paa",
			"Security_Doors_Mod\paa\Scanner\Scanner_Lvl_04.paa"
		};
	};
};
class CfgActionSounds
{
	class SDM_Security_Move
	{
		sounds[]=
		{
			"SDM_Security_Move_Sound"
		};
	};
};
class CfgSounds
{
	class default;
	class SDM_Security_Move_Sound
	{
		sound[]=
		{
			"Security_Doors_Mod\sounds\???",  //Has yet to be determined
			4,
			1,
			40
		};
	};
};
