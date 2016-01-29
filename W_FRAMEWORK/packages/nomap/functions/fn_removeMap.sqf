if (0 call ["nomap",{false},"CODE"] call FETT_framework_fnc_getSetting) then {
	[{
		params ["","_pfh"];
		if (!isNull (findDisplay 46)) then {
			[_pfh] call CBA_fnc_removePerFramehandler;
			player unlinkItem "ItemMap";
		};
	},0,[]] call CBA_fnc_addPerFramehandler;
};
