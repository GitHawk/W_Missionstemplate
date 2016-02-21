W_frameworkLoadoutHash = [] call CBA_fnc_hashCreate;
publicVariable "W_frameworkLoadoutHash";

"W_frameworkLoadoutSync" addPublicVariableEventHandler {
	params ["_varname","_data"];
	_data params ["_playername","_loadoutClass"];

	[W_frameworkLoadoutHash,_playername,_loadoutClass] call CBA_fnc_hashSet;
	publicVariable "W_frameworkLoadoutHash";
};