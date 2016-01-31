params [["_attribute","",[""]],"_default",["_type","SCALAR",[""]]];
_type = toUpper _type;

if !(_type in ["SCALAR","BOOL","ARRAY","STRING","CODE"]) throw "W_FRAMEWORK ERROR: BAD TYPE IN FETT_FRAMEWORK_FNC_GETSETTING";

private _setting = missionConfigFile >> "CfgFrameworkSettings" >> _attribute;
if (isNull _setting) exitWith { _default };

private _val = 0;
switch (_type) do {
	case "SCALAR": { _val = getNumber _setting; };
	case "BOOL": { _val = getNumber _setting != 0; };
	case "STRING": { _val = getText _setting; };
	case "ARRAY": { _val = getArray _setting; };
	case "CODE": { _val = compile getText _setting; };
};

_val
