if !(isMultiplayer) exitWith { isHC = true; OWNERHC = owner player; };

// Get the HC Settings
[{
	if (!isNil "paramsArray") then {
		if ( paramsArray select 0 == 1) then {
			isHC = !isServer && !hasInterface;
		} else {
			isHC = isServer;
		};

		[_this select 1] call CBA_fnc_removePerFrameHandler;
	};
},0,[]] call CBA_fnc_addPerFrameHandler;

// Find out, who is the owner of the HC
if !(isServer) exitWith {};

[{
	if (!isNil "bis_functions_mainscope") then {
		if (isHC) then {
			OWNERHC = owner bis_functions_mainscope;
		} else {
			OWNERHC = owner HC;
		};
		publicVariable "OWNERHC";

		[_this select 1] call CBA_fnc_removePerFrameHandler;
	};
},0,[]] call CBA_fnc_addPerFrameHandler;
