if (isMultiplayer) exitWith {};

private "_found";
_found = [];
{
	if !(allMissionObjects _x isEqualTo []) then {_found pushBack _x};
} forEach _this;

if (_found isEqualTo []) exitWith {};

private "_string";
_string = "Fehler: Du hast die Module ";
{
	_name = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
	_string = _string + _name + " ";
} forEach _found;
_string = _string + "platziert. Diese müssen gelöscht werden.";

[{
	if (!isNull (findDisplay 46)) then {
		params ["_message","_handler"];
		_message call BIS_fnc_error;
		[_handler] call CBA_fnc_removePerFrameHandler;
	};
},0,_string] call CBA_fnc_addPerFrameHandler;
