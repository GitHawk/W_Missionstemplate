private "_cfgLoadouts";
_cfgLoadouts = false;
#ifdef CFGLOADOUTS
	_cfgLoadouts = true;
#endif

private "_noMapCondition";
_noMapCondition = {false};
#ifdef NOMAPCONDITION
	_noMapCondition = {NOMAPCONDITION};
#endif

private "_logFF";
_logFF = false;
#ifdef LOGFF
	_logFF = true;
#endif

[_cfgLoadouts,_noMapCondition,_logFF]
