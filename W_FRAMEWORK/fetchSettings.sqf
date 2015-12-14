private _cfgLoadouts = false;
#ifdef CFGLOADOUTS
	_cfgLoadouts = true;
#endif

private _noMapCondition = {false};
#ifdef NOMAPCONDITION
	_noMapCondition = {NOMAPCONDITION};
#endif

private _logFF = false;
#ifdef LOGFF
	_logFF = true;
#endif

private _allowKick = true;
#ifdef NOKICK
	_allowKick = false;
#endif

private _noHC = false;
#ifdef NOHC
	_noHC = true;
#endif

[_cfgLoadouts,_noMapCondition,_logFF,_allowKick,_noHC]
