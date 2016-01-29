params ["_mode"];
_mode = toLower _mode;
switch _mode do {
	case "postinit": {
		// Get all settings
		private _settings = call compile preprocessFileLineNumbers "settings.sqf";
		_settings params ["_cfgLoadouts","_noMapCondition","_logFF","_allowKick"];

		private _missingDLCs = getDLCs 2;
		// noHeli || noMarksman
		if (304380 in _missingDLCs || 332350 in _missingDLCs) then {
			[name player] remoteExecCall ["FETT_fnc_w_dlcMissing",0];
			if (_allowKick) then {
				["dlcMissing"] call BIS_fnc_endMission;
			};
		};

		player addAction ["Viewdistance",{createDialog "W_RscVDDialog";}];

		// Apply loadout
		if (_cfgLoadouts) then {
			[player getVariable ["loadout",""],"",player] call FETT_fnc_applyCfgLoadout;
		} else {
			private _fnc = format ["FETT_fnc_%1_loadout",["b","i","c","o"] select ([west,independent,civilian,east] find side player)];
			_fnc = missionNamespace getVariable _fnc;
			[(player getVariable ["loadout",""]),player] call _fnc;
		};

		// Remove map
		if (0 call _noMapCondition) then {
			[{
				if (!isNull (findDisplay 46)) then {
					player unlinkItem "ItemMap";
					[_this select 1] call CBA_fnc_removePerFramerHandler;
				};
			},0,[]] call CBA_fnc_addPerFrameHandler;
		};

		// Log friendly fire
		if (_logFF) then {
			player addEventHandler ["Hit",{
				params ["_target","_shooter"];
				if (isPlayer _shooter && {side _shooter == side _target && _shooter != _target}) then {
					[_target,_shooter] remoteExecCall ["FETT_fnc_w_killMessage"];
				};
			}];
		};
	};
};
