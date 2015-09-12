_class = [_this,0,"",[""]] call BIS_fnc_param;
_obj = [_this,1,player,[objNull]] call BIS_fnc_param;
_isJIP = [_this,2,false,[true]] call BIS_fnc_param;

if (_class == "") exitWith {};
_class = toUpper _class;

#define this _obj
// --- Ab hier bearbeiten:

if (_class == "YOURCLASS") exitWith {

};