#ifndef CFGLOADOUTS
	[(player getVariable ["loadout",""]),player,(_this select 1)] call (missionnamespace getVariable format ["FETT_fnc_%1_loadout",["b","i","c","o"] select ([west,independent,civilian,east] find (side player))]);
#else
	[player getVariable ["loadotu",""]] call FETT_fnc_applyCfgLoadout;
#endif

_missingHeli = 304380 in getDLCs 2;
_missingMarksmen = 332350 in getDLCs 2;
if (_missingHeli || _missingMarksmen) then {
	[name player] remoteExecCall ["FETT_fnc_w_dlcMissing",0];
    ["dlcMissing"] call BIS_fnc_endMission;
};

#ifdef NO_MAP_CONDITION
	if (NO_MAP_CONDITION) then {
		[{
			if (!isNull (findDisplay 46)) then {
				player unlinkItem "ItemMap";

				[_this select 1] call CBA_fnc_removePerFramerHandler;
			};
		},0,[]] call CBA_fnc_addPerFrameHandler;
	};
#endif

player addAction ["Viewdistance",{createDialog "W_RscVDDialog";}];
