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

[_cfgLoadouts,_noMapCondition,_logFF,_allowKick]
