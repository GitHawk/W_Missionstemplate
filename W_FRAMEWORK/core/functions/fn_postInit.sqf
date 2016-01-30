#include "..\script_component.hpp"

// Get postinit scripts
private _clientScripts = FETT_framework_preInit param [INDEX_CLIENT,[],[[]]];
private _serverScripts = FETT_framework_preInit param [INDEX_SERVER,[],[[]]];
private _hcScripts = FETT_framework_preInit param [INDEX_HC,[],[[]]];

// Execute scripts
if (hasInterface) then {
	{
		["client","postinit"] call _x;
	} forEach _clientScripts;
};

if (isServer) then {
	{
		["server","postinit"] call _x;
	} forEach _serverScripts;
};

if (!isNil "isHC" && {isHC}) then {
	{
		["hc","postinit"] call _x;
	} forEach _hcScripts;

// Error message, just to be sure
} else {
	private _message = "WARNING MESSAGE - W_FRAMEWORK ERROR: isHC isNil during postInit";
	[_message] call BIS_fnc_error;
	diag_log _message;
};
