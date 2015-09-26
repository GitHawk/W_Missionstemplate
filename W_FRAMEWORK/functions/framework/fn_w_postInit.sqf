if (hasInterface || !isServer) then {
	["postinit"] call FETT_fnc_w_clientInit;
};

if (isServer) then {
	["postinit"] call FETT_fnc_w_serverInit;
};
