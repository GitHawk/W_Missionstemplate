// Set all global variables
0 call FETT_fnc_w_setVariables;

if (hasInterface) then {
	["postinit"] call FETT_fnc_w_clientInit;
};

if (isServer) then {
	["postinit"] call FETT_fnc_w_serverInit;
};

if (isHC) then { call compile preprocessFileLineNumbers "initHC.sqf" };
