/*
 * Argument:
 * 0: Target <OBJECT> (optional if player)
 * 1: Loadout <STRING> (optional)
 * 2: Side <STRING> (optional)
 *
 * Example:
 * [] call FETT_framework_fnc_applyLoadout
 * [_unit] call FETT_framework_fnc_applyLoadout
 * [_unit, "SNIPER"] call FETT_framework_fnc_applyLoadout
 * [_unit, "SNIPER", "east"] call FETT_framework_fnc_applyLoadout
 */

params [["_obj", objNull, [objNull]]];
if (!hasInterface && {isNull _obj}) exitWith {};
if (isNull _obj) then {
    _obj = player;
};
params ["", ["_loadout", _obj getVariable ["loadout", ""], [""]], ["_side", _obj getVariable ["side", str (side _obj)], [""]]];

if (isPlayer _obj && didJIP && {[W_frameworkLoadoutHash,name player] call CBA_fnc_hashHasKey}) then {
    _loadout = [W_frameworkLoadoutHash,name player] call CBA_fnc_hashGet;
};

if (_loadout == "") exitWith {};

if (isPlayer _obj && {!([W_frameworkLoadoutHash,name player] call CBA_fnc_hashHasKey)}) then {
    W_frameworkLoadoutSync = [name player,_loadout];
    publicVariableServer "W_frameworkLoadoutSync";
};

removeAllWeapons _obj;
removeAllItems _obj;
removeAllAssignedItems _obj;
removeUniform _obj;
removeVest _obj;
removeBackpack _obj;
removeHeadgear _obj;
removeGoggles _obj;

private _file = "";
_side = toLower _side;
switch (_side) do {
    case ("civilian"): { _file = "loadouts\civilian_loadout.sqf"; };
    case ("east"): { _file = "loadouts\east_loadout.sqf"; };
    case ("guer"): { _file = "loadouts\independent_loadout.sqf"; };
    case ("west"): { _file = "loadouts\west_loadout.sqf"; };
};

private _code = {};
if (hasInterface) then {
    _code = compile preprocessFileLineNumbers _file;
} else {
    _code = missionNamespace getVariable [format ["loadouts_%1", _side], ""];
    if (_code == "") then {
        _code = compile preprocessFileLineNumbers _file;
        missionNamespace setVariable [format ["loadouts_%1", _side], _code];
    };
};

[{
    params ["_args", "_pfh"];
    _args params ["_loadout", "_obj", "_code"];

    [_loadout, _obj] call _code;
    [_pfh] call CBA_fnc_removePerFramehandler;
}, 0, [_loadout, _obj, _code]] call CBA_fnc_addPerFramehandler;
