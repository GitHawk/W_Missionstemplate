
if !(isMultiplayer) then {
	// An array with all objects that are not allowed
	_prohibited = ["ACE_moduleMedicalSettings","ACE_moduleAdvancedMedicalSettings","ACE_moduleReviveSettings"];
	_found = [];
	{
		if !(allMissionObjects _x isEqualTo []) then {_found pushBack _x};
	} forEach _prohibited;

	if !(_found isEqualTo []) then {
		_found spawn {
			waitUntil { !isNull (findDisplay 46) };

			[{
				if (!isNull (findDisplay 46)) then {
					_string = "Fehler: Du hast die Module ";
					{
						_name = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
						_string = _string + _name + " ";
					} forEach _this select 0;
					_string = _string + "platziert. Diese müssen gelöscht werden.";
					_string call BIS_fnc_error;

					[_this select 1] call CBA_fnc_removePerFrameHandler;
				};
			},0,_this] call CBA_fnc_addPerFrameHandler;
		};
	};
};

if (isServer) then {
	{
		if (markerType _x == "") then {createMarker [_x,[0,0,0]]};
	} forEach ["respawn_west","respawn_east","respawn_guerrila","respawn_civilian"];
};
