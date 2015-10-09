if (hasInterface || !isServer) then {
	["postinit"] call FETT_fnc_w_clientInit;
};

if (isServer) then {
	["postinit"] call FETT_fnc_w_serverInit;
};

if (getText (missionConfigFile >> "medicSystem") == "RUNNINGMAN") then {
	FETT_w_defibrillator_allowed = true;
};
