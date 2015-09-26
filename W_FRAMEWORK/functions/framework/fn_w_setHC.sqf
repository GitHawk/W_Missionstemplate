params ["_setting"];
isHC = (_setting == 1 && local HC) || (_setting == 0 && isServer);
