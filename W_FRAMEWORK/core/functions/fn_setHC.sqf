params ["_setting"];
private _settings = call compile preprocessFileLineNumbers "settings.sqf";
_settings params ["","","","","_noHC"];
isHC = if (_noHC) then { isServer } else { (_setting == 1 && local HC) || (_setting == 0 && isServer) };
if (isHC) then { 0 spawn compile preprocessFileLineNumbers "initHC.sqf" };
