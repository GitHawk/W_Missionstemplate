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
if (_loadout == "") exitWith {};
private _faction = _obj getVariable ["faction", faction _obj];

removeAllWeapons _obj;
removeAllItems _obj;
removeAllAssignedItems _obj;
removeUniform _obj;
removeVest _obj;
removeBackpack _obj;
removeHeadgear _obj;
removeGoggles _obj;

private _file = "";

[{
    params ["_args","_pfh"];
    _args params ["_loadout","_faction", "_obj"];

    [_loadout, _faction, _obj] call FETT_fnc_applyCfgLoadout;
    [_pfh] call CBA_fnc_removePerFramehandler;
},0,[_loadout, _faction, _obj]] call CBA_fnc_addPerFramehandler;
