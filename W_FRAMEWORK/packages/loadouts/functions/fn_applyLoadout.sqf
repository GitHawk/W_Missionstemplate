private _loadout = player getVariable ["loadout",""];
private _faction = player getVariable ["faction", faction player];
if (_loadout == "") exitWith {};

removeAllWeapons player;
removeAllItems player;
removeAllAssignedItems player;
removeUniform player;
removeVest player;
removeBackpack player;
removeHeadgear player;
removeGoggles player;

private _file = "";
switch (side player) do {
    case (civilian): { _file = "loadouts\civilian_loadout.sqf"; };
    case (east): { _file = "loadouts\east_loadout.sqf"; };
    case (independent): { _file = "loadouts\independent_loadout.sqf"; };
    case (west): { _file = "loadouts\west_loadout.sqf"; };
};

[{
    params ["_args","_pfh"];
    _args params ["_loadout","_faction"];

    [_loadout, _faction, player] call FETT_fnc_applyCfgLoadout;
    [_pfh] call CBA_fnc_removePerFramehandler;
},0,[_loadout, _faction]] call CBA_fnc_addPerFramehandler;
