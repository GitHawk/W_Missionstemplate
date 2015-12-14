// Set all global variables
0 call FETT_fnc_w_setVariables;

if (hasInterface) then {
	["postinit"] call FETT_fnc_w_clientInit;
};

if (isServer) then {
	["postinit"] call FETT_fnc_w_serverInit;
};

private _settings = call compile preprocessFileLineNumbers "settings.sqf";
_settings params ["","","","","_noHC"];
isHC = if (_noHC) then { isServer } else { !isNil "paramsArray" && {paramsArray select 0 == 1 && !hasInterface} };
if (isHC) then { call compile preprocessFileLineNumbers "initHC.sqf" };
