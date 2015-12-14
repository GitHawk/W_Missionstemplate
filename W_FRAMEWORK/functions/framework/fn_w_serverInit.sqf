diag_log "serverinit.sqf";
params ["_mode"];
_mode = toLower _mode;
switch _mode do {
	case "postinit": {
		{
			if (markerType _x == "") then {createMarker [_x,[0,0,0]]};
		} forEach ["respawn_west","respawn_east","respawn_guerrila","respawn_civilian"];
	};
};
