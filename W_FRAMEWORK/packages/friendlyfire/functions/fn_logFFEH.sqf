if (["logff",false,"BOOL"] call FETT_framework_fnc_getSetting) then {
	player addEventHandler ["Hit",{
		params ["_target","_shooter"];
		if (isPlayer _shooter && {side _shooter == side _target && _shooter != _target}) then {
			[_target,_shooter] remoteExecCall ["FETT_framework_fnc_logFF"];
		};
	}];
};
