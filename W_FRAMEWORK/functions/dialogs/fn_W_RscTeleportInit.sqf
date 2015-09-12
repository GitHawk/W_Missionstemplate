#define CONTROL					(_display displayCtrl _idc)

#define LEADER_PIC				"W_FRAMEWORK\data\isLeader.paa"
#define VEHICLE_PIC 			"W_FRAMEWORK\data\isInVehicle.paa"
#define COMBINED_PIC 			"W_FRAMEWORK\data\isCombined.paa"

#define IDC_CB		2500
#define IDC_CB_1	2501
#define IDC_CB_2	2502
#define IDC_CB_3	2503

#define IDC_LB		1500
#define IDC_LB_1	1501

disableSerialization;
private "_params";
_params = _this select 1;

// set the ui event handlers
switch (_this select 0) do {
	case ("init"): {
		FETT_TELEPORT_TARGET = objNull;
		FETT_TELEPORT_TURRETS = [];
	};
	case ("cb"): {
		private ["_ctrl","_display"];
		_ctrl = _params select 0;
		_display = ctrlParent _ctrl;

		if (ctrlChecked _ctrl) then {
			private ["_cbs","_index"];
			_cbs = [IDC_CB,IDC_CB_1,IDC_CB_2,IDC_CB_3];
			_index = ctrlIDC _ctrl - IDC_CB;
			_cbs deleteAt _index;
			{
				private "_idc";
				_idc = _x;
				CONTROL ctrlSetChecked false;
			} forEach _cbs;
			_side = [west,independent,east,civilian] select _index;

			{
				private "_idc";
				_idc = _x;
				lbClear CONTROL;
			} forEach [IDC_LB,IDC_LB_1];

			private "_idc";
			_idc = IDC_LB;
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
		private ["_ctrl","_display","_index"];
		_ctrl = _params select 0;
		_display = ctrlParent _ctrl;
		_index = lbCurSel _ctrl;

		private ["_target","_vehicle"];
		_target = objNull;
		{
			if (name _x == _ctrl lbText _index) exitWith {_target = _x};
		} forEach (playableunits + switchableunits);
		_vehicle = vehicle _target;
		FETT_TELEPORT_TARGET = _target;

		private "_idc";
		_idc = IDC_LB_1;
		lbClear CONTROL;
		if (_vehicle == _target) then {
			private "_index";
			_index = CONTROL lbAdd "Soldier";
			CONTROL lbSetData [_index,"soldier"];
		} else {
			private ["_roles","_cargoSize"];
			_roles = [_vehicle] call BIS_fnc_vehicleRoles;
			_cargoSize = 0;
			{
				if (_x select 0 == "Cargo") then {
					_cargoSize = _cargoSize + 1;
					_roles = _roles - [_x];
				};
			} forEach _roles;

			{
				private "_vehicleRole";
				_vehicleRole = assignedVehicleRole _x;
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
				private "_index";
				_index = CONTROL lbAdd "Passenger";
				CONTROL lbSetData [_index,"cargo"];
			};

			FETT_TELEPORT_TURRETS = [];
			{
				switch (_x select 0) do {
					case "Driver" : {
						private "_index";
						_index = CONTROL lbAdd "Driver";
						CONTROL lbSetData [_index,"driver"];
					};
					case "Turret" : {
						private ["_path","_cfg","_displayName"];
						_path = _x select 1;
						_cfg = configfile >> "CfgVehicles" >> (typeOf _vehicle);
						{
							_cfg = (_cfg >> "Turrets") select _x;
						} forEach _path;
						_displayName = getText (_cfg >> "gunnerName");

						private "_index";
						_index = CONTROL lbAdd _displayName;
						CONTROL lbSetData [_index,"turret"];
						CONTROL lbSetValue [_index,_index];

						FETT_TELEPORT_TURRETS set [_index,(_x select 1)];
					};
				};
			} forEach _roles;

			private "_index";
			_index = CONTROL lbAdd "In the vicinity";
			CONTROl lbSetData [_index,"vicinity"];
		};
	};
	case ("teleport"): {
		private ["_ctrl","_display"];
		_ctrl = _params select 0;
		_display = ctrlParent _ctrl;

		private ["_idc","_index"];
		_idc = IDC_LB;
		_index = lbCurSel CONTROL;
		if (isNull FETT_TELEPORT_TARGET || isNil "FETT_TELEPORT_TARGET") exitWith {
			hintC "No player selected!";
			createDialog "W_RscTeleportDialog";
		};

		private ["_target","_mode"];
		_target = vehicle FETT_TELEPORT_TARGET;
		_idc = IDC_LB_1;
		_index = lbCurSel CONTROL;
		_mode = if (_index < 0) then {"vicinity"} else {CONTROL lbData _index};
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
					createDialog "W_RscTeleportDialog";
				} else {
					player moveInCargo _target;
				};
			};
			case "turret" : {
				if (damage _target > 0.9) then {
					hintC "Player not available anymore!";
					createDialog "W_RscTeleportDialog";
				} else {
					player moveInTurret [_target,(FETT_TELEPORT_TURRETS select _index)];
				};
			};
			case "driver" : {
				if (damage _target > 0.9) then {
					hintC "Player not available anymore!";
					createDialog "W_RscTeleportDialog";
				} else {
					player moveInDriver _target;
				};
			};
		};
	};
};
