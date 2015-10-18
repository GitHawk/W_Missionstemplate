#define CONTROL (_display displayCtrl _idc)

#define IDC_TITLE       100
#define IDC_SLIDER      101
#define IDC_TITLE_1     102
#define IDC_SLIDER_1    103
#define IDC_XLISTBOX    104

#define MAX_VD      12000
#define MAX_OBJ_VD  5000

disableSerialization;
private "_params";
_params = _this select 1;

switch (_this select 0) do {
	case ("init"): {
		if (isNil "FETT_VD_INIT") then {
			FETT_VD_INIT = true;

			if (isNil "FETT_VD_MAX") then {FETT_VD_MAX = MAX_VD};
			if (isNil "FETT_VD_MAX_OBJ") then {FETT_VD_MAX_OBJ = MAX_OBJ_VD};

			FETT_VD_STD = viewDistance min FETT_VD_MAX;
			setViewDistance FETT_VD_STD;

			FETT_VD_OBJ = viewDistance min FETT_VD_MAX_OBJ;
			setObjectViewDistance FETT_VD_OBJ;

			FETT_VD_GRID = 25;
			FETT_VD_TERRAIN_SETTINGS = [["Kein gras",50],["Standard",25],["Hoch",12],["Sehr hoch",6]];
			if (!isNil "FETT_VD_DISABLE_NOGRASS" && {FETT_VD_DISABLE_NOGRASS}) then {
				FETT_VD_TERRAIN_SETTINGS deleteAt 0;
			};
			if (!isNil "FETT_VD_FORCE_HIGHTERRAIN" && {FETT_VD_FORCE_HIGHTERRAIN}) then {
				FETT_VD_TERRAIN_SETTINGS = [["Sehr hoch",6]];
				FETT_VD_GRID = 6;
				setTerrainGrid FETT_VD_GRID;
			};

			player setVariable ["FETT_maxVD_obj",FETT_VD_MAX_OBJ,true];
		};

		private "_display";
		_display = _params select 0;

		// Set viewdistance options
		private "_idc";
		_idc = IDC_TITLE;
		CONTROL ctrlSetText (format ["Sichtweite: %1",FETT_VD_STD]);
		CONTROL ctrlCommit 0;
		_idc = IDC_SLIDER;
		CONTROL sliderSetRange [500,FETT_VD_MAX];
		CONTROL sliderSetSpeed [100,100,100];
		CONTROL sliderSetPosition FETT_VD_STD;

		// Set object viewdistance options
		_idc = IDC_TITLE_1;
		CONTROL ctrlSetText (format ["Objektsichtweite: %1",FETT_VD_OBJ]);
		CONTROL ctrlCommit 0;
		_idc = IDC_SLIDER_1;
		CONTROL sliderSetRange [500,FETT_VD_MAX_OBJ min FETT_VD_STD];
		CONTROL sliderSetSpeed [100,100,100];
		CONTROL sliderSetPosition (FETT_VD_OBJ min FETT_VD_STD);

		// Set terrain options
		_idc = IDC_XLISTBOX;
		private "_curGrid";
		_curGrid = -1;
		{
			private "_index";
			_index = CONTROL lbAdd (_x select 0);
			CONTROL lbSetValue [_index,(_x select 1)];
			if (_x select 1 == FETT_VD_GRID) then {_curGrid = _index};
		} forEach FETT_VD_TERRAIN_SETTINGS;
		if (_curGrid != -1) then {
			CONTROL lbSetCurSel _curGrid;
		};
	};
	case ("vd"): {
		private ["_ctrl","_display","_idc","_range"];
		_ctrl = _params select 0;
		_display = ctrlParent _ctrl;
		_idc = IDC_TITLE;

		_range = sliderPosition _ctrl;
		FETT_VD_STD = _range;
		CONTROL ctrlSetText format ["Sichtweite: %1",_range];
		CONTROL ctrlCommit 0;

		// apply object viewdistance as well
		_idc = IDC_SLIDER_1;
		CONTROL sliderSetRange [500,_range min FETT_VD_MAX_OBJ];
		CONTROL sliderSetPosition (_range min FETT_VD_OBJ);
		FETT_VD_OBJ = sliderPosition CONTROL;
		_idc = IDC_TITLE_1;
		CONTROL ctrlSetText format ["Objektsichtweite: %1",FETT_VD_OBJ];
		CONTROL ctrlCommit 0;

		setViewDistance _range;
	};
	case ("ovd"): {
		private ["_ctrl","_display","_idc","_range"];
		_ctrl = _params select 0;
		_display = ctrlParent _ctrl;
		_idc = IDC_TITLE_1;

		_range = sliderPosition _ctrl;
		FETT_VD_OBJ = _range;
		CONTROL ctrlSetText format ["Objektsichtweite: %1",_range];
		CONTROL ctrlCommit 0;

		setObjectViewDistance _range;
	};
	case ("terrain"): {
		private ["_ctrl","_display","_index"];
		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_index = _params select 1;

		_grid = _ctrl lbValue _index;
		setTerrainGrid _grid;
		FETT_VD_GRID = _grid;
	};
};
