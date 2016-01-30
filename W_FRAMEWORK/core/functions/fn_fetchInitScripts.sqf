// Get the init config
private _cfgFramework = missionConfigFile >> "CfgFramework";
if (!isClass _cfgFramework) exitWith {
	diag_log "WARNING MESSAGE - W_FRAMEWORK ERROR: NO CfgFramework GIVEN!";
};

{
	private _cfg = _x;

	// Get the script
	private _script = {};
	switch (true) do {
		case (!isNull (_cfg >> "code")): {
			_script = compile getText (_cfg >> "code");
		};
		case (!isNull (_cfg >> "function")): {
			_script = missionNamespace getVariable [getText (_cfg >> "function"),{}];
		};
		case (!isNull (_cfg >> "file")): {
			_script = compile preprocessFileLineNumbers getText (_cfg >> "file");
		};
	};

	// Script couldn't be resolved
	if (_script isEqualTo {}) then {
		diag_log format ["WARNING MESSAGE - W_FRAMEWORK ERROR: COULD NOT RESOLVE SCRIPT FOR %1",configName _cfg];
	} else {
		// Should this script be activated during post and/or preinit?
		private _preInit = getNumber (_cfg >> "preinit") == 1;
		private _postInit = getNumber (_cfg >> "postinit") == 1;

		// Where should this script be activated?
		{
			_x params ["_attribute","_index"];

			if (getNumber (_cfg >> _attribute) == 1) then {
				if (_preInit) then {
					(FETT_framework_preInit select _index) pushBack _script;
				};

				if (_postInit) then {
					(FETT_framework_postInit select _index) pushBack _script;
				};
			};
		} forEach [["client",INDEX_CLIENT],["server",INDEX_SERVER],["hc",INDEX_HC]];
	};
} forEach ("true" configClasses _cfgFramework);
