params [["_obj",objNull,[objNull]]];

private _radios = ["ACRE_PRC343","ACRE_PRC148","ACRE_PRC152","ACRE_PRC117F","ACRE_PRC77"];
private _whitelist = ["radios_whitelist",_radios,"ARRAY"] call FETT_framework_fnc_getSetting;
_radios = _radios arrayIntersect _whitelist;

{
	_obj addAction [format ["%1 holen",_x],{ player addItem (_this select 3); },_x];
} forEach _radios;
