class loadoutsFix {
	code = "[] call FETT_framework_fnc_serverCreateHash";
	server = 1;
	preinit = 1;
};

class loadouts {
	code = "[player] call FETT_framework_fnc_applyLoadout";
	client = 1;
	postinit = 1;
};