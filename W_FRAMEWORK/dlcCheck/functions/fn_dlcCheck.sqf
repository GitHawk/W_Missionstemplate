private _missingDLCs = getDLCs 2;
// noHeli || noMarksman
if (304380 in _missingDLCs || 332350 in _missingDLCs) then {
	[name player] remoteExecCall ["FETT_fnc_w_dlcMissing",0];
	hintC "Dir fehlt mindestens ein DLC!";

	if (["allowkick",false,"BOOL"] call FETT_framework_fnc_getSetting) then {
		[{
			params ["_time","_pfh"];
			if (time > _time) then {
				[_pfh] call CBA_fnc_removePerFramehandler;
				[] call BIS_fnc_endMission;
			};
		},0,time + 8] call CBA_fnc_addPerFramehandler;
	};
};
