params ["_gotKilled","_didKill"];
if (isNil "_gotKilled" || isNil "_didKill") exitWith {};

private "_shooterCrewMessage";
_shooterCrewMessage = "SHOOTER VEHICLE CREW: ";
{
	private ["_thisMessage","_role"];
	_thisMessage = name _x;
	_role = (assignedVehicleRole _x) param [0,""];
	if (_role != "") then {
		_thisMessage = _thisMessage + " (" + _role + ")"
	};
	_thisMessage = _thisMessage + ", ";

	_shooterCrewMessage = _shooterCrewMessage + _thisMessage;
} forEach (crew vehicle _didKill);

private "_message";
_message = "

" + format ["W_LOG_FRIENLDYFIRE: %1 FROM %2 IN %3",name _gotKilled,name _didKill,typeOf vehicle _didKill] + "
" + _shooterCrewMessage + "
" + format ["SHOT AT %1 FROM %2",getPosATL _gotKilled,getPosATL _didKill] + "
" + format ["SHOT WITH %1",currentWeapon vehicle _didKill] + "

";

diag_log text _message;
