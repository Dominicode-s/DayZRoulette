class CfgPatches
{
	class FirstModPacked
	{
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};

class CfgMods
{
	class FirstModPacked
	{
		name = "FirstModPacked";
		author = "Dominic";
		type = "mod";
		inputs = "FirstModPacked/Data/Inputs.xml";
		dependencies[] =
		{
			"Mission"
		};		
	    class defs
	    {
			class missionScriptModule		
            {
                files[] = 
				{
					"FirstModPacked/Mission"
				};
            };
        };
    };
};