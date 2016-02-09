params [["_obj", objNull, [objNull]]];
if (!hasInterface && isNull _obj) exitWith {};
if (isNull _obj) then {
    _obj = player;
};

private _loadout = _obj getVariable ["loadout",""];
if (_loadout == "") exitWith {};

removeAllWeapons _obj;
removeAllItems _obj;
removeAllAssignedItems _obj;
removeUniform _obj;
removeVest _obj;
removeBackpack _obj;
removeHeadgear _obj;
removeGoggles _obj;

private _file = "";
switch (side _obj) do {
	case (civilian): { _file = "loadouts\civilian_loadout.sqf"; };
	case (east): { _file = "loadouts\east_loadout.sqf"; };
	case (independent): { _file = "loadouts\independent_loadout.sqf"; };
	case (west): { _file = "loadouts\west_loadout.sqf"; };
};

private _code = {};
if (!hasInterface) then {
    _code = missionNamespace getVariable [format ["loadouts_%1", side _obj], ""];
    if (_code == "") then {
        _code = compile preprocessFileLineNumbers _file;
        missionNamespace setVariable [format ["loadouts_%1", side _obj], _code];
    };
} else {
    _code = compile preprocessFileLineNumbers _file;
};

[{
	params ["_args", "_pfh"];
	_args params ["_loadout", "_obj", "_code"];

	[_loadout, _obj] call _code;
	[_pfh] call CBA_fnc_removePerFramehandler;
}, 0, [_loadout, _obj, _code]] call CBA_fnc_addPerFramehandler;
