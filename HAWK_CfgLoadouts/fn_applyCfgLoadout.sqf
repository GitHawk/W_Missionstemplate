#define SELECTRANDOM(ARR) (ARR select (floor random count ARR))

params [["_class", "", [""]], ["_faction", "", [""]], ["_obj", player, [objNull]]];

if (_class isEqualTo "") then {
    _class = typeOf _obj;
};

if (typeName _faction != "STRING" || _faction isEqualTo "") then {
    _faction = getText (configFile >> "CfgVehicles" >> typeOf _obj >> "faction");
};

private _loadout = missionConfigFile >> "CfgLoadouts" >> _faction >> _class;
if (!isClass _loadout) exitWith {
    diag_log format ["W Loadout error: class %1 not found", _class];
};

// Reset medical and logistical status
_obj setVariable ['ace_isEngineer', 0, true];
_obj setVariable ["ace_medical_medicClass", 0, true];

// Add container
private ["_magazinesPrimary", "_magazinesSecondary", "_magazinesHandgun", "_magazinesAdditionally"];
// Add uniform
private _container = getArray (_loadout >> "Container" >> "uniform_pool");
private _addedContainer = ["", "", ""];
if (count _container != 0) then {
    private _uniform = SELECTRANDOM(_container);
    _obj forceAddUniform _uniform;
    _addedContainer set [0, _uniform];
};

// Add vest
_container = getArray (_loadout >> "Container" >> "vest_pool");
if (count _container != 0) then {
    private _vest = SELECTRANDOM(_container);
    _obj addVest _vest;
    _addedContainer set [1, _vest];
};

// Add backpack
_container = getArray (_loadout >> "Container" >> "backpack_pool");
if (count _container != 0) then {
    private _backpack = SELECTRANDOM(_container);
    _obj addBackpack _backpack;
    _addedContainer set [2, _backpack];
};

// Add gear
{
    private _gear = getArray (_loadout >> "Gear" >> _x);
    if (count _gear != 0) then {
        _obj addWeapon SELECTRANDOM(_gear);
    };
} forEach ["helmet_pool", "goggle_pool", "nightvision_pool", "map_pool", "compass_pool", "clock_pool", "gps_pool"];

private _gear = getArray (_loadout >> "Gear" >> "binocular");
_gear params [["_binocular", ""], ["_battery", ""]];
if (_binocular != "") then {
    _obj addWeapon _binocular;
    if (_battery != "") then {
        _obj addMagazine _battery;
    };
};

// Add non-weapon gear from ACRE
private _gear = getArray (_loadout >> "Gear" >> "radios");
if (count _gear != 0) then {
    {
        _obj addItem _x;
    } forEach _gear;
};


// Add weapons and get magazines
private _magazinesPrimary = [];
private _magazinesSecondary = [];
private _magazinesHandgun = [];
private _magazinesAdditionally = [];
{
    private _weaponPath = _loadout >> "Weapons" >> _x;
    private _weapons = getArray (_weaponPath >> "weapon_pool");
    private _weaponType = _x;
    private _weaponMagazinesArray = [];
    if (count _weapons != 0) then {
        // Add weapon
        _obj addWeapon SELECTRANDOM(_weapons);

        // Get the type of the weapon
        private _addFnc = {};
        switch _weaponType do {
            case ("primaryWeapon"): {
                _addFnc = { _obj addPrimaryWeaponItem _this };
                _weaponMagazinesArray = _magazinesPrimary; // set the pointer
            };
            case ("secondaryWeapon"): {
                _addFnc = { _obj addSecondaryWeaponItem _this };
                _weaponMagazinesArray = _magazinesSecondary; // set the pointer
            };
            case ("handGun"): {
                _addFnc = { _obj addHandgunItem _this };
                _weaponMagazinesArray = _magazinesHandgun; // set the pointer
            };
        };

        // Add one magazine to the weapon
        (getText (_weaponPath >> "magazine")) call _addFnc;

        // Add attachments
        {
            _x params ["_pool", ["_random", true]];
            private _attachments = getArray (_weaponPath >> _pool);
            if (count _attachments != 0) then {
                if (_random) then {
                    private _attachment = SELECTRANDOM(_attachments);
                    _attachment call _addFnc;
                } else {
                    {
                        if (_forEachIndex == 0) then {
                            _x call _addFnc;
                        } else {
                            _obj addItem _x;
                        }
                    } forEach _attachments;
                };
            };
        } forEach [["muzzleAttachment_pool"], ["barrelAttachment_pool"], ["weaponRestingAttachment_pool"], ["scopes", false]];

        // Save the magazines
        private _magazinesMax = getNumber (_weaponPath >> "magazinesMax");
        private _magazineTracer = getText (_weaponPath >> "magazineTracer");
        private _tracersEvery = if (_magazineTracer == "") then {
            _magazinesMax + 1
        } else {
            getNumber (_weaponPath >> "magazinesTracerEvery")
        };
        private _magazine = getText (_weaponPath >> "magazine");

        for "_i" from 1 to _magazinesMax do {
            if (_i % _tracersEvery == 0) then {
                _weaponMagazinesArray pushBack _magazineTracer;
            } else {
                _weaponMagazinesArray pushBack _magazine;
            };
        };

        {
            if (typeName _x == typeName []) then {
                _x params ["_magazine","_count"];
                for "_i" from 1 to _count do {
                    _magazinesAdditionally pushBack _magazine;
                };
            } else {
                _magazinesAdditionally pushBack _x;
            };
        } forEach (getArray (_weaponPath >> "optional"));
    };
} forEach ["secondaryWeapon", "handGun", "primaryWeapon"];

// Get medic material, grenades and other
private _medicMaterial = getArray (_loadout >> "Items" >> "medicMaterial");
_obj call compile getText (_loadout >> "Items" >> "onApplyLoadout");
private _grenades = getArray (_loadout >> "Items" >> "grenades");
private _other = getArray (_loadout >> "Items" >> "other");
private _ace =  getArray (_loadout >> "Items" >> "ace");
private _combined = [_medicMaterial, _grenades, _other, _ace];
{
    private _array = _x;
    {
        private _transformed = [];
        if (typeName _x == typeName []) then {
            _x params ["_magazine","_count"];
            for "_i" from 1 to _count do {
                _transformed pushBack _magazine;
            };
        } else {
            _transformed pushBack _x;
        };
        _array set [_forEachIndex, _transformed];
    } forEach _array;

    private _appended = [];
    {
        _appended append _x;
    } forEach _array;

    _combined set [_forEachIndex, _appended];
} forEach _combined;

_combined params ["_medicMaterial", "_grenades", "_other", "_ace"];
_addedContainer params ["_uniform", "_vest", "_backpack"];
private _medicMaterialAdded = false;

if !(_backpack == "") then {
    if (getNumber (configFile >> "CfgVehicles" >> (backpack _obj) >> "maximumLoad") > 0) then {
        {
            if (_obj canAddItemToBackpack _x ) then {
                _obj addItemToBackpack _x;
            } else {
                _obj addItem _x;
            };
        } forEach _medicMaterial;
        {
            if (_obj canAddItemToBackpack _x ) then {
                _obj addItemToBackpack _x;
            } else {
                _obj addItem _x;
            };
        } forEach _ace;
        {
            if (_obj canAddItemToBackpack _x ) then {
                _obj addItemToBackpack _x;
            } else {
                _obj addItem _x;
            };
        } forEach _magazinesAdditionally;
        _medicMaterialAdded = true;
    };
};
if !((_vest == "") || _medicMaterialAdded) then {
    if (getNumber (configFile >> "CfgVehicles" >> format ["Vest_%1", vest _obj] >> "maximumLoad") > 0) then {
        {
            if (_obj canAddItemToVest _x ) then {
                _obj addItemToVest _x;
            } else {
                _obj addItem _x;
            };
        } forEach _medicMaterial;
        {
            if (_obj canAddItemToVest _x ) then {
                _obj addItemToVest _x;
            } else {
                _obj addItem _x;
            };
        } forEach _ace;
        {
            if (_obj canAddItemToVest _x ) then {
                _obj addItemToVest _x;
            } else {
                _obj addItem _x;
            };
        } forEach _magazinesAdditionally;
        _medicMaterialAdded = true;
    };
};
// Add medic material if it hasn't been added yet
if !(_medicMaterialAdded) then {
    {
        _obj addItem _x;
    } forEach _medicMaterial;
    {
        _obj addItem _x;
    } forEach _ace;
};

// Add grenades
{
    _obj addItem _x;
} forEach _grenades;

// Add other stuff
{
    _obj addItem _x;
} forEach _other;

// Finally add additional magazine
if !(_medicMaterialAdded) then {
    {
        _obj addItem _x;
    } forEach _magazinesAdditionally;
};

// Add all magazines
private _biggestArrayCount = 0;
private _allMagazines = [];
{
    if (count _x != 0) then {
        _allMagazines pushBack _x;
    };
} forEach [_magazinesPrimary, _magazinesSecondary, _magazinesHandgun];

{
    if (count _x > _biggestArrayCount) then {
        _biggestArrayCount = count _x;
    };
} forEach _allMagazines;

{
    private _factor = floor (_biggestArrayCount / count _x);
    private _new = [];
    for "_i" from 0 to (_biggestArrayCount - 1) do {
        _new set [_i, ""];
    };

    {
        _new set [_forEachIndex * _factor, _x];
    } forEach _x;

    _allMagazines set [_forEachIndex, _new];
} forEach _allMagazines;

for "_i" from 0 to (_biggestArrayCount - 1) do {
    {
        if (_x select _i != "") then {
            _obj addItem (_x select _i);
        };
    } forEach _allMagazines;
};

// Switch to primary weapon
_obj selectWeapon (primaryWeapon _obj);

// Run onApplyLoadout code
_obj call compile getText (_loadout >> "onApplyLoadout");
