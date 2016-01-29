params ["_setting"];

isHC = if (isNil "HC") then {
	["W_FRAMEWORK ERROR: NO HC SET"] call BIS_fnc_error;
	isServer
} else {
	(_setting == 1 && local HC) || (_setting == 0 && isServer)
};
