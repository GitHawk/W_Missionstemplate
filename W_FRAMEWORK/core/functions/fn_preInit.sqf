#include "..\script_component.hpp"

// Get all init scripts
FETT_framework_preInit = [[],[],[]];
FETT_framework_postInit = [[],[],[]];
0 call FETT_framework_fnc_fetchInitScripts;

// Get preinit scrips
private _clientScripts = FETT_framework_preInit param [INDEX_CLIENT,[],[[]]];
private _serverScripts = FETT_framework_preInit param [INDEX_SERVER,[],[[]]];

// Execute scripts
if (hasInterface) then {
	{
		["client","preinit"] call _x;
	} forEach _clientScripts;
};

if (isServer) then {
	{
		["server","preinit"] call _x;
	} forEach _serverScripts;
};
