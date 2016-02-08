#include "..\script_component.hpp"

disableSerialization;
params ["_mode","_params"];

// set the ui event handlers
switch (_mode) do {
	case ("init"): {
		FETT_TELEPORT_TARGET = objNull;
		FETT_TELEPORT_TURRETS = [];
	};
	case ("cb"): {
		private _ctrl = _params select 0;
		private _display = ctrlParent _ctrl;

		if (ctrlChecked _ctrl) then {
			private _cbs = [IDC_CB,IDC_CB_1,IDC_CB_2,IDC_CB_3];
			private _index = ctrlIDC _ctrl - IDC_CB;
			_cbs deleteAt _index;
			{
				private _idc = _x;
				CONTROL ctrlSetChecked false;
			} forEach _cbs;
			_side = [west,independent,east,civilian] select _index;

			{
				private _idc = _x;
				lbClear CONTROL;
			} forEach [IDC_LB,IDC_LB_1];

			private _idc = IDC_LB;
			{
				if (side _x == _side) then {
					_index = CONTROL lbAdd (name _x);

					_pic = "";
					switch (true) do {
						case ((leader _x == _x) && (vehicle _x == _x)): {_pic = LEADER_PIC;};
						case (!(leader _x == _x) && !(vehicle _x == _x)): {_pic = VEHICLE_PIC;};
						case ((leader _x == _x) && !(vehicle _x == _x)): {_pic = COMBINED_PIC;};
					};
					CONTROL lbSetPicture [_index,_pic];
				};
			} forEach (playableunits + switchableunits);
			lbSort CONTROL;
		};
	};
	case ("lb"): {
		private _ctrl = _params select 0;
		private _display = ctrlParent _ctrl;
		private _index = lbCurSel _ctrl;

		private _target = objNull;
		{
			if (name _x == _ctrl lbText _index) exitWith {_target = _x};
		} forEach (playableunits + switchableunits);
		private _vehicle = vehicle _target;
		FETT_TELEPORT_TARGET = _target;

		private _idc = IDC_LB_1;
		lbClear CONTROL;
		if (_vehicle == _target) then {
			private _index = CONTROL lbAdd "Soldier";
			CONTROL lbSetData [_index,"soldier"];
		} else {
			private _roles = [_vehicle] call BIS_fnc_vehicleRoles;
			private _cargoSize = 0;
			{
				if (_x select 0 == "Cargo") then {
					_cargoSize = _cargoSize + 1;
					_roles = _roles - [_x];
				};
			} forEach _roles;

			{
				private _vehicleRole = assignedVehicleRole _x;
				switch (_vehicleRole select 0) do {
					case "Driver" : {
						_roles = _roles - [["Driver",[]]];
					};
					case "Turret" : {
						_roles = _roles - [_vehicleRole];
					};
					case "Cargo" : {
						_cargoSize = _cargoSize - 1;
					};
				};
			} forEach (crew _vehicle);

			if (_cargoSize > 0) then {
				private _index = CONTROL lbAdd "Passenger";
				CONTROL lbSetData [_index,"cargo"];
			};

			FETT_TELEPORT_TURRETS = [];
			{
				switch (_x select 0) do {
					case "Driver" : {
						private _index = CONTROL lbAdd "Driver";
						CONTROL lbSetData [_index,"driver"];
					};
					case "Turret" : {
						private _path = _x select 1;
						private _cfg = configfile >> "CfgVehicles" >> (typeOf _vehicle);
						{
							_cfg = (_cfg >> "Turrets") select _x;
						} forEach _path;
						private _displayName = getText (_cfg >> "gunnerName");

						private _index = CONTROL lbAdd _displayName;
						CONTROL lbSetData [_index,"turret"];
						CONTROL lbSetValue [_index,_index];

						FETT_TELEPORT_TURRETS set [_index,(_x select 1)];
					};
				};
			} forEach _roles;

			private _index = CONTROL lbAdd "In the vicinity";
			CONTROl lbSetData [_index,"vicinity"];
		};
	};
	case ("teleport"): {
		private _ctrl = _params select 0;
		private _display = ctrlParent _ctrl;

		private _idc = IDC_LB;
		private _index = lbCurSel CONTROL;
		if (isNull FETT_TELEPORT_TARGET || isNil "FETT_TELEPORT_TARGET") exitWith {
			hintC "No player selected!";
			createDialog "FETT_teleporterDialog";
		};

		private _target = vehicle FETT_TELEPORT_TARGET;
		_idc = IDC_LB_1;
		_index = lbCurSel CONTROL;
		private _mode = if (_index < 0) then {"vicinity"} else {CONTROL lbData _index};
		switch _mode do {
			case "soldier" : {
				_pos = _target modelToWorld [0,-2,0];
				player setpos _pos;
			};
			case "vicinity" : {
				_pos = _target modelToWorld [-5,-5,0];
				_pos set [2,0];
				player setpos _pos;
			};
			case "cargo" : {
				if (damage _target > 0.9) then {
					hintC "Player not availabe anymore!";
					createDialog "FETT_teleporterDialog";
				} else {
					player moveInCargo _target;
				};
			};
			case "turret" : {
				if (damage _target > 0.9) then {
					hintC "Player not available anymore!";
					createDialog "FETT_teleporterDialog";
				} else {
					player moveInTurret [_target,(FETT_TELEPORT_TURRETS select _index)];
				};
			};
			case "driver" : {
				if (damage _target > 0.9) then {
					hintC "Player not available anymore!";
					createDialog "FETT_teleporterDialog";
				} else {
					player moveInDriver _target;
				};
			};
		};
	};
};
