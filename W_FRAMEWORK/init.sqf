tf_no_auto_long_range_radio = true;
TF_give_personal_radio_to_regular_soldier = true;
TF_terrain_interception_coefficient = -10;
W_no_ff_punishment = true;

// Run the initHC.sqf
[{
	if (!isNil "isHC") then {
		if (isHC) then {
			execVM "initHC.sqf";
		};

		[_this select 1] call CBA_fnc_removePerFrameHandler;
	};
},0,[]] call CBA_fnc_addPerFrameHandler;
